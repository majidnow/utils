#pragma once

#include <cstdint>
#include <memory>

#include "SFrame.h"
#include "ls_config.h"

#define START_BYTE_CAT  0x41
#define START_BYTE_DOG  0x24

#define DEBUG_LS        0

#if DEBUG_LS
typedef struct ppp {
	uint8_t a = 1;
	uint16_t b = 1234;
	uint32_t c = 123456;
	uint16_t d = 4321;
}pp;

static void debug_loop()
{
	pp p{ 1, 123, 123456 };
	uint8_t data[256];
	uint8_t r;
	uint16_t len;
	uint16_t crc;
	for (;;)
	{
		static int ccc = 0;
		ccc++;
		if (ccc == 488)
			LOG(LOG_DEBUG, "time to crc error");
		data[0] = 65;
		data[1] = 36;
		data[2] = (uint8_t)FrameType::FILE_ERROR;
		r = rand() % 20;
		len = sizeof(p) * r;
		memcpy(&data[3], &len, 2);
		for (int i = 0; i < r; i++)
			memcpy(&data[5] + (i * sizeof(p)), &p, sizeof(p));

		//for (int i = 0; i < len + 3; i++)
		//      std::cout << std::hex << (int)data[2 + i] << " ";
		//std::cout << std::endl;

		crc = crcFast(&data[2], len + 3);
		//if ((len == 36 && crc == 32841) || (len == 0 && crc == 3569) || (len == 180 && crc == 3010) ||
		//      (len == 24 && crc == 13890))
		//      LOG(LOG_DEBUG, "time to get crc error");
		memcpy(&data[len + 5], &crc, 2);

		size_t a = lstream->Size();
		if (a >= len + 7)
		{
			memcpy(lstream->Buffer(), data, len + 7);
			lstream->Check(len + 7);
		}
		else
		{
			memcpy(lstream->Buffer(), data, a);
			lstream->Check(a);
			memcpy(lstream->Buffer(), data + a, len + 7 - a);
			lstream->Check(len + 7 - a);
		}
	}
}
#endif

class IFrame
{
public:
	virtual ~IFrame(){}
    virtual void OnFrame(SFrame&) = 0;
};

class LightStream
{
public:
	LightStream(std::shared_ptr<IFrame>);
	uint8_t* Buffer();
	size_t Size();
	void Check(size_t);
	void InitFrame();
	void FrameHeader(FrameType, size_t);
	void PushDataToFrame(uint8_t*,size_t);
	LSBuff* Frame();

private:
	void Reset();
    std::shared_ptr<IFrame> upper;
	SFrame frame;
	uint8_t* rbuffer;
    int rposition;
    LSBuff wbuff;
};

