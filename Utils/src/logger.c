/*
 * stdoutredirect.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Majid
 */
#include "logger.h"

PUTCHAR_PROTOTYPE
{
#if LOGGER_INTERFACE == LOGGER_INTERFACE_UART
	HAL_UART_Transmit(&LOGGER_UART, (const uint8_t*)&ch, 1, 100);
#else
    ITM_SendChar(ch);
#endif
    return ch;
}

