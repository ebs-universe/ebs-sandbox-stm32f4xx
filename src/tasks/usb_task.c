

#include <application.h>
#include <tusb.h>
#include "usb_task.h"
#include <hal/uc/usb.h>
#include <hal/uc/usbcdc.h>

uint8_t message[] = "abcdefghijklmnopqrstuvwxyz"; 
uint8_t connected = 0;
uint8_t usb_read_buf[64];

static void cdc_read_task(void)
{
  if ( usbcdc_population_rxb(0) )
  {
    usbcdc_read(0, usb_read_buf, 64);
    connected = 0x01;
    return;
  }
}

static void cdc_write_task(void) {
  uint8_t havelock = 0;
  if (connected && usb_status == USB_ST_ACTIVE) {
      havelock = usbcdc_reqlock(0, 30, 0);
      if (havelock){
          usbcdc_write(0, message, sizeof(message), 0x00);
      }
    }
}


void usb_task(void){
  #if APP_ENABLE_USB
    #if APP_ENABLE_USB_DEVICE
      tud_task();
      cdc_read_task();
      cdc_write_task();
    #endif
    #if APP_ENABLE_USB_HOST
      tuh_task();
    #endif
  #endif
}
