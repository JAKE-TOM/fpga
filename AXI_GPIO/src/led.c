// --------------------------------------------------------------------
//
// Permission:
//
//   MicroPhase grants permission to use and modify this code for use
//   in synthesis for all MicroPhase Development Boards.
//   Other use of this code, including the selling
//   ,duplication, or modification of any portion is strictly prohibited.
//
// Disclaimer:
//
//   This VHDL/Verilog or C/C++ source code is intended as a design reference
//   which illustrates how these types of functions can be implemented.
//   It is the user's responsibility to verify their design for
//   consistency and functionality through the use of formal
//   verification methods.  MicroPhase provides no warranty regarding the use
//   or functionality of this code.
//
// --------------------------------------------------------------------
//
//                     MicroPhase Technologies Inc
//                     Shanghai, China
//
//                     web: http://www.microphase.cn/
//                     email: support@microphase.cn
//
// --------------------------------------------------------------------
// --------------------------------------------------------------------
//
// Major Functions:
//
// --------------------------------------------------------------------
// --------------------------------------------------------------------
//
//  Revision History:
//  Date          By            Revision    Change	 Description
//---------------------------------------------------------------------
//2020-02-22      	Wang 		1.0          		Original
//2020-                         1.1
// --------------------------------------------------------------------
// --------------------------------------------------------------------
#include "led.h"
#include "axi_gpio.h"


XGpioPs          gpiops;     				//PS�� GPIO ����ʵ��
XGpioPs_Config * gpiops_cfg; 				//PS�� GPIO ������Ϣ
//PS��GPIO



/*******************/

void ps_led_init(){
    gpiops_cfg = XGpioPs_LookupConfig(GPIOPS_ID);
    XGpioPs_CfgInitialize(&gpiops, gpiops_cfg, gpiops_cfg->BaseAddr);	
    XGpioPs_SetDirectionPin(&gpiops, MIO_LED1, 1);		//���� PS GPIO Ϊ���
    XGpioPs_SetOutputEnablePin(&gpiops, MIO_LED1, 1);	//ʹ��LED���
    XGpioPs_WritePin(&gpiops, MIO_LED1, led_val);		//����LED	
	
}
