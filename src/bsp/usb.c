

#include "usb.h"

#include <stddef.h>
#include <hal/uc/usb.h>
#include <hal/uc/usbcdc.h>

#if BLINK_FOR_USB_STATUS
#include <tasks/blink.h>
#endif

#define BLINK_PERIOD_MOUNTED        0, 500
#define BLINK_PERIOD_NOT_MOUNTED    0, 100
#define BLINK_PERIOD_SUSPENDED      1, 0


void tud_mount_cb(void) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_MOUNTED);
    #endif
    usb_status = USB_ST_ACTIVE;
}

void tud_umount_cb(void) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_NOT_MOUNTED);
    #endif
    usb_status = USB_ST_DISCONNECTED;
}

void tud_suspend_cb(bool remote_wakeup_en) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_SUSPENDED);
    #endif
    usb_status = USB_ST_SUSPENDED;
}

void tud_resume_cb(void) {
    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_MOUNTED);
    #endif
    usb_status = USB_ST_ACTIVE;
}

void application_usb_init(void) {
    usb_init();
    tud_init(BOARD_TUD_RHPORT);

    #if uC_USBCDC_IF0
    usbcdc_init(0);
    #endif
    #if uC_USBCDC_IF1
    usbcdc_init(1);
    #endif
    #if uC_USBCDC_IF2
    usbcdc_init(2);
    #endif

    #if BLINK_FOR_USB_STATUS
    set_blink_period(BLINK_PERIOD_NOT_MOUNTED);
    #endif
}