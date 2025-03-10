// Blink app
//
// Blinks the LED on SPARKFUN

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <nrf_drv_spi.h>

#include "app_error.h"
#include "nrf.h"
#include "nrf_delay.h"
#include "nrfx_gpiote.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_serial.h"

#include "sparkfun.h"

// LED array
static uint8_t LED = SPARKFUN_LED;

int main(void) {

  // initialize RTT library
  ret_code_t error_code = NRF_SUCCESS;
  error_code = NRF_LOG_INIT(NULL);
  APP_ERROR_CHECK(error_code);
  NRF_LOG_DEFAULT_BACKENDS_INIT();
  printf("Log initialized!\n");

  // initialize GPIO driver
  if (!nrfx_gpiote_is_init()) {
    error_code = nrfx_gpiote_init();
  }
  APP_ERROR_CHECK(error_code);

  // configure leds
  // manually-controlled (simple) output, initially set
  nrfx_gpiote_out_config_t out_config = NRFX_GPIOTE_CONFIG_OUT_SIMPLE(true);
  error_code = nrfx_gpiote_out_init(LED, &out_config);
  APP_ERROR_CHECK(error_code);

  // loop forever
  while (1) {
    printf("sparkfun flash! \n");
    nrf_delay_ms(1000); 
    nrf_gpio_pin_toggle(LED);
  }
}

