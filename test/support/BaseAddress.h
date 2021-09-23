#ifndef BASEADDRESS_H
#define BASEADDRESS_H

#include <stdint.h>

#define PORT_A					getGpioABaseAddress()
#define PORT_B					getGpioBBaseAddress()
#define PORT_C					getGpioCBaseAddress()
#define PORT_D					getGpioDBaseAddress()
#define PORT_E					getGpioEBaseAddress()
#define PORT_H					getGpioHBaseAddress()

#define USART1_BASE_ADDRESS		getUsart1BaseAddress()
#define USART2_BASE_ADDRESS		getUsart2BaseAddress()
#define USART6_BASE_ADDRESS		getUsart6BaseAddress()

#define NVIC_BASE_ADDRESS		getNvicBaseAddress()

uintptr_t getGpioABaseAddress();
uintptr_t getGpioBBaseAddress();
uintptr_t getGpioCBaseAddress();
uintptr_t getGpioDBaseAddress();
uintptr_t getGpioEBaseAddress();
uintptr_t getGpioHBaseAddress();

uintptr_t getUsart1BaseAddress();
uintptr_t getUsart2BaseAddress();
uintptr_t getUsart6BaseAddress();

uintptr_t getNvicBaseAddress();

#endif // BASEADDRESS_H
