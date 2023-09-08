// =============================================================================
// Arduino-RF-Toolset | Handlers
// =============================================================================

#include "responseHandlers.h"
#include "logging.h"

#include "gpioHandler.h"
#include "hardware.h"

/// @brief setPort Handler function
///
/// @param handler The transceiver object
void ResponseHandler::setPort(Transceiver handler)
{
    uint8_t port;
    uint8_t level;

    handler.tlv.read(port); // read the number from tlv packet
    handler.tlv.read(level);
    if(handler.tlv.readError())
        return;

    if((Hardware::Port)port != Hardware::Port::RF_RX
        && (Hardware::Port)port != Hardware::Port::RF_TX)
    {
        GPIO::setPort((Hardware::Port)port, level);
        Logging::log("%d: Set port %d to %d", handler.tlv.getSenderAddress(), port, level);
    }
    else
    {
        Logging::log("%d: Cannot set port %d", handler.tlv.getSenderAddress(), port);
    }

    return;
}