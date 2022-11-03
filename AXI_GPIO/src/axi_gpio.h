#ifndef _AXI_GPIO_H_
#define _AXI_GPIO_H_
/******************************* Include Files ********************************/
#include "stdio.h"
#include "xparameters.h"
#include "xgpiops.h"
#include "xgpio.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "xil_printf.h"
#include "sleep.h"
///
//����ID�궨��
#define SCUGIC_ID	XPAR_SCUGIC_0_DEVICE_ID		//�жϿ�����
// #define GPIOPS_ID   XPAR_XGPIOPS_0_DEVICE_ID   	//PS��  GPIO����
#define AXI_GPIO_ID XPAR_AXI_GPIO_0_DEVICE_ID	//PL��  AXI GPIO����
#define GPIO_INT_ID XPAR_FABRIC_GPIO_0_VEC_ID	//PL��  AXI GPIO�ж�
//���Ӷ˿ں궨��
// #define MIO_LED1     0   						//PS LED1 ���ӵ� MIO50
#define KEY_CHANNEL  1							//PL_KEY1ʹ��AXI GPIOͨ��1
#define KEY_MASK     XGPIO_IR_CH1_MASK 			//ͨ��1��λ����

//��������
void axi_gpio_intr_handler(void *CallbackRef);		//�жϷ�����
void axi_gpio_init();	

extern int led_val;								//LED��ʾ״̬
extern int key_flag;								//�жϱ�־

#endif /* XDDRPS_H_ */