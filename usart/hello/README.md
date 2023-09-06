# STM32 USART - hello (Minimal Implementation)

## Demo
Prepare a TTL-to-USB module (e.g.: cp2102 or ch340), and connect PA2(Tx) and PA3(Rx) to module's Rx and Tx, respectively.
Then, use a serial communication tool like ```screen``` to monitor the serial port ```/dev/ttyUSB0```.
After starting ```screen```, the string ```"Hello World"``` will be printed after resetting STM32.

* The animation has been speeded up.

![](hello.gif)
