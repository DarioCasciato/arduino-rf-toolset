// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "sendHandlers.h"
#include "tags.h"
#include "logging.h"


void SendHandler::setPort(Transceiver sender, SerialTLV handler)
{
    uint16_t destAddr;
    uint8_t port;
    uint8_t state;

    handler.read(destAddr); // read the destination address from tlv packet
    handler.read(port); // read the port from tlv packet
    handler.read(state); // read the state from tlv packet
    if(handler.readError())
        return;

    TLVResponse response;
    response << port;
    response << state;
    sender.transmit((uint16_t)Tags::Tag::SetPort, destAddr, response.toString());

    Logging::log("Setting port %d to %d on %d", port, state, destAddr);

    return;
}