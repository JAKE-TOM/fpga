#ifndef _LED_H_
#define _LED_H_
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
#define GPIOPS_ID   XPAR_XGPIOPS_0_DEVICE_ID   	//PS��  GPIO����
//���Ӷ˿ں궨��
#define MIO_LED1     0   						//PS LED1 ���ӵ� MIO50

//��������
void ps_led_init();	

extern XGpioPs          gpiops;     				//PS�� GPIO ����ʵ��
extern XGpioPs_Config * gpiops_cfg; 				//PS�� GPIO ������Ϣ

#endif /* XDDRPS_H_ */
