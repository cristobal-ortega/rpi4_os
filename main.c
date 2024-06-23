#include "uart.h"
#include "types.h"
#include "utils.h"
#include "gpio.h"

void main() {

    // INIT
    uart_init();

    uart_puts("Init done\n");

    // echo UART
    while(1) {
        uart_send(uart_get());
    }

}