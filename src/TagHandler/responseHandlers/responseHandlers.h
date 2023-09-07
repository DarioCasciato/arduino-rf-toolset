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

    /// @brief ScanDevices Tag Handler function
    void scanDevices(Transceiver handler);

    /// @brief PingPong Tag Handler function
    void PingPong(Transceiver handler);

    /// @brief sendNumber Tag Handler function
    void sendString(Transceiver handler);

    /// @brief sendNumber Tag Handler function
    void sendNumber(Transceiver handler);

    /// @brief setPort Tag Handler function
    void setPort(Transceiver handler);

    /// @brief setPort Tag Handler function
    void getPort(Transceiver handler);

} // TagHandler


#endif //ARDUINO_RF_TOOLKIT_TAG_HANDLERS_H