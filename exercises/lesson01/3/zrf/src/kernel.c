#include "mini_uart.h"
#include "utils.h"

void kernel_main(int cpu_id)
{
	if (cpu_id == 0)
		uart_init(BAUD_115200);
	else
		delay(1000000 * cpu_id);

	uart_send_string("Hello, from processor ");
	uart_send('0' + cpu_id);
	uart_send_string("!\r\n");

	if (cpu_id == 0)
	{
		while (1) 
		{
			uart_send(uart_recv());
		}
	}
}