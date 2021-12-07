// Copyright 2019-2021 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

/* System headers */
#include <platform.h>
#include <xs1.h>

/* FreeRTOS headers */
#include "FreeRTOS.h"
#include "queue.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_DHCP.h"

/* Library headers */
#include "fs_support.h"
#include "sntpd.h"
//#include "tls_support.h"

/* App headers */
#include "app_conf.h"
#include "platform/platform_init.h"
#include "platform/driver_instances.h"
#include "network_demos/network_setup.h"
//#include "thruput_test/thruput_test.h" //debugging header
//#include "mem_analysis/mem_analysis.h" //debugging header
#include "queue_to_tcp_stream/queue_to_tcp_stream.h"
#include "tcp_stream_to_queue/tcp_stream_to_queue.h"
#include "example_pipeline/example_pipeline.h"
#include "gpio_ctrl/gpio_ctrl.h"

void vApplicationMallocFailedHook( void )
{
    rtos_printf("Malloc Failed on tile %d!\n", THIS_XCORE_TILE);
    for(;;);
}

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
    rtos_printf("\nStack Overflow!!! %d %s!\n", THIS_XCORE_TILE, pcTaskName);
    configASSERT(0);
}

void startup_task(void *arg)
{
    rtos_printf("Startup task running from tile %d on core %d\n", THIS_XCORE_TILE, portGET_CORE_ID());

    platform_start();

#if ON_TILE(0)
    /* Initialize filesystem  */
    rtos_fatfs_init(qspi_flash_ctx);

    /* Initialize WiFi */
    wifi_start(appconfWIFI_SETUP_TASK_PRIORITY);

    /* Create intertile audio frame receiver */
    intertile_pipeline_to_tcp_create();
    /* Create intertile audio frame sender */
    tcp_to_intertile_pipeline_create();

    /* Initialize TLS  */
    //tls_platform_init();

    /* Create the thruput test */
    //thruput_test_create(appconfTHRUPUT_TEST_TASK_PRIORITY);

    /* Create SNTPD */
    //sntp_create(appconfSNTPD_TASK_PRIORITY);

    /* Create UDP CLI */
    //vStartUDPCommandInterpreterTask( portTASK_STACK_DEPTH( vUDPCommandInterpreterTask ), appconfCLI_UDP_PORT, appconfCLI_TASK_PRIORITY );
    //vInitializeUDPIntertile( appconfCLI_RPC_PROCESS_COMMAND_PORT );

    /* Create TLS echo demo */
	//tls_echo_demo_create( appconfTLS_ECHO_TASK_PRIORITY );

    /* Create TLS echo demo */
	//tls_echo_server_create( appconfTLS_ECHO_SERVER_PRIORITY );

    /* Create HTTP demo */
	//http_demo_create(appconfHTTP_TASK_PRIORITY);

    /* Create MQTT demo*/
    //mqtt_demo_create(appconfMQTT_TASK_PRIORITY);
#endif

#if ON_TILE(1)
    /* Create the gpio control task */
    gpio_ctrl_create(appconfGPIO_TASK_PRIORITY);

    /* Create audio pipeline */
    example_pipeline_init(appconfAUDIO_PIPELINE_TASK_PRIORITY);
    //remote_cli_gain_init(appconfCLI_RPC_PROCESS_COMMAND_TASK_PRIORITY);
#endif

	for (;;) {
		rtos_printf("Tile[%d]:\n\tMinimum heap free: %d\n\tCurrent heap free: %d\n", THIS_XCORE_TILE, xPortGetMinimumEverFreeHeapSize(), xPortGetFreeHeapSize());
		vTaskDelay(pdMS_TO_TICKS(5000));
	}
}

static void tile_common_init(chanend_t c)
{
    platform_init(c);
    chanend_free(c);

    xTaskCreate((TaskFunction_t) startup_task,
                "startup_task",
                configMINIMAL_STACK_SIZE * 10,
                NULL,
                appconfSTARTUP_TASK_PRIORITY,
                NULL);

    rtos_printf("start scheduler on tile %d\n", THIS_XCORE_TILE);
    vTaskStartScheduler();
}

#if ON_TILE(0)
void main_tile0(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3) {
    (void)c0;
    (void)c2;
    (void)c3;

    tile_common_init(c1);
}
#endif

#if ON_TILE(1)
void main_tile1(chanend_t c0, chanend_t c1, chanend_t c2, chanend_t c3) {
    (void)c1;
    (void)c2;
    (void)c3;

    tile_common_init(c0);
}
#endif
