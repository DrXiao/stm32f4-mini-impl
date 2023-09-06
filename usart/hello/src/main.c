#include <stdint.h>
#include "reg.h"

#define USART_FLAG_TXE	((uint16_t) 0x0080)

void print_str(const char *str) {
	while (*str) {
		while (!(*(USART2_SR) & USART_FLAG_TXE));
		*(USART2_DR) = (*str & 0xFF);
		str++;
	}
}

int main(void) {
	*(RCC_AHB1ENR) |= 0x00000001;
	*(RCC_APB1ENR) |= 0x00020000;

	*(GPIOA_AFRL) = 0x00007700;
	*(GPIOA_AFRH) = 0x00000000;
	*(GPIOA_MODER) = 0xA8000000;
	*(GPIOA_MODER) |= 0x000000A0;
	*(GPIOA_OTYPER) = 0x00000000;
	*(GPIOA_OSPEEDR) = 0x000000F0;
	*(GPIOA_PUPDR) = 0x00000000;
	*(GPIOA_ODR) = 0x00000000;

	*(USART2_CR1) = 0x0000000C;
	*(USART2_CR2) = 0x00000000;
	*(USART2_CR3) = 0x00000000;
	*(USART2_CR1) += 0x2000;
	*(USART2_BRR) = 833;

	print_str("Hello world\r\n");

	while (1) {

	}

	return 0;
}
