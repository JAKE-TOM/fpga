#ifndef _AXI_UART_H_
#define _AXI_UART_H_
/******************************* Include Files ********************************/
#include "stdio.h"
#include "F:\0.zynq\PS_FPGA\5_AXI_GPIO\AXI_GPIO\AXI_GPIO.sdk\AXI_GPIO_bsp_2_bsp_0\ps7_cortexa9_0\include\xparameters.h"
#include "xintc.h"
#include "xil_exception.h"
#include "xil_printf.h"
#include "sleep.h"

#include "F:\0.zynq\PS_FPGA\5_AXI_GPIO\AXI_GPIO\AXI_GPIO.sdk\AXI_GPIO_bsp_2_bsp_0\ps7_cortexa9_0\include\xuartlite.h"
#include "F:\0.zynq\PS_FPGA\5_AXI_GPIO\AXI_GPIO\AXI_GPIO.sdk\AXI_GPIO_bsp_2_bsp_0\ps7_cortexa9_0\include\xuartlite_l.h"
///
//����ID�궨��
#define INTC_DEVICE_ID	XPAR_SCUGIC_0_DEVICE_ID		//�жϿ�����
// #define GPIOPS_ID   XPAR_XGPIOPS_0_DEVICE_ID   	//PS��  GPIO����
#define AXI_UART_ID XPAR_AXI_UARTLITE_0_DEVICE_ID	//PL��  AXI UART����
#define UART_INT_ID XPAR_FABRIC_UARTLITE_0_VEC_ID	//PL��  AXI UART�ж�

#define TEST_BUFFER_SIZE        100
//���Ӷ˿ں궨��
// #define MIO_LED1     0   						//PS LED1 ���ӵ� MIO50

//��������
void axi_gpio_intr_handler(void *CallbackRef);		//�жϷ�����
void axi_uart_init();	
void SendHandler(void *CallBackRef, unsigned int EventData);
void RecvHandler(void *CallBackRef, unsigned int EventData);
void axi_uart_intr_handler(void *CallBackRef);
int UartLiteSetupIntrSystem(XScuGic *IntcInstancePtr,
				XUartLite *UartLiteInstPtr,
				u16 UartLiteIntrId);
/*
extern int led_val;								//LED��ʾ״̬
extern int key_flag;								//�жϱ�־
*/
extern XUartLite UartLite;

#endif /* XDDRPS_H_ */
