// =============================================================================
// Arduino-RF-Toolkit | Tags
// =============================================================================

#ifndef ARDUINO_RF_TOOLKIT_TAGS_H
#define ARDUINO_RF_TOOLKIT_TAGS_H

#include <stdint.h>

namespace Tags
{
    enum class Tag : uint16_t
    {
        ScanDevices = 0x0100,
        PingPong = 0x0101,
        SendString = 0x0102,
        SendNumber = 0x0103,
        SetPort = 0x0104,
        GetPort = 0x0105
    };
} // Tags

#endif //ARDUINO_RF_TOOLKIT_TAGS_H