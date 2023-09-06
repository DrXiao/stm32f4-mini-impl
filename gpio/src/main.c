#include <stdint.h>
#include "reg.h"

void delay(uint32_t count) {
	while (count--);
}

int main(void) {
	*(RCC_AHB1ENR) |= (0x00000008);

	*(GPIOD_MODER) = 0x00000000;
	*(GPIOD_MODER) |= 0x55000000;
	*(GPIOD_OTYPER) = 0x00000000;
	*(GPIOD_OSPEEDR) = 0x00000000;
	*(GPIOD_PUPDR) = 0x00000000;
	*(GPIOD_ODR) = 0x00000000;

	while (1) {
		*(GPIOD_BSRR) |= 0x00001000;
		delay(1e5);
		*(GPIOD_BSRR) |= 0x00002000;
		delay(1e5);
		*(GPIOD_BSRR) |= 0x00004000;
		delay(1e5);
		*(GPIOD_BSRR) |= 0x00008000;
		delay(1e5);

		delay(1e5);

		*(GPIOD_BSRR) |= 0x10000000;
		delay(1e5);
		*(GPIOD_BSRR) |= 0x20000000;
		delay(1e5);
		*(GPIOD_BSRR) |= 0x40000000;
		delay(1e5);
		*(GPIOD_BSRR) |= 0x80000000;
		delay(1e5);

		delay(1e5);
	}

	return 0;
}
