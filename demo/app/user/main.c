/**
  * @file       main.c
  * @brief      主程序
  * @author     redoc <619675912@qq.com>
  * @version    v1.0
  * @date       2017-08-23
  *
  * @note
  * [2016-08-03] <redoc> v1.0
  * 初始版本
  *
  * @remark
  */

/* Includes ------------------------------------------------------------------*/
#include "includes.h"
#include "bsp.h"
#include "ioout.h"


/* typedef -----------------------------------------------------------*/
/* define ------------------------------------------------------------*/
/* macro -------------------------------------------------------------*/
#define ENABLE_INT()	__ASM volatile("cpsie i")           /* 使能全局中断 */
#define DISABLE_INT()	__ASM volatile("cpsid i")           /* 禁止全局中断 */

/* variables ---------------------------------------------------------*/
const uint8_t projectTab[] = {"operation"};                  /**<  项目名称   */
const uint8_t versionsTab[] = {"V1.1.00beta"};               /**<  版本信息   */
const uint8_t userNameTab[] = {"redoc"};                     /**<  用户名     */

/* function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);


/* functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    HAL_Init();
    SystemClock_Config();

    DISABLE_INT();

    BSP_Init();
    ioout_config();

    ENABLE_INT();

    ioout_set(ID_IOOUT_LED1,1000,1000,0);
    ioout_set(ID_IOOUT_LED2,200,200,0);

    while (1)
    {
        ioout_pause(ID_IOOUT_LED1);
        HAL_Delay(1000);
        ioout_start(ID_IOOUT_LED2);
        HAL_Delay(1000);
        ioout_stop(ID_IOOUT_LED1);
        HAL_Delay(1000);
        ioout_set(ID_IOOUT_LED2,200,200,2000);
        HAL_Delay(5000);

    }
}

/**
  * @brief      系统时钟配置
  * @param      void
  *
  * @return     void
  * @remark
  */
static void SystemClock_Config(void)
{
    RCC_ClkInitTypeDef clkinitstruct = {0};
    RCC_OscInitTypeDef oscinitstruct = {0};

    /* Enable HSE Oscillator and activate PLL with HSE as source */
    oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
    oscinitstruct.HSEState        = RCC_HSE_ON;
    oscinitstruct.HSEPredivValue  = RCC_HSE_PREDIV_DIV1;
    oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
    oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;
    oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL9;
    if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
    {
        /* Initialization Error */
        while(1);
    }

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
       clocks dividers */
    clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
    clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;
    if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
    {
        /* Initialization Error */
        while(1);
    }
}

/**
  * @brief      系统中断配置
  * @param      void
  *
  * @return     void
  * @remark
  */
void HAL_MspInit(void)
{
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    /* System interrupt init*/
    /* MemoryManagement_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
    /* BusFault_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
    /* UsageFault_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
    /* DebugMonitor_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DebugMonitor_IRQn, 0, 0);
    /* SysTick_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(SysTick_IRQn, INT_PRO_SYSTICK, 0);
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif



