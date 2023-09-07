// =============================================================================
// Arduino-RF-Toolkit | Tag-Handlers
// =============================================================================

#ifndef ARDUINO_RF_TOOLKIT_TAG_HANDLERS_
#define ARDUINO_RF_TOOLKIT_TAG_HANDLERS_

#include "transceiver.h"
#include "serial_tlv.h"

namespace SendHandler
{
    /// @brief The send handler function
    void sendHandler(SerialTLV handler);

} // namespace sendHandler


#endif //ARDUINO_RF_TOOLKIT_TAG_HANDLERS_