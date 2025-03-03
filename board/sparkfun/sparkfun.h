// Pin definitions for the Berkeley Buckler revision B

#pragma once

#include "nrf_gpio.h"
#include "nrf_saadc.h"


// TODO: Define SPI pins 




// Analog accelerometer
#define BUCKLER_ANALOG_ACCEL_X NRF_SAADC_INPUT_AIN5 // P0.29
#define BUCKLER_ANALOG_ACCEL_Y NRF_SAADC_INPUT_AIN6 // P0.30
#define BUCKLER_ANALOG_ACCEL_Z NRF_SAADC_INPUT_AIN7 // P0.31

// Buttons and Switches
#define BUCKLER_BUTTON0 NRF_GPIO_PIN_MAP(0,28)
#define BUCKLER_SWITCH0 NRF_GPIO_PIN_MAP(0,22)

// Grove Headers
#define BUCKLER_GROVE_A0 NRF_GPIO_PIN_MAP(0,4)
#define BUCKLER_GROVE_A1 NRF_GPIO_PIN_MAP(0,3)
#define BUCKLER_GROVE_D0 NRF_GPIO_PIN_MAP(0,2)
#define BUCKLER_GROVE_D1 NRF_GPIO_PIN_MAP(0,5)

// I2C sensors
#define BUCKLER_SENSORS_SCL     NRF_GPIO_PIN_MAP(0,19)
#define BUCKLER_SENSORS_SDA     NRF_GPIO_PIN_MAP(0,20)
#define BUCKLER_IMU_INTERUPT    NRF_GPIO_PIN_MAP(0,7)
#define BUCKLER_LIGHT_INTERRUPT NRF_GPIO_PIN_MAP(0,27)

// LCD screen
#define BUCKLER_LCD_SCLK NRF_GPIO_PIN_MAP(0,17)
#define BUCKLER_LCD_MISO NRF_GPIO_PIN_MAP(0,16)
#define BUCKLER_LCD_MOSI NRF_GPIO_PIN_MAP(0,15)
#define BUCKLER_LCD_CS   NRF_GPIO_PIN_MAP(0,18)

// LEDs
#define BUCKLER_LED0 NRF_GPIO_PIN_MAP(0,25)
#define BUCKLER_LED1 NRF_GPIO_PIN_MAP(0,24)
#define BUCKLER_LED2 NRF_GPIO_PIN_MAP(0,23)

// SD Card
#define BUCKLER_SD_ENABLE NRF_GPIO_PIN_MAP(0,26)
#define BUCKLER_SD_SCLK   NRF_GPIO_PIN_MAP(0,13)
#define BUCKLER_SD_MISO   NRF_GPIO_PIN_MAP(0,12)
#define BUCKLER_SD_MOSI   NRF_GPIO_PIN_MAP(0,11)
#define BUCKLER_SD_CS     NRF_GPIO_PIN_MAP(0,14)

// Re-define GPIOs for compatibility with simple_logger
#define SD_CARD_ENABLE      BUCKLER_SD_ENABLE
#define SD_CARD_SPI_CS      BUCKLER_SD_CS
#define SD_CARD_SPI_MISO    BUCKLER_SD_MISO
#define SD_CARD_SPI_MOSI    BUCKLER_SD_MOSI
#define SD_CARD_SPI_SCLK    BUCKLER_SD_SCLK

// Define which SPI to use
#define SD_CARD_SPI_INSTANCE    NRF_SPI1

// UART serial connection (to Kobuki)
#define BUCKLER_UART_RX NRF_GPIO_PIN_MAP(0,6)
#define BUCKLER_UART_TX NRF_GPIO_PIN_MAP(0,8)

// LED
#define SPARKFUN_LED NRF_GPIO_PIN_MAP(0,7)

// Buttons
#define SPARKFUN_RESET NRF_GPIO_PIN_MAP(0,21)
#define SPARKFUN_BUTTON NRF_GPIO_PIN_MAP(0,6)

// LoRa
#define SPI_SCLK   NRF_GPIO_PIN_MAP(0,15)
#define SPI_MISO   NRF_GPIO_PIN_MAP(0,14)
#define SPI_MOSI   NRF_GPIO_PIN_MAP(1,13)
#define RTC_CS     NRF_GPIO_PIN_MAP(0,12)
#define RTC_WDI    NRF_GPIO_PIN_MAP(0, 11)


