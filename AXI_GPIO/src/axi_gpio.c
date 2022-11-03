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
#include "axi_gpio.h"

int led_val;								//LED��ʾ״̬
int key_flag=0;								//�жϱ�־
//PS��GPIO


//PL��AXI_GPIO
XGpio            axi_gpio;					//PL�� AXI GPIO ����ʵ��
//�жϿ���
XScuGic 		 scugic;					//�жϿ�����  ����ʵ��
XScuGic_Config * scugic_cfg; 				//�жϿ�����  ������Ϣ
/*******************/

void axi_gpio_init(){
    //��ʼ��PL��  AXI GPIO����
    XGpio_Initialize(&axi_gpio, AXI_GPIO_ID);
    //��ʼ���жϿ���������
	scugic_cfg = XScuGic_LookupConfig(SCUGIC_ID);
    XScuGic_CfgInitialize(&scugic, scugic_cfg, scugic_cfg->CpuBaseAddress);
    //����PL AXI GPIO
    XGpio_SetDataDirection(&axi_gpio, KEY_CHANNEL, 1); //����PL AXI GPIOͨ��1Ϊ����
    XGpio_InterruptEnable(&axi_gpio, KEY_MASK);		//ʹ��ͨ��1�ж�
    XGpio_InterruptGlobalEnable(&axi_gpio);			//ʹ��AXI GPIOȫ���ж�
    //�����ж����ȼ��ʹ�������(�ߵ�ƽ����)
    XScuGic_SetPriorityTriggerType(&scugic, GPIO_INT_ID, 0xA0, 0x1);
    //�����ж�ԴAXI_GPIO���жϴ�����axi_gpio_intr_handler
    XScuGic_Connect(&scugic, GPIO_INT_ID, axi_gpio_intr_handler, &axi_gpio);
    //ʹ��AXI GPIO�ж�
    XScuGic_Enable(&scugic, GPIO_INT_ID);

    //���ò����ж��쳣������
    Xil_ExceptionInit();
    Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
    		(Xil_ExceptionHandler)XScuGic_InterruptHandler, &scugic);
    Xil_ExceptionEnable();


	
}



// AXI GPIO �жϷ�����
void axi_gpio_intr_handler(void *CallbackRef)
{
	int key_value = 1;
	XGpio *GpioPtr = (XGpio *)CallbackRef;


	XGpio_InterruptDisable(GpioPtr, KEY_MASK);				//AXI GPIO�ж�ʧ��
	key_value = XGpio_DiscreteRead(GpioPtr, KEY_CHANNEL);
	usleep(100000);												//��ʱ100ms,��������
	if(key_value == 0){										//�жϰ�������
		key_flag=1;
	}

	XGpio_InterruptClear(GpioPtr, KEY_MASK);				//����жϱ�־
	XGpio_InterruptEnable(GpioPtr, KEY_MASK);				//AXI GPIO�ж�ʹ��
}
