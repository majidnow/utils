/*
 * Serial.h
 *
 *  Created on: May 6, 2024
 *      Author: majid
 */

#ifndef INCLUDE_SERIALMANAGER_H_
#define INCLUDE_SERIALMANAGER_H_

#include "stm32h7xx_hal.h"
#include "cmsis_os2.h"
#include <vector>

#include "SerialInterface.h"

#define SERIAL_USE_THREAD		1

class SerialManager {
public:
	void Start();

	static void Add(SerialInterface*);
	static void TxCallback(UART_HandleTypeDef *huart);
	static void RxCallback(UART_HandleTypeDef *huart, uint16_t nread);
private:
	static void Task(void *arg);
	void Run();
	static osMessageQueueId_t rxtxEventQueueHandle;
	static std::vector<SerialInterface*> interfaces;
};

#endif /* INCLUDE_SERIALMANAGER_H_ */
