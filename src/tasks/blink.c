

#include "blink.h"
#include <hal/uc.h>


cron_job_t blink_job;
tm_system_t blink_start;
tm_sdelta_t blink_period = {100,0,0};


void blink(void) {
    gpio_set_output_toggle(BLINK_GPIO);  
}

void set_blink_period(uint16_t sec, uint16_t frac){
    blink_period.seconds = sec;
    blink_period.frac = frac;
}

void start_blink_task(void) {
    tm_current_time(&blink_start);
    tm_cron_create_job_abs(&blink_job, &blink, &blink_start, &blink_period);
}
