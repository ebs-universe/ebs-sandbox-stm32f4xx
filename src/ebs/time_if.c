

#include <hal/uc.h>
#include <stdint.h>
#include "time_if.h"


uint16_t time_init(void) {
    uint16_t ucdm_address = DMAP_TIME_BASE_ADDRESS;
    ucdm_address = tm_init(ucdm_address);
    #if APP_ENABLE_CRON == 1
    tm_cron_init();
    #endif
    #if APP_ENABLE_TIMESYNC == 1
    ucdm_address = tm_sync_init(ucdm_address);
    #endif
    return ucdm_address;
}

uint32_t HAL_GetTick(void)
{
    tm_system_t current;
    tm_current_time(&current);
    return current.seconds * 1000 + current.frac;
}
