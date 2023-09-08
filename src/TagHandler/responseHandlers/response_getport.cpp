// =============================================================================
// Arduino-RF-Toolset | Handlers
// =============================================================================

#include "responseHandlers.h"
#include "logging.h"

#include "hardware.h"
#include "tlv.h"
#include "gpiohandler.h"


namespace { uint8_t responseBit; }

/// @brief getPort Handler function
///
/// @param handler The transceiver object
void ResponseHandler::getPort(Transceiver handler)
{
    handler.tlv.read(responseBit);
    if(handler.tlv.readError())
        return;

    if(!responseBit)
        sendGetPort(handler);

    else if(responseBit)
        evaluateGetPort(handler);

    return;
}

// -----------------------------------------------------------------------------

void sendGetPort(Transceiver handler)
{
    TLVResponse response;
    uint8_t port;

    handler.tlv.read(port);

    if(port != (uint8_t)Hardware::Port::RF_RX
        && port != (uint8_t)Hardware::Port::RF_TX)
    {
        response << (responseBit + 1); // response bit
        response << port;
        response << GPIO::getPort((Hardware::Port)port); // get the port level

        handler.respond(response.toString());
    }
    else
    {
        Logging::log("%d: Cannot get port %d", handler.tlv.getSenderAddress(), port);
    }

    return;
}

void evaluateGetPort(Transceiver handler)
{
    uint8_t port;
    uint8_t level;

    handler.tlv.read(port);
    handler.tlv.read(level);

    Logging::log("%d: Port %d is %d", handler.tlv.getSenderAddress(), port, level);

    return;
}