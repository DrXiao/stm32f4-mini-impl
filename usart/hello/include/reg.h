#ifndef __REG_H__
#define __REG_H__
#include <stdint.h>

#define __REG_TYPE	volatile uint32_t
#define __REG		__REG_TYPE *

#define RCC		((__REG_TYPE) 0x40023800)
#define RCC_CR		((__REG) (RCC + 0x00))
#define RCC_PLLCFGR	((__REG) (RCC + 0x04))
#define RCC_CFGR	((__REG) (RCC + 0x08))
#define RCC_CIR		((__REG) (RCC + 0x0C))
#define RCC_AHB1RSTR	((__REG) (RCC + 0x10))
#define RCC_AHB2RSTR	((__REG) (RCC + 0x14))
#define RCC_AHB3RSTR	((__REG) (RCC + 0x18))
#define RCC_APB1RSTR	((__REG) (RCC + 0x20))
#define RCC_APB2RSTR	((__REG) (RCC + 0x24))
#define RCC_AHB1ENR	((__REG) (RCC + 0x30))
#define RCC_AHB2ENR	((__REG) (RCC + 0x34))
#define RCC_AHB3ENR	((__REG) (RCC + 0x38))
#define RCC_APB1ENR	((__REG) (RCC + 0x40))
#define RCC_APB2ENR	((__REG) (RCC + 0x44))
#define RCC_AHB1LPENR	((__REG) (RCC + 0x50))
#define RCC_AHB2LPENR	((__REG) (RCC + 0x54))
#define RCC_AHB3LPENR	((__REG) (RCC + 0x58))
#define RCC_APB1LPENR	((__REG) (RCC + 0x60))
#define RCC_APB2LPENR	((__REG) (RCC + 0x64))
#define RCC_BDCR	((__REG) (RCC + 0x70))
#define RCC_CSR		((__REG) (RCC + 0x74))
#define RCC_SSCGR	((__REG) (RCC + 0x80))
#define RCC_PLLI2SCFGR	((__REG) (RCC + 0x84))
#define RCC_PLLSAICFGR	((__REG) (RCC + 0x88))
#define RCC_DCKCFGR	((__REG) (RCC + 0x8C))

#define RCC_CR_HSION	((uint32_t) 0x00000001)
#define RCC_CR_HSEON	((uint32_t) 0x00010000)
#define RCC_CR_HSERDY	((uint32_t) 0x00020000)
#define RCC_CR_CSSON	((uint32_t) 0x00080000)

#define RCC_CFGR_SW		((uint32_t) 0x00000003)
#define RCC_CFGR_SW_HSE		((uint32_t) 0x00000001)
#define RCC_CFGR_SWS		((uint32_t) 0x0000000C)
#define RCC_CFGR_HPRE_DIV1	((uint32_t) 0x00000000)
#define RCC_CFGR_PPRE1_DIV1	((uint32_t) 0x00000000)
#define RCC_CFGR_PPRE2_DIV1	((uint32_t) 0x00000000)


#define FLASH		((__REG_TYPE) 0x40023C00)
#define FLASH_ACR	((__REG) (FLASH + 0x00))

#define FLASH_ACR_LATENCY	((uint8_t) 0x03)
#define FLASH_ACR_LATENCY_0	((uint8_t) 0x00)
#define FLASH_ACR_PRFTBE	((uint8_t) 0x10)


#define HSE_STARTUP_TIMEOUT	((uint16_t) 0x0500)


#define GPIOA		((__REG_TYPE) 0x40020000)
#define GPIOA_MODER	((__REG) (GPIOA + 0x00))
#define GPIOA_OTYPER	((__REG) (GPIOA + 0x04))
#define GPIOA_OSPEEDR	((__REG) (GPIOA + 0x08))
#define GPIOA_PUPDR	((__REG) (GPIOA + 0x0C))
#define GPIOA_IDR	((__REG) (GPIOA + 0x10))
#define GPIOA_ODR	((__REG) (GPIOA + 0x14))
#define GPIOA_BSRR	((__REG) (GPIOA + 0x18))
#define GPIOA_LCKR	((__REG) (GPIOA + 0x1C))
#define GPIOA_AFRL	((__REG) (GPIOA + 0x20))
#define GPIOA_AFRH	((__REG) (GPIOA + 0x24))


#define USART2		((__REG_TYPE) 0x40004400)
#define USART2_SR	((__REG) (USART2 + 0x00))
#define USART2_DR	((__REG) (USART2 + 0x04))
#define USART2_BRR	((__REG) (USART2 + 0x08))
#define USART2_CR1	((__REG) (USART2 + 0x0C))
#define USART2_CR2	((__REG) (USART2 + 0x10))
#define USART2_CR3	((__REG) (USART2 + 0x14))
#define USART2_GTPR	((__REG) (USART2 + 0x18))

#endif
