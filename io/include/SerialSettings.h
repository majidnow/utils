/*
 * SerialSettings.h
 *
 *  Created on: May 6, 2024
 *      Author: majid
 */

#ifndef INCLUDE_SERIALSETTINGS_H_
#define INCLUDE_SERIALSETTINGS_H_

struct SerialSettings
{

    /// Defaults to the familiar 9600 8/N/1, no flow control
    SerialSettings()
        : baud(9600),
          dataBits(8),
          stopBits(StopBits::One),
          parity(Parity::None),
          flowType(FlowControl::None)
    {
    }

    /// Baud rate of the port, i.e. 9600 or 57600
    int baud;

    /// Data bits, usually 8
    int dataBits;

    /// Stop bits, usually set to 1
    StopBits stopBits;

    /// Parity setting for the port, usually PAR_NONE
    Parity parity;

    /// Flow control setting, usually FLOW_NONE
    FlowControl flowType;
};




#endif /* INCLUDE_SERIALSETTINGS_H_ */
