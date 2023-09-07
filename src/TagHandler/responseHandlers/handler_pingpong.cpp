// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "TagHandler/tagHandlers.h"
#include "logging.h"

/// @brief PingPong Tag Handler function
/// First sender sends a0 as uint8_t, receiver responses with a 1 as uint8_t
/// @param handler
void TagHandler::PingPong(Transceiver handler)
{
    uint8_t message;
    handler.tlv.read(message); // read the message from tlv packet
    if(handler.tlv.readError())
        return;

    if(message == 0)
    {
        Logging::log("Ping from %d", handler.tlv.getSenderAddress());
        handler.respond((uint8_t)1);
    }
    else if(message == 1)
    {
        Logging::log("Pong from %d", handler.tlv.getSenderAddress());
    }

    return;
}