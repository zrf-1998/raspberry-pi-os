#include "mini_uart.h"

void kernel_main(void)
{
	char ch;

	uart_init(BAUD_115200);
	uart_send_string("Hello, world!\r\n");

	while (1) {
		ch = uart_recv();

		if (ch == '\r')
			uart_send_string("\r\n");
		else 
			uart_send(ch);
	}
}