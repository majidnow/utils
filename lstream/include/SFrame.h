/*
 * SFrame.h
 *
 *  Created on: May 8, 2024
 *      Author: majid
 */

#ifndef INCLUDE_SFRAME_H_
#define INCLUDE_SFRAME_H_

#include "LSBuff.h"
#include "LSBaseTypes.h"

class SFrame
{
    friend class LightStream;
public:
	uint8_t* buffer;
	size_t length;
    FrameType type;
    Status status;
private:
    uint8_t step, msg_type;
    uint16_t msg_len, first_piece_len, nread;
};



#endif /* INCLUDE_SFRAME_H_ */
