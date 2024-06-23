#ifndef __UART_H__
#define __UART_H__

#include "gpio.h"
#include "utils.h"
#include "types.h"

void uart_init();
Byte uart_tx_ready();
Byte uart_data_ready();
void uart_send(Byte c);
Byte uart_get();
void uart_puts(char *s);


#define MINI_UART_BASE MMIO_BASE + 0x00215000

// Baudrate = system_clock_freq / 8*(baudrate_reg + 1)

#define AUX_IRQ         (MINI_UART_BASE + 0x00) // Auxiliary Interrupt status
#define AUX_ENABLES     (MINI_UART_BASE + 0x04) // Auxiliary enables
#define AUX_MU_IO_REG   (MINI_UART_BASE + 0x40) // Mini UART I/O Data
#define AUX_MU_IER_REG  (MINI_UART_BASE + 0x44) // Mini UART Interrupt Enable
#define AUX_MU_IIR_REG  (MINI_UART_BASE + 0x48) // Mini UART Interrupt Identify
#define AUX_MU_LCR_REG  (MINI_UART_BASE + 0x4c) // Mini UART Line Control
#define AUX_MU_MCR_REG  (MINI_UART_BASE + 0x50) // Mini UART Modem Control
#define AUX_MU_LSR_REG  (MINI_UART_BASE + 0x54) // Mini UART Line Status
#define AUX_MU_MSR_REG  (MINI_UART_BASE + 0x58) // Mini UART Modem Status
#define AUX_MU_SCRATCH  (MINI_UART_BASE + 0x5c) // Mini UART Scratch
#define AUX_MU_CNTL_REG (MINI_UART_BASE + 0x60) // Mini UART Extra Control
#define AUX_MU_STAT_REG (MINI_UART_BASE + 0x64) // Mini UART Extra Status
#define AUX_MU_BAUD_REG (MINI_UART_BASE + 0x68) // Mini UART Baudrate

#endif // __UART_H__