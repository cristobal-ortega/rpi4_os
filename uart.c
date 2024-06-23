#include "uart.h"

void uart_init() {


    set_address_to(AUX_ENABLES, 0x1); // Enable mini-UART
    set_address_to(AUX_MU_CNTL_REG, 0x0); // Disable Transmiter and receiver while configuring
    set_address_to(AUX_MU_BAUD_REG, 270); // Set Baud

    set_address_to(AUX_MU_LCR_REG, 	0x03); // Document UART 16550. 8 bits, 1 stop (8N1)

    unsigned int cur = get_value_from(GPFSEL1);
    cur &= ~(0b111<<15 | 0b111<<12); // Clear function for pins 14 and 15
    cur |=  (0b010<<15 | 0b010<<12); // Set function 15
    set_address_to(GPFSEL1, cur);

    set_address_to(AUX_MU_CNTL_REG, 0x3); // Enable Transmiter and receiver
}

Byte uart_tx_ready() {
	return (get_value_from(AUX_MU_LSR_REG)>>5)&0x1;
}

Byte uart_data_ready() {
	return get_value_from(AUX_MU_LSR_REG)&0x1;
}

void uart_send(Byte c) {
    while(!uart_tx_ready());
    set_address_to(AUX_MU_IO_REG, c);
}

Byte uart_get() {
	while (!uart_data_ready());
    Byte ret = get_value_from(AUX_MU_IO_REG);
    return (ret == '\r') ? '\n' : ret;
}


void uart_puts(char *s) {
    while(*s) {
        /* convert newline to carriage return + newline */
        if(*s == '\n')
            uart_send('\r');
        uart_send(*s++);
    }
}