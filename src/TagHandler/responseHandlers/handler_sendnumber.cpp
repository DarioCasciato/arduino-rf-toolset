// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "responseHandlers.h"
#include "logging.h"

/// @brief sendNumber Handler function
///
/// @param handler The transceiver object
void TagHandler::sendNumber(Transceiver handler)
{
    uint64_t number;

    handler.tlv.read(number); // read the number from tlv packet
    if(handler.tlv.readError())
        return;

    Logging::log("Number from %d: %d", handler.tlv.getSenderAddress(), number);

    return;
}