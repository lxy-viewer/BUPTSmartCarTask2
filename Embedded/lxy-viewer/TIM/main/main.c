#include "stm32l1xx.h"
#include "stm32l1xx_tim.h"
#include "sys.h"
#include "delay.h"
#include "led.h"
u8 flag;
int main(void)
{ 
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    TIM_TimeBaseStructure.TIM_Period = 65535;
    TIM_TimeBaseStructure.TIM_Prescaler = 0;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    /* TIM IT enable */
    TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE);

    /* TIM2 enable counter */
    TIM_Cmd(TIM2, ENABLE);

    delay_init(32);
    LED_Init();   
	  GPIO_ResetBits(GPIOB, GPIO_Pin_9|GPIO_Pin_7|GPIO_Pin_6|GPIO_Pin_5);
	  GPIO_ResetBits(GPIOA, GPIO_Pin_9|GPIO_Pin_7|GPIO_Pin_6|GPIO_Pin_5);
    while(1)
    {
			digitalToggle(GPIOA,GPIO_Pin_3);
			delay_ms(50);
    }
}



