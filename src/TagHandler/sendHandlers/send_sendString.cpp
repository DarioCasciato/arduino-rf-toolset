// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "sendHandlers.h"
#include "tags.h"
#include "logging.h"


void SendHandler::sendString(Transceiver sender, SerialTLV handler)
{
    uint16_t destAddr;
    String message;

    handler.read(destAddr); // read the destination address from tlv packet
    handler.read(message); // read the string from tlv packet
    if(handler.readError())
        return;

    sender.transmit((uint16_t)Tags::Tag::SendString, destAddr, message);

    Logging::log("Sending %s to %d", message, destAddr);

    return;
}