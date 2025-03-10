/**
 * Copyright (c) 2016 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "nrf.h"
#include "nrf_drv_clock.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_drv_power.h"
#include "nrf_serial.h"
#include "app_timer.h"


#include "app_error.h"
#include "app_util.h"
#include "boards.h"

/** @file
 * @defgroup nrf_serial_example main.c
 * @{
 * @ingroup nrf_serial_example
 * @brief Example of @ref nrf_serial usage. Simple loopback.
 *
 */

#define OP_QUEUES_SIZE          3
#define APP_TIMER_PRESCALER     NRF_SERIAL_APP_TIMER_PRESCALER
#define ENABLE NRF_GPIO_PIN_MAP(0,8)

char store[1000];

static void sleep_handler(void)
{
    __WFE();
}

NRF_SERIAL_DRV_UART_CONFIG_DEF(m_uart0_drv_config,
                      NRF_GPIO_PIN_MAP(0, 14), NRF_GPIO_PIN_MAP(0, 13),
                      0, 0,
                      NRF_UART_HWFC_ENABLED, NRF_UART_PARITY_EXCLUDED,
                      NRF_UART_BAUDRATE_9600,
                      2);

#define SERIAL_FIFO_TX_SIZE 32
#define SERIAL_FIFO_RX_SIZE 32

NRF_SERIAL_QUEUES_DEF(serial_queues, SERIAL_FIFO_TX_SIZE, SERIAL_FIFO_RX_SIZE);


#define SERIAL_BUFF_TX_SIZE 1
#define SERIAL_BUFF_RX_SIZE 1

NRF_SERIAL_BUFFERS_DEF(serial_buffs, SERIAL_BUFF_TX_SIZE, SERIAL_BUFF_RX_SIZE);

NRF_SERIAL_CONFIG_DEF(serial_config, NRF_SERIAL_MODE_POLLING,
                      &serial_queues, &serial_buffs, NULL, sleep_handler);


NRF_SERIAL_UART_DEF(serial_uart, 0);


int main(void)
{
    ret_code_t ret;

    size_t * p_written = 0;

    ret = nrf_drv_clock_init();
    APP_ERROR_CHECK(ret);
    //ret = nrf_drv_power_init(NULL);
    //APP_ERROR_CHECK(ret);

    nrf_drv_clock_lfclk_request(NULL);
    ret = app_timer_init();
    APP_ERROR_CHECK(ret);

    // // Initialize LEDs and buttons.
    // bsp_board_init(BSP_INIT_LEDS | BSP_INIT_BUTTONS);

    ret = nrf_serial_init(&serial_uart, &m_uart0_drv_config, &serial_config);
    printf("Initialized\n");
    APP_ERROR_CHECK(ret);

    // static char tx_message[] = "Hello nrf_serial!\n\r";

    // ret = nrf_serial_write(&serial_uart,
    //                        tx_message,
    //                        strlen(tx_message),
    //                        NULL,
    //                        NRF_SERIAL_MAX_TIMEOUT);
    // APP_ERROR_CHECK(ret);

    int i = 0;
    while (true) {
        size_t * tp = 0;

        int len = 0;
        memset(store, 0, 1000);
        char c;

        //printf("frozen?\n");
        ret = nrf_serial_read(&serial_uart, &c, sizeof(c), NULL, 1000);
        printf("%x\n", ret);
        //printf("frozen\n");
        store[len] = c;

        while(c!='\n'){
            ret = nrf_serial_read(&serial_uart, &c, sizeof(c), NULL, 1000); 
            if (ret != 0)
                break;
            //printf("%u\n", ret);
            store[++len] = c;
            //printf("%s\n", c);
        }

        printf("%s", store);

        // if (i++ > 2) {
        //     printf("counter %d\n", i);
        nrf_delay_ms(1000);

        ret = nrf_serial_uninit(&serial_uart);
        printf("Uninitialized: %x\n", ret);
        ret = nrf_serial_init(&serial_uart, &m_uart0_drv_config, &serial_config);
        printf("Initialized: %x\n", ret);

        //     printf("delaying\n");

        //     // ret = nrf_drv_clock_init();
        //     // nrf_drv_clock_lfclk_request(NULL);
        //     // ret = app_timer_init();
        //     // ret = nrf_serial_init(&serial_uart, &m_uart0_drv_config, &serial_config);
        //     // printf("Initialized\n");
        // }
            //printf("%c", '0');

            //(void)nrf_serial_write(&serial_uart, &c, sizeof(c), NULL, 0);
            //(void)nrf_serial_flush(&serial_uart, 0);

    }
}

/** @} */