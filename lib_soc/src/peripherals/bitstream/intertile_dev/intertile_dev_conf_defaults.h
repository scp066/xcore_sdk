// Copyright (c) 2020, XMOS Ltd, All rights reserved

#ifndef INTERTILE_DEV_CONF_DEFAULTS_H_
#define INTERTILE_DEV_CONF_DEFAULTS_H_

#define INTERTILE_DEV_MAX_HANDLER_COUNT     (8)

#ifndef INTERTILE_DEV_HANDLER_COUNT
#define INTERTILE_DEV_HANDLER_COUNT         (INTERTILE_DEV_MAX_HANDLER_COUNT)
#endif

#ifndef INTERTILE_DEV_BUFSIZE
#define INTERTILE_DEV_BUFSIZE               (4096)
#endif

#if( INTERTILE_DEV_HANDLER_COUNT > INTERTILE_DEV_MAX_HANDLER_COUNT )
#error INTERTILE_DEV_HANDLER_COUNT must be smaller than INTERTILE_DEV_MAX_HANDLER_COUNT
#endif

#endif /* INTERTILE_DEV_CONF_DEFAULTS_H_ */
