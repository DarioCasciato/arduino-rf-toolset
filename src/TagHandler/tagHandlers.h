// =============================================================================
// Arduino-RF-Toolkit | Tag-Handlers
// =============================================================================

#ifndef ARDUINO_RF_TOOLKIT_TAG_HANDLERS_H
#define ARDUINO_RF_TOOLKIT_TAG_HANDLERS_H

#include "transceiver.h"

namespace TagHandler
{
    /// @brief The tag handler function
    void tagHandler(Transceiver handler);


    // Handlers

    /// @brief PingPong Tag Handler function
    void PingPong(Transceiver handler);


} // TagHandler


#endif //ARDUINO_RF_TOOLKIT_TAG_HANDLERS_H