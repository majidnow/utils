/*
 * default.h
 *
 *  Created on: May 4, 2024
 *      Author: majid
 */

#ifndef DEFAULT_H_
#define DEFAULT_H_

#include "user_defined.h"

// logger
#ifndef LOGGER_LEVEL
#define LOGGER_LEVEL			(LOG_DEBUG)
#endif

#ifndef LOGGER_INTERFACE
#define LOGGER_INTERFACE 		LOGGER_INTERFACE_ITM
#endif

#ifndef LOGGER_UART
#define LOGGER_UART				huart7
#endif

#ifndef LOGGER_PRINT_TIME
#define LOGGER_PRINT_TIME		0
#endif

#ifndef LOGGER_PRINT_FILE_LINE
#define LOGGER_PRINT_FILE_LINE	0
#endif

#ifndef LOGGER_TIME_SRC
#define LOGGER_TIME_SRC			0
#endif


#endif /* DEFAULT_H_ */
