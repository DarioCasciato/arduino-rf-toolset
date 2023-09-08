// =============================================================================
// Arduino-RF-Toolset | Handlers
// =============================================================================

#include "sendHandlers.h"
#include "tags.h"
#include "logging.h"


void SendHandler::PingPong(Transceiver sender, SerialTLV handler)
{
    uint16_t destAddr;
    handler.read(destAddr); // read the destination address from tlv packet
    if(handler.readError())
        return;

    sender.transmit((uint16_t)Tags::Tag::PingPong, destAddr, (uint8_t)0);

    Logging::log("Ping to %d", destAddr);

    return;
}