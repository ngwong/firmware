/**
  Copyright (c) 2013-2018 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
  ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

#include "platforms.h"

// STM32 Device electronic signature
// Factory-programmed 12 byte unique device ID
#define         ID1          (0x1FFF7A10)
#define         ID2          (0x1FFF7A14)
#define         ID3          (0x1FFF7A18)

#ifndef PLATFORM_ID
#error "PLATFORM_ID not defined"
#endif

//LEDs
// TODO - map to Xenon hardware
#define LEDn                                4
#define LED_MIRROR_SUPPORTED                1
#define LED1_GPIO_AF_TIM                    0                       //User Led
#define LED1_GPIO_PIN                       GPIO_Pin_13             //User Led
#define LED1_GPIO_PIN_SOURCE                GPIO_PinSource13        //User Led
#define LED1_GPIO_PORT                      GPIOA                   //User Led
#define LED1_GPIO_CLK                       RCC_AHB1Periph_GPIOA    //User Led
#define LED1_GPIO_MODE                      GPIO_Mode_OUT           //User Led
#define LED_BLUE                            LED2
#define LED2_GPIO_AF_TIM                    GPIO_AF_TIM2            //BLUE Led
#define LED2_GPIO_PIN                       GPIO_Pin_3              //BLUE Led
#define LED2_GPIO_PIN_SOURCE                GPIO_PinSource3         //BLUE Led
#define LED2_GPIO_PORT                      GPIOA                   //BLUE Led
#define LED2_GPIO_CLK                       RCC_AHB1Periph_GPIOA    //BLUE Led
#define LED2_GPIO_MODE                      GPIO_Mode_AF            //BLUE Led
#define LED_RED                             LED3
#define LED3_GPIO_AF_TIM                    GPIO_AF_TIM2            //RED Led
#define LED3_GPIO_PIN                       GPIO_Pin_1              //RED Led
#define LED3_GPIO_PIN_SOURCE                GPIO_PinSource1         //RED Led
#define LED3_GPIO_PORT                      GPIOA                   //RED Led
#define LED3_GPIO_CLK                       RCC_AHB1Periph_GPIOA    //RED Led
#define LED3_GPIO_MODE                      GPIO_Mode_AF            //RED Led
#define LED_GREEN                           LED4
#define LED4_GPIO_AF_TIM                    GPIO_AF_TIM2            //GREEN Led
#define LED4_GPIO_PIN                       GPIO_Pin_2              //GREEN Led
#define LED4_GPIO_PIN_SOURCE                GPIO_PinSource2         //GREEN Led
#define LED4_GPIO_PORT                      GPIOA                   //GREEN Led
#define LED4_GPIO_CLK                       RCC_AHB1Periph_GPIOA    //GREEN Led
#define LED4_GPIO_MODE                      GPIO_Mode_AF            //GREEN Led

//Push Buttons
#define BUTTONn                             1
#define BUTTON1_GPIO_PIN                    GPIO_Pin_7
#define BUTTON1_GPIO_PORT                   GPIOC
#define BUTTON1_GPIO_CLK                    RCC_AHB1Periph_GPIOC
#define BUTTON1_GPIO_MODE                   GPIO_Mode_IN
#define BUTTON1_GPIO_PUPD                   GPIO_PuPd_UP
#define BUTTON1_PRESSED                     0x00
#define BUTTON1_EXTI_LINE                   EXTI_Line7
#define BUTTON1_EXTI_PORT_SOURCE            EXTI_PortSourceGPIOC
#define BUTTON1_EXTI_PIN_SOURCE             EXTI_PinSource7
#define BUTTON1_EXTI_IRQn                   EXTI9_5_IRQn
#define BUTTON1_EXTI_IRQ_HANDLER            EXTI9_5_IRQHandler
#define BUTTON1_EXTI_IRQ_PRIORITY           7
#define BUTTON1_EXTI_IRQ_INDEX              39
#define BUTTON1_EXTI_TRIGGER                EXTI_Trigger_Falling
#define BUTTON1_MIRROR_SUPPORTED            1

#define UI_TIMER_FREQUENCY                  100	/* 100Hz -> 10ms */
#define BUTTON_DEBOUNCE_INTERVAL            1000 / UI_TIMER_FREQUENCY

// todo - add this later #define FLASH_UPDATE_MODULES

//NVIC Priorities based on NVIC_PriorityGroup_4
#define SDIO_IRQ_PRIORITY                   0       //??? BCM43362 SDIO Interrupt
#ifdef USE_USB_OTG_FS
#define OTG_FS_IRQ_PRIORITY                 2       //USB OTG FS Interrupt
#define OTG_FS_WKUP_IRQ_PRIORITY            2       //USB OTG FS Wakeup Interrupt
#elif defined USE_USB_OTG_HS
#define OTG_HS_EP1_IN_IRQ_PRIORITY          2       //USB OTG HS EP1 IN Interrupt
#define OTG_HS_EP1_OUT_IRQ_PRIORITY         2       //USB OTG HS EP1 OUT Interrupt
#define OTG_HS_IRQ_PRIORITY                 2       //USB OTG HS Interrupt
#define OTG_HS_WKUP_IRQ_PRIORITY            2       //USB OTG HS Wakeup Interrupt
#endif
#define RTC_Alarm_IRQ_PRIORITY              3       //RTC Alarm Interrupt
#define RTC_WKUP_IRQ_PRIORITY               4       //RTC Seconds Interrupt
#define USART1_IRQ_PRIORITY                 5       //USART1 Interrupt
#define USART2_IRQ_PRIORITY                 5       //USART2 Interrupt
#define TIM2_IRQ_PRIORITY                   6       //TIM2 CC Interrupt(Button Use)
//BUTTON1_EXTI_IRQ_PRIORITY                 7       //Mode Button Interrupt
#define EXTI15_10_IRQ_PRIORITY              8       //User Interrupt
#define EXTI9_5_IRQ_PRIORITY                9       //User Interrupt
#define EXTI0_IRQ_PRIORITY                  10      //User Interrupt
#define EXTI1_IRQ_PRIORITY                  10      //User Interrupt
#define EXTI2_IRQ_PRIORITY                  10      //User Interrupt
#define EXTI3_IRQ_PRIORITY                  10      //User Interrupt
#define EXTI4_IRQ_PRIORITY                  10      //User Interrupt
#define SYSTICK_IRQ_PRIORITY                13      //CORTEX_M3 Systick Interrupt
#define SVCALL_IRQ_PRIORITY                 14      //CORTEX_M3 SVCall Interrupt
#define PENDSV_IRQ_PRIORITY                 15      //CORTEX_M3 PendSV Interrupt

#define PREPSTRING2(x) #x
#define PREPSTRING(x) PREPSTRING2(x)

#if PLATFORM_ID == PLATFORM_XENON
    #define INTERNAL_FLASH_SIZE             (0x100000)
#else
    #pragma message "PLATFORM_ID is " PREPSTRING(PLATFORM_ID)
    #error "Unknown PLATFORM_ID"
#endif

/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */

