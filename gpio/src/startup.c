#include <stdint.h>

#include "reg.h"
#include "isr.h"

extern int main(void);

extern uint32_t _sidata;

extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

extern uint32_t _estack;

__attribute__((section(".isr_vector"))) 
uint32_t *isr_vectors[]= {
	(uint32_t *) &_estack,
	(uint32_t *) reset_handler,
	(uint32_t *) nmi_handler,
	(uint32_t *) hardfault_handler
};

void rcc_clock_init(void);

void reset_handler(void) {
	uint32_t *idata_begin = &_sidata;
	uint32_t *data_begin = &_sdata;
	uint32_t *data_end = &_edata;

	while (data_begin < data_end) *data_begin++ = *idata_begin++;

	uint32_t *bss_begin = &_sbss;
	uint32_t *bss_end = &_ebss;
	while (bss_begin < bss_end) *bss_begin++ = 0;

	rcc_clock_init();

	main();
}

void rcc_clock_init(void) {
	*RCC_CR |= (uint32_t) 0x00000001;
	*RCC_CFGR = (uint32_t) 0x00000000;
	*RCC_CFGR &= (uint32_t) 0xFEF6FFFF;
	*RCC_PLLCFGR = 0x24003010;
	*RCC_CR &= (uint32_t) 0xFFFBFFFF;
	*RCC_CIR = 0x00000000;

	volatile uint32_t StartUpCounter = 0, HSEStatus = 0;

	*RCC_CR |= (uint32_t) RCC_CR_HSEON;

	do {
		HSEStatus = *RCC_CR & RCC_CR_HSERDY;
		StartUpCounter++;
	} while ((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

	if ((*RCC_CR & RCC_CR_HSERDY) != 0)
		HSEStatus = (uint32_t) 0x01;
	else
		HSEStatus = (uint32_t) 0x00;

	if (HSEStatus == (uint32_t) 0x01) {

		*FLASH_ACR |= FLASH_ACR_PRFTBE;
		*FLASH_ACR &= (uint32_t) ((uint32_t) ~FLASH_ACR_LATENCY);
		*FLASH_ACR |= (uint32_t) FLASH_ACR_LATENCY_0;
		

		*RCC_CFGR |= (uint32_t) RCC_CFGR_HPRE_DIV1;
		*RCC_CFGR |= (uint32_t) RCC_CFGR_PPRE2_DIV1;
		*RCC_CFGR |= (uint32_t) RCC_CFGR_PPRE1_DIV1;
		*RCC_CFGR &= (uint32_t) ((uint32_t) ~(RCC_CFGR_SW));
		*RCC_CFGR |= (uint32_t) RCC_CFGR_SW_HSE;

		while ((*RCC_CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) 0x04);

	}
	else {

	}
}
