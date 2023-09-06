#include <stdint.h>
#include "reg.h"

#define USART_FLAG_TXE	((uint16_t) 0x0080)
#define USART_FLAG_RXNE ((uint16_t) 0x0020)

void usart_putc(const char ch) {
	while (!(*(USART2_SR) & USART_FLAG_TXE));
	*(USART2_DR) = (ch & 0xFF);
}

char usart_getc(void) {
	while (!(*(USART2_SR) & USART_FLAG_RXNE));
	return *(USART2_DR) & 0xFF;
}

int main(void) {

	*(RCC_AHB1ENR) |= (uint32_t) (0x00000001);
	*(RCC_APB1ENR) |= (uint32_t) (0x00020000);

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

	char ch;
	while (1) {
		ch = usart_getc();
		usart_putc(ch);
	}

	return 0;
}
