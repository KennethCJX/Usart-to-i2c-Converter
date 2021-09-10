#ifndef BASEADDRESS_H
#define BASEADDRESS_H

#include <stdint.h>

#define PORT_A					getGpioABaseAddress()
#define PORT_B					getGpioBBaseAddress()
#define PORT_C					getGpioCBaseAddress()
#define PORT_D					getGpioDBaseAddress()
#define PORT_E					getGpioEBaseAddress()
#define PORT_H					getGpioHBaseAddress()

#define NVIC_BASE_ADDRESS		getNvicBaseAddress()

uintptr_t getGpioABaseAddress();
uintptr_t getGpioBBaseAddress();
uintptr_t getGpioCBaseAddress();
uintptr_t getGpioDBaseAddress();
uintptr_t getGpioEBaseAddress();
uintptr_t getGpioHBaseAddress();
uintptr_t getNvicBaseAddress();

#endif // BASEADDRESS_H
