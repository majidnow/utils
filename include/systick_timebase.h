/*
 * systick_timebase.h
 *
 *  Created on: Mar 12, 2023
 *      Author: majid
 */

#ifndef INCLUDE_SYSTICK_TIMEBASE_H_
#define INCLUDE_SYSTICK_TIMEBASE_H_

#include "stdint.h"

extern uint64_t global_tick;

#define TIMESTAMP_TO_STRING(time, str, size) do{ \
	time_t rawtime = time/1000; \
	struct tm * timeinfo; \
	timeinfo = localtime(&rawtime); \
	strftime(str,size,"%y/%m/%d %H:%M:%S", timeinfo); \
}while(0);

#ifdef __cplusplus
extern "C" {
#endif

// get milliseconds based on system tick
uint64_t GetTick(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_SYSTICK_TIMEBASE_H_ */
