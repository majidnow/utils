/*
 * LSBuff.h
 *
 *  Created on: May 8, 2024
 *      Author: majid
 */

#ifndef INCLUDE_LSBUFF_H_
#define INCLUDE_LSBUFF_H_

class LSBuff
{
    friend class LightStream;
public:
    LSBuff(size_t size)
		:
		position(0)
    {
    	ptr = new uint8_t[size];
    }
	uint8_t *End()
	{
		return (ptr+position);
	}
	uint8_t *Buffer()
	{
		return ptr;
	}
	size_t Size()
	{
		return position;
	}
private:
	uint8_t *ptr;
	size_t position;
};




#endif /* INCLUDE_LSBUFF_H_ */
