// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "responseHandlers.h"
#include "logging.h"

#include "gpioHandler.h"
#include "hardware.h"

/// @brief getPort Handler function
///
/// @param handler The transceiver object
void TagHandler::getPort(Transceiver handler)
{
    uint8_t port;

    handler.tlv.read(port); // read the number from tlv packet
    if(handler.tlv.readError())
        return;

    if((Hardware::Port)port != Hardware::Port::RF_RX
        && (Hardware::Port)port != Hardware::Port::RF_TX)
    {
        uint8_t level = GPIO::getPort((Hardware::Port)port);
        handler.respond(level);
        Logging::log("%d: Get port %d: %d", handler.tlv.getSenderAddress(), port, level);
    }
    else
    {
        Logging::log("%d: Cannot get port %d", handler.tlv.getSenderAddress(), port);
    }

    return;
}