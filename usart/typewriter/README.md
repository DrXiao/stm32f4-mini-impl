# STM32 USART - typewriter (Minimal Implementation)

## Demo
Prepare a TTL-to-USB module (e.g.: cp2102 or ch340), and connect PA2(Tx) and PA3(Rx) to module's Rx and Tx, respectively.
Then, use a serial communication tool like ```screen``` to monitor the serial port ```/dev/ttyUSB0```.

When ```screen``` is starting, the screen will print the character, which will be sent from STM32 USART, after you type any key.

* The animation has beenn speeded up.
![](typewriter.gif)
