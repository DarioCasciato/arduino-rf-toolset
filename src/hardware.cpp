// =============================================================================
// Arduino-RF-Toolset | Hardware
// =============================================================================

#include <Arduino.h>
#include "hardware.h"
#include "configurations.h"

namespace Hardware
{
    // Constructor for transceiver
    Transceiver transceiver(DeviceAddress, (uint8_t) Port::RF_RX, (uint8_t) Port::RF_TX);

    SerialTLV serialTLV;

    void init()
    {

    }

    void updateHardware()
    {

    }
} // namespace Hardware