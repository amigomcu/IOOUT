/**
  * @file		includes.c
  * @brief		头文件汇总
  * @author 	redoc <619675912@qq.com>
  * @version	v1.0
  * @date		2017-08-07
  *
  * @note
  * [2016-08-07] <redoc> v1.0
  * 初始版本
  *
  * @remark
  */

#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__

/*
*********************************************************************************************************
*                                         标准库
*********************************************************************************************************
*/
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


#ifdef __cplusplus
extern "C" {
#endif

/*
*********************************************************************************************************
*                                         其它库
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           OS
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                           宏定义
*********************************************************************************************************
*/

/* 中断优先级 小数字为优先极高  */


#define INT_PRO_SOFTTIME					6
#define INT_PRO_SYSTICK						15





/*
*********************************************************************************************************
*                                        APP / BSP
*********************************************************************************************************
*/

#include "stm32f1xx_hal.h"


#ifdef __cplusplus
}
#endif


#endif /******  (END OF FILE) ********/
