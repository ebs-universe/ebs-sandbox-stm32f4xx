

#include <time/cron.h>
#include <iomap.h>

#define BLINK_GPIO  GPIO_LED2

void start_blink_task(void);
void set_blink_period(uint16_t sec, uint16_t frac);
