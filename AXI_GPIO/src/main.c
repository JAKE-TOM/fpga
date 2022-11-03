//////////////////////////////////////////////////////////////////////////////////
// Company:  Time Studio
// Engineer: He Jiakang
//
// Create Date: 2022/11/01 22:48:00
// Design Name: axi_uart
// Module Name: axi_uart
// Project Name:axi_uart
// Target Devices: zynq 7010
// Tool Versions: 2018.3
// Description: test RAM on the board of zynq7010
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////
#include "stdio.h"
#include "xparameters.h"
#include "xgpiops.h"
#include "xgpio.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "xil_printf.h"
#include "sleep.h"
#include "axi_gpio.h"
#include "axi_uart.h"
#include "led.h"

char p[] = "hello";

int main()
{
    printf("AXI_GPIO Test!\n");

	axi_gpio_init();
	axi_uart_init();
	ps_led_init();
    while(1)
    {
    	if(key_flag)
    	{
    		key_flag=0;
    		led_val = ~led_val;
    		XGpioPs_WritePin(&gpiops, MIO_LED1, led_val);	//¸Ä±äLEDÁÁÃð
			XUartLite_Send(&UartLite, p, 5);
    	}
    }

    return 0;
}

