#include "printf.h"
#include "mini_uart.h"
#include "utils.h"

void kernel_main(void)
{
	char ch;
	int el = get_el();

	if (el == 2)
	{
		uart_init(BAUD_115200);
	}
	
	init_printf(0, putc);
	printf("Exception level: %d \r\n", el);

	if (el == 1)
	{
		while (1) {
			ch = uart_recv();

			if (ch == '\r')
				uart_send_string("\r\n");
			else 
				uart_send(ch);
		}
	}

}