

#include "iomap.h"
#include <hal/uc/gpio.h>


static void gpio_init_board_leds(void){
    gpio_set_output_high(GPIO_LED1);
    gpio_set_output_high(GPIO_LED2);
    gpio_conf_output(GPIO_LED1);
    gpio_conf_output(GPIO_LED2);
    gpio_conf_outmode_pp(GPIO_LED1);
    gpio_conf_outmode_pp(GPIO_LED2);
    gpio_conf_speed(GPIO_LED1, GPIO_SPEED_FREQ_LOW);
    gpio_conf_speed(GPIO_LED2, GPIO_SPEED_FREQ_LOW);    
}

static void gpio_init_board_buttons(void){
    gpio_conf_input(GPIO_K0);
    gpio_conf_pullup(GPIO_K0);
    gpio_conf_interrupt(GPIO_K0, GPIO_INT_EDGE_FALLING);

    gpio_conf_input(GPIO_K1);
    gpio_conf_pullup(GPIO_K1);
    gpio_conf_interrupt(GPIO_K1, GPIO_INT_EDGE_FALLING);
}

static void gpio_init_nrf_port(void){
    gpio_set_output_high(GPIO_NRF_CS);
    gpio_conf_output(GPIO_NRF_CS);
    gpio_conf_outmode_pp(GPIO_NRF_CS);
    gpio_conf_speed(GPIO_NRF_CS, GPIO_SPEED_FREQ_LOW);
    
    gpio_set_output_low(GPIO_NRF_CE);
    gpio_conf_output(GPIO_NRF_CE);
    gpio_conf_outmode_pp(GPIO_NRF_CE);
    gpio_conf_speed(GPIO_NRF_CE, GPIO_SPEED_FREQ_LOW);

    gpio_conf_input(GPIO_NRF_IRQ);
    gpio_conf_hiz(GPIO_NRF_IRQ);
    gpio_conf_interrupt(GPIO_NRF_IRQ, GPIO_INT_EDGE_FALLING);
}

static void gpio_init_board_flash(void){
    gpio_set_output_high(GPIO_F_CS);
    gpio_conf_output(GPIO_F_CS);
    gpio_conf_outmode_pp(GPIO_F_CS);
    gpio_conf_speed(GPIO_F_CS, GPIO_SPEED_FREQ_LOW);
}

static void gpio_init_app_outputs(void){
    gpio_set_output_low(GPIO_DOUT0);
    gpio_conf_output(GPIO_DOUT0);
    gpio_conf_outmode_pp(GPIO_DOUT0);
    gpio_conf_speed(GPIO_DOUT0, GPIO_SPEED_FREQ_LOW);

    gpio_set_output_low(GPIO_DOUT1);
    gpio_conf_output(GPIO_DOUT1);
    gpio_conf_outmode_pp(GPIO_DOUT1);
    gpio_conf_speed(GPIO_DOUT1, GPIO_SPEED_FREQ_LOW);

    gpio_set_output_low(GPIO_DOUT2);
    gpio_conf_output(GPIO_DOUT2);
    gpio_conf_outmode_pp(GPIO_DOUT2);
    gpio_conf_speed(GPIO_DOUT2, GPIO_SPEED_FREQ_LOW);

    gpio_set_output_low(GPIO_DOUT3);
    gpio_conf_output(GPIO_DOUT3);
    gpio_conf_outmode_pp(GPIO_DOUT3);
    gpio_conf_speed(GPIO_DOUT3, GPIO_SPEED_FREQ_LOW);
}

static void gpio_init_app_inputs(void){
    gpio_conf_input(GPIO_DIN0);
    gpio_conf_hiz(GPIO_DIN0);
    gpio_conf_interrupt(GPIO_DIN0, GPIO_INT_EDGE_RISING);

    gpio_conf_input(GPIO_DIN1);
    gpio_conf_hiz(GPIO_DIN1);
    gpio_conf_interrupt(GPIO_DIN1, GPIO_INT_EDGE_RISING);

    gpio_conf_input(GPIO_DIN2);
    gpio_conf_hiz(GPIO_DIN2);
    gpio_conf_interrupt(GPIO_DIN2, GPIO_INT_EDGE_RISING);

    gpio_conf_input(GPIO_DIN3);
    gpio_conf_hiz(GPIO_DIN3);
    gpio_conf_interrupt(GPIO_DIN3, GPIO_INT_EDGE_RISING);
}

void gpio_arm_nrf_interrupt(void){
    gpio_interrupt_arm(GPIO_NRF_IRQ);
}

void gpio_disarm_nrf_interrupt(void){
    gpio_interrupt_disarm(GPIO_NRF_IRQ);
}

void gpio_arm_button_interrupts(void){
    gpio_interrupt_arm(GPIO_K0);
    gpio_interrupt_arm(GPIO_K1);
}

void gpio_disarm_button_interrupts(void){
    gpio_interrupt_disarm(GPIO_K0);
    gpio_interrupt_disarm(GPIO_K1);
}

void gpio_arm_din_interrupts(void){
    gpio_interrupt_arm(GPIO_DIN0);
    gpio_interrupt_arm(GPIO_DIN1);
    gpio_interrupt_arm(GPIO_DIN2);
    gpio_interrupt_arm(GPIO_DIN3);
}

void gpio_disarm_din_interrupts(void){
    gpio_interrupt_disarm(GPIO_DIN0);
    gpio_interrupt_disarm(GPIO_DIN1);
    gpio_interrupt_disarm(GPIO_DIN2);
    gpio_interrupt_disarm(GPIO_DIN3);
}

void application_gpio_init (void){
    gpio_init();
    gpio_init_board_leds();
    gpio_init_board_buttons();
    gpio_init_board_flash();
    gpio_init_nrf_port();
    gpio_init_app_outputs();
    gpio_init_app_inputs();
}
