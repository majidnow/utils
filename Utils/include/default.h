/*
 * default.h
 *
 *  Created on: May 4, 2024
 *      Author: majid
 */

#ifndef DEFAULT_H_
#define DEFAULT_H_

// general
#define UTILS_CMSISOS_ENABLED	0

// logger
#define LOGGER_UART				(0x01)
#define LOGGER_ITM				(0x02)

#define	LOG_DEBUG  				((unsigned int)0x000001U)

#define LOGGER_LEVEL			(LOG_DEBUG)
#define LOGGER_INTERFACE 		LOGGER_ITM

#if LOGGER_INTERFACE == LOGGER_UART
#define LOGGER_UART_INSTANC	UART7
#endif

#define LOGGER_PRINT_TIME		0
#define LOGGER_PRINT_FILE_LINE	0
#define LOGGER_TIME_SRC			0


#endif /* DEFAULT_H_ */
