/*
 * stdoutredirect.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Majid
 */

#ifndef INC_LOGGER_H_
#define INC_LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"
#include "default.h"
#include "stdio.h"

#ifdef __GNUC__
extern int __io_putchar(int ch);
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

//static osMutexId_t log_mutex;

#define LOG(filter, ...) do{ \
	if((filter & LOGGER_LEVEL)){ \
		/*osMutexAcquire(log_mutex, osWaitForever);*/ \
		if(LOGGER_PRINT_TIME) \
			printf("%u\t", LOGGER_TIME_SRC); \
		printf(__VA_ARGS__); \
		if(LOGGER_PRINT_FILE_LINE) \
			printf("\t %s %i", __FILE__, __LINE__); \
		printf("\r\n"); \
		/*osMutexRelease(log_mutex);*/ \
	} \
}while(0);
#define LOG_C(filter, ...) do{ \
	if((filter & LOGGER_LEVEL)){ \
		printf(__VA_ARGS__); \
		fflush(stdout); \
	} \
}while(0);

#ifdef __cplusplus
}
#endif

#endif /* INC_LOGGER_H_ */
