/*
 * systick_timebase.c
 *
 *  Created on: Mar 12, 2023
 *      Author: majid
 */
#include "systick_timebase.h"

uint64_t global_tick = 0;

uint64_t GetTick(void)
{
	return global_tick;
}

