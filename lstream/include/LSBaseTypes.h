/*
 * LSBaseTypes.h
 *
 *  Created on: May 8, 2024
 *      Author: majid
 */

#ifndef INCLUDE_LSBASETYPES_H_
#define INCLUDE_LSBASETYPES_H_

#include <stdint.h>
#include "ls_config.h"

#ifndef LS_USER_DEF_STATUS
enum class Status:uint8_t
{
	OK = 0,
	CRC_ERROR,
	INVALID = 255
};
#endif

#ifndef LS_USER_DEF_FRAME_TYPE
enum class FrameType :uint8_t
{
    PING = 0x00,
    PONG = 0x1F// we using 3 high-bits of type field to show protocol version so we can support 32 types
};
#endif

#endif /* INCLUDE_LSBASETYPES_H_ */
