// =============================================================================
// Arduino-RF-Toolkit | Hardware
// =============================================================================

#ifndef _TEMPLATE_PROJECT_HARDWARE_
#define _TEMPLATE_PROJECT_HARDWARE_

#include "EdgeDetection.h"
#include "configurations.h"
#include "gpio.h"
#include "transceiver.h"


namespace Hardware
{
    // Example entries
    enum class Port : uint8_t
    {
        RF_TX = 0,
        RF_RX = 1
    };

    extern Transceiver transceiver;


    /// @brief Initializes hardware
    void init();

    /// @brief Fetches hardware values
    void updateHardware();
} // namespace Hardware


#endif // _TEMPLATE_PROJECT_HARDWARE_