# STM32 F4 Minimal Implementation (= stm32F4-mini-impl)
## Purpose
The repository is inspired by [mini-arm-os](https://github.com/jserv/mini-arm-os) and [stm32f4-examples](https://github.com/shengwen-tw/stm32f4-examples).

The purpose of the repo wants to provide the cases that **use the minimal amount of code to let a STM32 board work normally without any libraries like Hardware Abstract Level library (HAL) or Standard Peripheral Library (SPL)**.

The repo expects that readers can learn the following concepts:
1. The boot sequence of ARM Cortex-M4 processor.
2. How to use a linker script to describe program entry and memory layout.
3. The behavior of ```reset_handler()``` in the cases.
4. STM32F4 peripheral.
5. STM32F4 memory mapping and memory mapped input/output (MMIO).
6. The behavior of ```rcc_clock_init()``` and ```main()```.

