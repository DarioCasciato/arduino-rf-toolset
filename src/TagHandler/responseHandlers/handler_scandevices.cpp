// =============================================================================
// Arduino-RF-Toolkit | Handlers
// =============================================================================

#include "TagHandler/tagHandlers.h"
#include "logging.h"


/// @brief scanDevices Tag Handler function
///
/// @param handler The transceiver object
void TagHandler::scanDevices(Transceiver handler)
{
    uint16_t receiverAddr = handler.tlv.getReceiverAddress();

    if(receiverAddr == handler.getDeviceAddr())
    {
        Logging::log("Found Device: %x", handler.tlv.getSenderAddress());
    }
    else if(receiverAddr == 0xFFFF)
    {
        // Scale the 16-bit address to a delay between 0 and 50,000 microseconds.
        // uint16_t max value is 65535.
        // (50000.0 / 65535.0) * receiverAddr will scale it to 0-50000.
        uint16_t delayTimeMicroseconds = (uint16_t)((50000.0 / 65535.0) * receiverAddr);
        delayMicroseconds(delayTimeMicroseconds);

        handler.respond("");
    }

    return;
}