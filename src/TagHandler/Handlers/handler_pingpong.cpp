// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "TagHandler/tagHandlers.h"

/// @brief PingPong Tag Handler function
/// First sender sends a0 as uint8_t, receiver responses with a 1 as uint8_t
/// @param handler
void TagHandler::PingPong(Transceiver handler)
{
    uint8_t pingPong;

    handler.tlv.read(pingPong); // read the pingPong value from tlv packet

    if(0 == pingPong)
        handler.respond(pingPong++);

    return;
}