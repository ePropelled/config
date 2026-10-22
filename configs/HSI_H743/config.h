/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#pragma once

/*
 * HSI flight controller target, based on the EP-PILOT hardware mapping.
 * Timer assignments and all power/control polarity must be verified on the
 * final PCB before further hardware testing.
 */

#define FC_TARGET_MCU     STM32H743
#define SYSTEM_HSE_MHZ    8

/* Ensure ADC3 is explicitly clocked/configured before H743 internal ADC use. */
#define USE_ADC3_DIRECT_HAL_INIT

#define BOARD_NAME        HSI_H743
#define MANUFACTURER_ID   HSI

/* Sensors */
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_BMP581
#define DEFAULT_BARO_BMP581
#define DEFAULT_BARO_I2C_ADDRESS 70 /* BMP581 address 0x46 */
#define USE_MAG
#define USE_MAG_LIS2MDL

/* USB and debug */
#define USB_DP_PIN         PA12
#define USB_DM_PIN         PA11
#define USB_DETECT_PIN     PC5
#define SWDIO_PIN          PA13
#define SWCLK_PIN          PA14

/* UARTs: EP-PILOT USART/UART pin mapping */
#define UART1_RX_PIN       PA10
#define UART1_TX_PIN       PA9
#define UART2_TX_PIN       PA2
#define UART2_RX_PIN       PA3
#define UART3_RX_PIN       PD9
#define UART3_TX_PIN       PD8
#define UART4_TX_PIN       PA0
#define UART4_RX_PIN       PA1
#define UART5_RX_PIN       PB5
#define UART5_TX_PIN       PB6
#define UART6_RX_PIN       PC7
#define UART6_TX_PIN       PC6
#define UART7_RX_PIN       PE7

/* I2C1/I2C2: external bus, BMP581, and magnetometer */
#define I2C1_SCL_PIN       PB8
#define I2C1_SDA_PIN       PB9
#define I2C2_SCL_PIN       PB10
#define I2C2_SDA_PIN       PB11
#define BARO_I2C_INSTANCE  I2CDEV_2
#define MAG_I2C_INSTANCE   I2CDEV_2
#define MAG_DATA_READY_PIN PB13

/* BMI270: SPI3 bus */
#define SPI3_SCK_PIN        PB3
#define SPI3_SDI_PIN        PB4
#define SPI3_SDO_PIN        PD6
#define GYRO_1_SPI_INSTANCE SPI3
#define GYRO_1_EXTI_PIN     PE1
#define ACCEL_1_EXTI_PIN    PB7
#define GYRO_1_CS_PIN       PA15

/* BMI088 wiring reserved for future driver support. */
#define SPI2_SCK_PIN       PD3
#define SPI2_SDI_PIN       PC2
#define SPI2_SDO_PIN       PC3
#define GYRO_2_SPI_INSTANCE SPI2
#define ACCEL_2_CS_PIN     PD4
#define GYRO_2_CS_PIN      PD5
#define ACCEL_2_EXTI_PIN   PC14
#define GYRO_2_EXTI_PIN    PC15

/* Auxiliary SPI connector */
#define SPI1_SCK_PIN       PA5
#define SPI1_SDI_PIN       PA6
#define SPI1_SDO_PIN       PA7
#define SPI1_CS_PIN        PB12
#define SPI1_DRDY1_PIN     PE0

/* SD card */
#define USE_SDCARD
#define SDIO_CK_PIN        PC12
#define SDIO_CMD_PIN       PD2
#define SDIO_D0_PIN        PC8
#define SDIO_D1_PIN        PC9
#define SDIO_D2_PIN        PC10
#define SDIO_D3_PIN        PC11
#define SDIO_USE_4BIT      1
#define SDIO_DEVICE        SDIODEV_1
#define USE_SDCARD_SDIO
#define VDD_3V3_SD_CARD_EN PC13

/* ADC inputs in EP-PILOT order */
#define ADC_EXTERNAL1_PIN  PA4
#define ADC_EXTERNAL2_PIN  PC4
#define ADC_VBAT_PIN       PC0
#define ADC_CURR_PIN       PC1
#define ADC1_DMA_OPT       0
#define ADC3_DMA_OPT       10 /* ADC3 DMA2 stream/request mapping for STM32H743 */

/* CAN1 */
#define CAN1_RX_PIN        PD0
#define CAN1_TX_PIN        PD1

/* Board controls and indicators */
#define BUZZER_PIN           PD15
#define LED_STRIP_PIN        PD14
#define USE_HSI_RGB_STATUS
#define HEARTBEAT_LED_PIN    PE10
#define HEATER_PIN           PE8
#define ARMED_PIN            PB2
#define VDD_3V3_EXT_EN       PA8
#define POWER_GOOD_12V_PIN   PD10
#define POWER_GOOD_5V_PIN    PE12
#define POWER_GOOD_EXT5V_PIN PE15
#define LED0_PIN             PE4 /* RGB blue */
#define LED1_PIN             PE2 /* RGB green */
#define LED2_PIN             PE3 /* RGB red; LED2 renders amber with green */
#define LED0_OPEN_DRAIN
#define LED1_OPEN_DRAIN
#define LED2_OPEN_DRAIN
/* PE10 is a separate heartbeat signal and is not currently driven by Betaflight. */

/* Motor outputs from the EP-PILOT pinout. */
#define MOTOR1_PIN         PE14
#define MOTOR2_PIN         PE13
#define MOTOR3_PIN         PE11
#define MOTOR4_PIN         PE9
#define MOTOR5_PIN         PB1
#define MOTOR6_PIN         PB0
#define MOTOR7_PIN         PD12
#define MOTOR8_PIN         PD13
#define MOTOR9_PIN         PE5
#define MOTOR10_PIN        PE6

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN, 1, 3) \
    TIMER_PIN_MAP(1, MOTOR2_PIN, 1, 2) \
    TIMER_PIN_MAP(2, MOTOR3_PIN, 1, 1) \
    TIMER_PIN_MAP(3, MOTOR4_PIN, 1, 0) \
    TIMER_PIN_MAP(4, MOTOR5_PIN, 2, 5) \
    TIMER_PIN_MAP(5, MOTOR6_PIN, 2, 4) \
    TIMER_PIN_MAP(6, MOTOR7_PIN, 1, 6) \
    TIMER_PIN_MAP(7, MOTOR8_PIN, 1, 7) \
    TIMER_PIN_MAP(8, MOTOR9_PIN, 1, -1) \
    TIMER_PIN_MAP(9, MOTOR10_PIN, 1, -1) \
    TIMER_PIN_MAP(10, LED_STRIP_PIN, 1, 12)

#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD
