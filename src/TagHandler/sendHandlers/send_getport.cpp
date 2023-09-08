// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "sendHandlers.h"
#include "tags.h"
#include "logging.h"


void SendHandler::getPort(Transceiver sender, SerialTLV handler)
{
    uint16_t destAddr;
    uint16_t port;

    handler.read(destAddr); // read the destination address from tlv packet
    handler.read(port); // read the port from tlv packet
    if(handler.readError())
        return;

    sender.transmit((uint16_t)Tags::Tag::GetPort, destAddr, port);

    Logging::log("Sending getPort %d to %d", port, destAddr);

    return;
}