
#include <main.h>
#include <time/cron.h>
#include <bsp/usb.h>

#ifdef APP_ENABLE_BLINK
#include <blink.h>
#endif

#include <test-serial/serial_test.h>


int main(void) {
    setup_system(1);
    
    #ifdef APP_ENABLE_BLINK
    start_blink_task();
    #endif

    while (1)
    {
        #if APP_ENABLE_TIME_CRON
        tm_cron_poll();
        #endif

        #if APP_ENABLE_USB
        tusb_task();
        #endif

        test_serial_loophandler();
    }
}

