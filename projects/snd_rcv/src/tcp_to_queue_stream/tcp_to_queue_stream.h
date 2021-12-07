// Copyright 2019-2021 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#ifndef TCP_TO_QUEUE_STREAM_H_
#define TCP_TO_QUEUE_STREAM_H_

#include "FreeRTOS_Sockets.h"

typedef struct tcp_to_queue_ctx
{
	QueueHandle_t queue;
	TickType_t rx_timeout;
	TickType_t tx_timeout;
	BaseType_t connected;
	size_t data_length;
	Socket_t socket;
	uint16_t port;
} tcp_to_queue_ctx_t;

typedef struct tcp_to_queue_ctx * tcp_to_queue_handle_t;

tcp_to_queue_handle_t tcp_to_queue_create( QueueHandle_t queue, uint16_t port, TickType_t rx_timeout,  TickType_t tx_timeout, size_t data_length );
BaseType_t tcp2queue_connected( tcp_to_queue_handle_t handle );
void tcp_to_queue_stream_create( tcp_to_queue_handle_t handle, UBaseType_t priority );

#endif /* QUEUE_TO_TCP_STREAM_H_ */
