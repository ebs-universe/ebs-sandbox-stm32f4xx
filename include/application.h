

#ifndef APPLICATION_H
#define APPLICATION_H

#include <hal/constants/all.h>

// Also see the following files generated by SMT32CubeMX : 
//   include/stm32f4xx_hal_conf.h

/**
 * @name Application Descriptors Configuration
 * 
 * Various descriptrs used to identify the application. For USB enumeration, 
 * the following descriptors must be minimally specified : 
 * 
 *  - APP_DESCRIPTOR_VENDOR_NAME : USB Device Manufacturer
 *  - APP_DESCRIPTOR_HARDWARE_NAME : USB Product Name
 * 
 */
/**@{*/   

#define APP_DESCRIPTOR_VENDOR_NAME          "EBS Development"
#define APP_DESCRIPTOR_VENDOR_URL           "https://github.com/ebs-universe"

#define APP_DESCRIPTOR_HARDWARE_NAME        "Black STM32F4VE DevEBox"
#define APP_DESCRIPTOR_HARDWARE_REVISION    "2021Z"
#define APP_DESCRIPTOR_HARDWARE_VARIANT     ""    

#define APP_DESCRIPTOR_FIRMWARE_NAME        "EBS Platform Development Stack"
#define APP_DESCRIPTOR_FIRMWARE_REVISION    "9.9.9"

#define APP_UCDM_MAX_REGISTERS              255
#define APP_ENABLE_LIBVERSION_DESCRIPTORS   1

/**
 * @name Application GPIO Configuration
 */
/**@{*/   
    #define APP_ENABLE_GPIO            1
/**@}*/ 


/**
 * @name Application Systick and Time Configuration
 */
/**@{*/   
    #define APP_ENABLE_SYSTICK         1
    #define APP_USE_CORE_SYSTICK       1
    #define APP_ENABLE_TIME_CRON       1
    #define APP_ENABLE_TIME_SYNC       1
    #define APP_ENABLE_RTC             0
    #define APP_ENABLE_RTC_1HZ_OUT     0
/**@}*/ 

/**
 * @name Application Device ID Configuration
 */
/**@{*/   
    #define APP_ENABLE_ID       1
    #define APP_ID_TRIMFUNC     1
/**@}*/ 

/**
 * @name Application EEPROM Configuration
 */
/**@{*/   
    #define APP_ENABLE_EEPROM         1
    #define APP_EEPROM_PROVIDER       2
    #define APP_EEPROM_SIZE           1024
    #define APP_EEPROM_SIZETYPE       uint16_t
/**@}*/ 

/**
 * @name Application Entropy Configuration
 */
/**@{*/   
    #define APP_ENABLE_RAND                 1
    #define APP_ENABLE_ENTROPY              APP_ENABLE_RAND
    #define APP_ENTROPY_POOL_SIZE           16
    #define APP_ENTROPY_MODE                2
/**@}*/ 

/**
 * @name Application USB Configuration
 */
/**@{*/    
    #define APP_ENABLE_USB_HOST             0   // Not implemented.
    #define APP_ENABLE_USB_DEVICE           1
    #define APP_ENABLE_USB                  (APP_ENABLE_USB_DEVICE | APP_ENABLE_USB_HOST)
    #define APP_USB_DEVICE_RHPORT           0
    #define APP_USB_POWER                   400
    #define APP_USB_DESCR_VID               1155
    #define APP_USB_DESCR_PID               22336
    #define APP_USB_DESCR_VERSION           0x0100
    #define APP_BLINK_FOR_USB_STATUS        1

    // STM32 F4 USB FS peripheral has enough endpoints for only one USBCDC
    #define APP_ENABLE_USBCDC0              1
    #define APP_ENABLE_USBCDC1              0
    #define APP_ENABLE_USBCDC2              0
    #define APP_USBCDC_IFACES               (APP_ENABLE_USBCDC0 + APP_ENABLE_USBCDC1 + APP_ENABLE_USBCDC2)
    
    #define APP_ENABLE_USBCDC0_PT           0
    #define APP_ENABLE_USBCDC1_PT           0
    #define APP_ENABLE_USBCDC2_PT           0

    #if APP_USBCDC_IFACES >= 3
    #define APP_USB_DESCR_IF_CDC0           "Control Interface"
    #define APP_USB_DESCR_IF_CDC1           "Bulk Interface"
    #define APP_USB_DESCR_IF_CDC2           "Backchannel Interface"
    #elif APP_USBCDC_IFACES == 2
    #define APP_USB_DESCR_IF_CDC0           "Primary Interface"
    #define APP_USB_DESCR_IF_CDC1           "Backchannel Interface"
    #else 
    #define APP_USB_DESCR_IF_CDC0           "Primary Interface"
    #endif
/**@}*/ 

/**
 * @name Application Primary Interface Configuration
 */
/**@{*/   
    #define APP_ENABLE_PRIF             1
    #define APP_PRIF_TYPE               1
    #define APP_PRIF_INTFNUM            0
/**@}*/ 

/**
 * @name Application Backchannel Interface Configuration
 */
/**@{*/   
    #define APP_ENABLE_BCIF             0
    #define APP_BCIF_TYPE               0
    #define APP_BCIF_INTFNUM            0
/**@}*/ 

/**
 * @name Application Common Infrastructure Configuration
 */
/**@{*/   
    #define APP_ENABLE_BLINK                 1
/**@}*/

/**
 * @name Application Modbus Configuration
 */
/**@{*/   
    #define APP_ENABLE_MODBUS                1
    
    #if APP_ENABLE_PRIF
        #define MODBUS_TRANSPORT_INTFNUM     APP_PRIF_INTFNUM
        #define MODBUS_TRANSPORT_TYPE        APP_PRIF_TYPE
    #elif APP_ENABLE_BCIF
        #define MODBUS_TRANSPORT_INTFNUM     APP_BCIF_INTFNUM
        #define MODBUS_TRANSPORT_TYPE        APP_BCIF_TYPE
    #endif

    #define MODBUS_PLUGGABLE_TRANSPORTS      0
    #define MODBUS_DEFAULT_DEVICE_ADDRESS    0x05
/**@}*/

/**
 * @name Application Testing Configuration
 */
/**@{*/   
    #ifndef TEST_SERIAL_INTFNUM
        #if APP_ENABLE_PRIF
        #define TEST_SERIAL_INTFNUM           APP_PRIF_INTFNUM
        #define TEST_SERIAL_TYPE              APP_PRIF_TYPE
        #elif APP_ENABLE_BCIF
        #define TEST_SERIAL_INTFNUM           APP_BCIF_INTFNUM
        #define TEST_SERIAL_TYPE              APP_BCIF_TYPE
        #endif
    #endif
    #ifndef TEST_SERIAL_TYPE
    #define TEST_SERIAL_TYPE                  0
    #endif
/**@}*/ 

#endif