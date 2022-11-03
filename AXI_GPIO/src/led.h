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
//器件ID宏定义
#define GPIOPS_ID   XPAR_XGPIOPS_0_DEVICE_ID   	//PS端  GPIO器件
//连接端口宏定义
#define MIO_LED1     0   						//PS LED1 连接到 MIO50

//函数声明
void ps_led_init();	

extern XGpioPs          gpiops;     				//PS端 GPIO 驱动实例
extern XGpioPs_Config * gpiops_cfg; 				//PS端 GPIO 配置信息

#endif /* XDDRPS_H_ */
