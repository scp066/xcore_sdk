// Copyright 2020-2021 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#ifndef SRC_EXAMPLE_PIPELINE_H_
#define SRC_EXAMPLE_PIPELINE_H_

#include "rtos/drivers/mic_array/api/rtos_mic_array.h"
#include "rtos/drivers/i2s/api/rtos_i2s.h"

enum {
    GET_GAIN_VAL = 1,
    SET_GAIN_VAL
};

void example_pipeline_init( UBaseType_t priority );

void intertile_pipeline_to_tcp_create( void );

void example_pipeline_init( UBaseType_t priority );

void tcp_to_pipeline_intertile_create( void );


void remote_cli_gain_init( UBaseType_t priority );

BaseType_t audiopipeline_get_stage1_gain( void );
BaseType_t audiopipeline_set_stage1_gain( BaseType_t xNewGain );

#endif /* SRC_EXAMPLE_PIPELINE_H_ */
