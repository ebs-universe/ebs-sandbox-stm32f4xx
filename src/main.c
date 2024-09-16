

#include <application.h>
#include <irq_handlers.h>
#include <iomap.h>

#include "bsp/gpio.h"
#include "bsp/usb.h"

#include "tasks/blink.h"
#include "tasks/usb_task.h"

#include "ebs/time_if.h"
#include <ucdm/ucdm.h>

#include <hal/uc.h>


static void setup_handlers(void) {
  __core_handler_inclusion = 1;
  __exti_handler_inclusion = 1;
  __shared_handler_inclusion = 1;
  __usb_handler_inclusion = 1;
}

void button_handler(uint8_t line);

void button_handler(uint8_t line) {
  gpio_set_output_toggle(GPIO_LED1);
}

void led_toggle(void) {
  gpio_set_output_toggle(GPIO_LED2);  
}


static void setup_core(void) {
  setup_handlers();
  core_init();
  ucdm_init();
  time_init();
  clock_set_default();
}


static void setup_peripherals(void) {
  application_gpio_init();
  
  #if APP_ENABLE_ID == 1 
    id_init();
  #endif
  #if APP_ENABLE_ENTROPY == 1 
    entropy_init();
  #endif
  #if APP_ENABLE_USB
    application_usb_init();
  #endif
  #if APP_ENABLE_EEPROM
    eeprom_init();
  #endif
  
  gpio_conf_interrupt_handler(GPIO_K0, &button_handler);
  gpio_conf_interrupt_handler(GPIO_K1, &button_handler);
  gpio_arm_button_interrupts();
}


int main(void) {
  setup_core();
  setup_peripherals();
  start_blink_task();
  while (1)
  {
    #if APP_ENABLE_CRON
    tm_cron_poll();
    #endif
    #if APP_ENABLE_USB
    usb_task();
    #endif
  }
}

