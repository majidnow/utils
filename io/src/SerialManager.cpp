/*
 * Serial.cpp
 *
 *  Created on: May 6, 2024
 *      Author: majid
 */

#include <SerialManager.h>
#include "globals.h"

#if SERIAL_USE_THREAD
#define EVENT_TX		0x10
#define EVENT_RX		0x20

const osMessageQueueAttr_t rxtxEventQueue_attributes = {
  .name = "rxtxEventQueue"
};

const osThreadAttr_t rxtxEvent_attributes = {
	.name = "rxtx_event",
	.stack_size = 1024 * 8,
	.priority = (osPriority_t) osPriorityNormal
};

#endif

std::vector<SerialInterface*> SerialManager::interfaces;
osMessageQueueId_t SerialManager::rxtxEventQueueHandle;

void SerialManager::Start()
{
#if SERIAL_USE_THREAD
	rxtxEventQueueHandle = osMessageQueueNew (4, sizeof(uint8_t), &rxtxEventQueue_attributes);
	if (rxtxEventQueueHandle == 0)  // Queue not created
	{
		LOG(LOG_SYSTEM, "Error in create serial message queue");
	}
	else
	{
		LOG(LOG_SYSTEM, "Serial message queue created");
	}

	if(osThreadNew(Task, this, &rxtxEvent_attributes))
		LOG(LOG_SYSTEM, "Serial started")
	else
		LOG(LOG_SYSTEM, "Serial thread failed to start");

#else
#endif
}

void SerialManager::Add(SerialInterface* handler)
{
	if(interfaces.size() == 16)
		return;

	interfaces.push_back(handler);
}

void SerialManager::TxCallback(UART_HandleTypeDef *huart)
{
	//	LOG(LOG_DEBUG, "elapsed(%lu)", (uint32_t)(GetTick()-global.start));
	for(uint8_t i = 0; i < SerialManager::interfaces.size(); i++)
	{
		SerialInterface* interface = SerialManager::interfaces[i];
		if(interface->uart->Instance == huart->Instance)
		{
#if SERIAL_USE_THREAD
			uint8_t e = EVENT_TX | i;
			osMessageQueuePut(rxtxEventQueueHandle, &e, 0, 0U);
#else
			interface->TxDone(0);
#endif
			break;
		}
	}
}

void SerialManager::RxCallback(UART_HandleTypeDef *huart, uint16_t nread)
{
	for(uint8_t i = 0; i < SerialManager::interfaces.size(); i++)
	{
		SerialInterface* interface = SerialManager::interfaces[i];
#if SERIAL_USE_THREAD
		interface->rx_size = nread;
		uint8_t e = EVENT_RX | i;
		osMessageQueuePut(rxtxEventQueueHandle, &e, 0, 0U);
#else
#endif
		break;
	}
}

void SerialManager::Task(void *arg)
{
	SerialManager* self = static_cast<SerialManager*>(arg);
	self->Run();
}

void SerialManager::Run()
{
	osStatus_t status;
	uint8_t e;
	while (1)
	{
		// wait for message
		status = osMessageQueueGet(rxtxEventQueueHandle, &e, NULL, osWaitForever);
		uint8_t event = e & 0xF0;
		uint8_t index = e & 0x0F;
		SerialInterface* interface = SerialManager::interfaces[index];
		if (status == osOK)
		{
			if(event == EVENT_TX)
			{
				interface->TxDone(0);
			}
			else if(event == EVENT_RX)
			{
				interface->RxHandle();
			}
		}
	}
}
