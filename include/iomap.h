


/**
 * @file iomap.h
 * @brief Application / Board Specific IO Map
 *
 * This file defines the various uC GPIOs used by the application.
 * This file was seeded by the cubeMX generated main.h, with the following changes: 
 *   - We switch all the GPIOx references with GPIOE_BASE, since we will be 
 *     writing our own GPIO handling code.
 *   - Rename, for example, LED_GPIO_Port to LED_PORT and LED_Pin to LED_PIN 
 *     to keep things consistent with the rest of EBS. 
 *   - Also add the optional GPIO_LED defines for convenience. 
 *   - We also change the Pin definitions from the masks to integers to maybe
 *     simplify the GPIO manipulation functions.
 * 
 * Note that not while all IO pins are specified in the cubeMX generated main.h, we add 
 * the other pins as well here to maintain a single source of truth. The missing GPIOs 
 * are the Analog pins and Alternate Function pins, which are initialized in the cubeMX
 * generated stm32f4xx_hal_msp.c. 
 * 
 */

#include "stm32f4xx_hal.h"

/**
 * @name GPIOs for User Buttons
 */
/**@{*/ 
#define K0_PIN              4   // GPIO_PIN_4  
#define K0_PORT             GPIOE_BASE
#define GPIO_K0             K0_PORT, K0_PIN 

#define K1_PIN              3   // GPIO_PIN_3 
#define K1_PORT             GPIOE_BASE
#define GPIO_K1             K1_PORT, K1_PIN 
/**@}*/ 

/**
 * @name GPIOs for User LEDs
 */
/**@{*/ 
#define LED1_PIN            6   // GPIO_PIN_6
#define LED1_PORT           GPIOA_BASE
#define GPIO_LED1           LED1_PORT, LED1_PIN 

#define LED2_PIN            7   // GPIO_PIN_7
#define LED2_PORT           GPIOA_BASE
#define GPIO_LED2           LED2_PORT, LED2_PIN 
/**@}*/ 

/**
 * @name GPIOs Associated with the NRF port on the F4VE
 */
/**@{*/ 
#define NRF_CE_PIN          6   // GPIO_PIN_6
#define NRF_CE_PORT         GPIOB_BASE
#define GPIO_NRF_CE         NRF_CE_PORT, NRF_CE_PIN 

#define NRF_CS_PIN          7   // GPIO_PIN_7
#define NRF_CS_PORT         GPIOB_BASE
#define GPIO_NRF_CS         NRF_CS_PORT, NRF_CS_PIN 

#define NRF_IRQ_PIN         8   // GPIO_PIN_8
#define NRF_IRQ_PORT        GPIOB_BASE
#define GPIO_NRF_IRQ        NRF_IRQ_PORT, NRF_IRQ_PIN 
#define NRF_IRQ_EXTI_IRQn   EXTI9_5_IRQn

/**@}*/ 

/**
 * @name GPIOs Associated with the on-board Flash on the F4VE
 */
/**@{*/ 
#define F_CS_PIN            0   // GPIO_PIN_0
#define F_CS_PORT           GPIOB_BASE
#define GPIO_F_CS           F_CS_PORT, F_CS_PIN 
/**@}*/ 

/**
 * @name GPIOs for Application Digital Outputs
 */
/**@{*/ 
#define DOUT0_PIN           3   // GPIO_PIN_3
#define DOUT0_PORT          GPIOD_BASE
#define GPIO_DOUT0          DOUT0_PORT, DOUT0_PIN 

#define DOUT1_PIN           6   // GPIO_PIN_6
#define DOUT1_PORT          GPIOD_BASE
#define GPIO_DOUT1          DOUT1_PORT, DOUT1_PIN 

#define DOUT2_PIN           11  // GPIO_PIN_11
#define DOUT2_PORT          GPIOD_BASE
#define GPIO_DOUT2          DOUT2_PORT, DOUT2_PIN 

#define DOUT3_PIN           12  // GPIO_PIN_12
#define DOUT3_PORT          GPIOD_BASE
#define GPIO_DOUT3          DOUT3_PORT, DOUT3_PIN 
/**@}*/ 

/**
 * @name GPIOs for Application Digital Inputs with Interrupts
 */
/**@{*/ 
#define DIN0_PIN            0   // GPIO_PIN_0
#define DIN0_PORT           GPIOE_BASE
#define GPIO_DIN0           DIN0_PORT, DIN0_PIN
#define DIN0_EXTI_IRQn      EXTI0_IRQn

#define DIN1_PIN            1   // GPIO_PIN_1
#define DIN1_PORT           GPIOE_BASE
#define GPIO_DIN1           DIN1_PORT, DIN1_PIN
#define DIN1_EXTI_IRQn      EXTI1_IRQn

#define DIN2_PIN            2   // GPIO_PIN_2
#define DIN2_PORT           GPIOE_BASE
#define GPIO_DIN2           DIN2_PORT, DIN2_PIN
#define DIN2_EXTI_IRQn      EXTI2_IRQn

#define DIN3_PIN            5   // GPIO_PIN_5
#define DIN3_PORT           GPIOE_BASE
#define GPIO_DIN3           DIN3_PORT, DIN3_PIN
#define DIN3_EXTI_IRQn      EXTI9_5_IRQn
/**@}*/ 

/**
 * @name USB FS GPIOs
 */
/**@{*/ 
#define USBFS_DP_PIN        12   // GPIO_PIN_12
#define USBFS_DP_PORT       GPIOA_BASE
#define USBFS_DP            USBFS_DP_PORT, USBFS_DP_PIN
#define USBFS_DP_AF         GPIO_AF10_OTG_FS

#define USBFS_DM_PIN        11   // GPIO_PIN_11
#define USBFS_DM_PORT       GPIOA_BASE
#define USBFS_DM            USBFS_DM_PORT, USBFS_DM_PIN
#define USBFS_DM_AF         GPIO_AF10_OTG_FS 
/**@}*/ 