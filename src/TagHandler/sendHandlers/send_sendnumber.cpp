// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "sendHandlers.h"
#include "tags.h"
#include "logging.h"


void SendHandler::sendNumber(Transceiver sender, SerialTLV handler)
{
    uint16_t destAddr;
    uint64_t number;

    handler.read(destAddr); // read the destination address from tlv packet
    handler.read(number); // read the number from tlv packet
    if(handler.readError())
        return;

    sender.transmit((uint16_t)Tags::Tag::SendNumber, destAddr, number);

    Logging::log("Sending %d to %d", number, destAddr);

    return;
}