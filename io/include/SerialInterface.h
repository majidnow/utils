/*
 * SerialInterface.h
 *
 *  Created on: May 7, 2024
 *      Author: majid
 */

#ifndef INCLUDE_SERIALINTERFACE_H_
#define INCLUDE_SERIALINTERFACE_H_

#include "stm32h7xx_hal.h"
#include "cmsis_os2.h"
#include <functional>
#include <system_error>

typedef std::function<void(uint8_t*, size_t)> rx_cb;
typedef std::function<void(std::error_code&, size_t)> tx_cb;

enum SerialTxMode{
	BLOCKING, INTERRUPT, DMA
};

class SerialInterface{
	friend class SerialManager;
public:
	SerialInterface();
	void Transmit(uint8_t*, size_t);
	void Receive();
	UART_HandleTypeDef* uart;
	DMA_HandleTypeDef* rxDMA;
	rx_cb OnRX;
	tx_cb OnTx;
	SerialTxMode txMode;
	uint8_t* rxBuffer;
	size_t rxBufferSize;
private:
	uint32_t CalculateDelay(size_t);
	void TxDone(uint8_t);
	void RxHandle();
	size_t tx_size = 0, rx_size = 0;
	uint32_t rxBufferIndex = 0;
};

#endif /* INCLUDE_SERIALINTERFACE_H_ */
