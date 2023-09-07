// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "responseHandlers.h"
#include "logging.h"

/// @brief sendString Handler function
///
/// @param handler The transceiver object
void ResponseHandler::sendString(Transceiver handler)
{
    String message;

    handler.tlv.read(message); // read the message from tlv packet
    if(handler.tlv.readError())
        return;

    Logging::log("Message from %d: %s", handler.tlv.getSenderAddress(), message.c_str());

    return;
}