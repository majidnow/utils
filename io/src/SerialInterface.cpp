/*
 * SerialInterface.cpp
 *
 *  Created on: May 7, 2024
 *      Author: majid
 */

#include <SerialInterface.h>
#include <globals.h>

SerialInterface::SerialInterface()
:
	txMode(SerialTxMode::BLOCKING)
{
}

void SerialInterface::Transmit(uint8_t* buffer, size_t size)
{
//	LOG(LOG_DEBUG, "delay(%lu)", CalculateDelay(size));
	tx_size = size;
	switch(txMode)
	{
	case SerialTxMode::BLOCKING:
	{
		uint8_t result = HAL_UART_Transmit(uart, buffer, size, CalculateDelay(size));
		TxDone(result);
		break;
	}
	case SerialTxMode::INTERRUPT:
		HAL_UART_Transmit_IT(uart, buffer, size);
		break;
	case SerialTxMode::DMA:
		HAL_UART_Transmit_DMA(uart, buffer, size);
		break;
	default:
		break;
	}
}

void SerialInterface::Receive()
{
	HAL_UARTEx_ReceiveToIdle_DMA(uart, rxBuffer, rxBufferSize);
	__HAL_DMA_DISABLE_IT(rxDMA, DMA_IT_HT);
	// TODO implement other receive methods
}

uint32_t SerialInterface::CalculateDelay(size_t data_size)
{
	// frame = WordLength + StartBits + StopBits + Parity
	// for 8N1 => frame = 8 + 1 + 1 + 0 = 10
	float baudrate_in_ms = uart->Init.BaudRate/1000.0f;
	uint32_t data_size_in_bits = data_size * 10;
	return (data_size_in_bits/baudrate_in_ms)+20;
}

void SerialInterface::TxDone(uint8_t status)
{
	std::error_code ec(status, std::generic_category());
	OnTx(ec, tx_size);
}

void SerialInterface::RxHandle()
{
	if(rxDMA && rxDMA->Init.Mode == DMA_CIRCULAR)
	{
		if (rx_size != rxBufferIndex)
		{
			if (rx_size > rxBufferIndex)
				OnRX(&rxBuffer[rxBufferIndex], rx_size - rxBufferIndex);
			else
			{
				OnRX(&rxBuffer[rxBufferIndex], rxBufferSize - rxBufferIndex);
				if (rx_size > 0)
					OnRX(&rxBuffer[0], rx_size);
			}

			rxBufferIndex = rx_size;

			if (rxBufferIndex == rxBufferSize)
				rxBufferIndex = 0;
		}
	}
	else
	{
		OnRX(rxBuffer, rx_size);
		Receive();
	}
}


