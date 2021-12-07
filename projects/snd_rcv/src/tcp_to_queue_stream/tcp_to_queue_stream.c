// Copyright 2019-2021 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#define DEBUG_UNIT QUEUE_TO_TCP
/* FreeRTOS headers */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* FreeRTOS Plus headers */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"

/* App headers */
#include "app_conf.h"
#include "tcp_to_queue_stream/tcp_to_queue_stream.h"

static void tcp_to_queue_recv(void *arg)
{
    
	tcp_to_queue_handle_t handle = ( tcp_to_queue_handle_t ) arg;
    Socket_t xConnectedSocket = handle->socket;
    size_t data_length = handle->data_length;
    BaseType_t xRecv = 0;

    int32_t *data = NULL;
  for (;;) {

        xRecv = FreeRTOS_recv( xConnectedSocket,
							   data,
							   data_length,
							   0);
        
        xQueueSend( handle->queue, &data, portMAX_DELAY );


		if( xRecv != data_length)
		{
			handle->connected = pdFALSE;

			FreeRTOS_shutdown( xConnectedSocket, FREERTOS_SHUT_RDWR );

			char dummy;
			while( FreeRTOS_recv( xConnectedSocket, &dummy, 1, 0 ) >= 0 )
			{
				vTaskDelay(pdMS_TO_TICKS( 100 ));
			}

			configASSERT( FreeRTOS_issocketconnected( xConnectedSocket ) == pdFALSE );
			FreeRTOS_closesocket( xConnectedSocket );

			debug_printf("Connection closed\n");
			debug_printf("Heap free: %d\n", xPortGetFreeHeapSize());
			debug_printf("Minimum heap free: %d\n", xPortGetMinimumEverFreeHeapSize());

			vPortFree(data);

			vTaskDelete( NULL );
		}

		vPortFree(data);
    }
    
}

static void tcp2queue( void *arg )
{
	tcp_to_queue_handle_t handle = ( tcp_to_queue_handle_t ) arg;

    struct freertos_sockaddr xClient, xBindAddress;
    Socket_t xListeningSocket, xConnectedSocket;
    socklen_t xSize = sizeof( xClient );
    const TickType_t xReceiveTimeOut = handle->rx_timeout;
    const TickType_t xSendTimeOut = handle->tx_timeout;
    const BaseType_t xBacklog = 1;

    while( FreeRTOS_IsNetworkUp() == pdFALSE )
    {
        vTaskDelay(pdMS_TO_TICKS( 100 ));
    }

    /* Attempt to open the socket. */
    xListeningSocket = FreeRTOS_socket( FREERTOS_AF_INET,
										FREERTOS_SOCK_STREAM,
										FREERTOS_IPPROTO_TCP );

    /* Check the socket was created. */
    configASSERT( xListeningSocket != FREERTOS_INVALID_SOCKET );

    /* Set a time out so accept() will just wait for a connection. */
    FreeRTOS_setsockopt( xListeningSocket,
                         0,
                         FREERTOS_SO_RCVTIMEO,
                         &xReceiveTimeOut,
                         sizeof( xReceiveTimeOut ) );

    /* Set the listening port */
    xBindAddress.sin_port = FreeRTOS_htons( handle->port );

    /* Bind the socket to the port that the client RTOS task will send to. */
    FreeRTOS_bind( xListeningSocket, &xBindAddress, sizeof( xBindAddress ) );

    /* Set the socket into a listening state so it can accept connections.
    The maximum number of simultaneous connections is limited to 20. */
    FreeRTOS_listen( xListeningSocket, xBacklog );

    for( ;; )
    {
        /* Wait for incoming connections. */
        xConnectedSocket = FreeRTOS_accept( xListeningSocket, &xClient, &xSize );

        configASSERT( xConnectedSocket != FREERTOS_INVALID_SOCKET );

        FreeRTOS_setsockopt( xConnectedSocket,
                             0,
                             FREERTOS_SO_SNDTIMEO,
                             &xSendTimeOut,
                             sizeof( xSendTimeOut ) );

        handle->socket = xConnectedSocket;
        handle->connected = pdTRUE;
        xTaskCreate( tcp_to_queue_recv, "tcp2queue_recv", portTASK_STACK_DEPTH( tcp_to_queue_recv ), ( void * ) handle, uxTaskPriorityGet( NULL ), NULL );
    }
}

void tcp_to_queue_stream_create( tcp_to_queue_handle_t handle, UBaseType_t priority )
{
    xTaskCreate( tcp2queue, "tcp2queue", portTASK_STACK_DEPTH( tcp2queue ), ( void * ) handle, priority, NULL );
}
