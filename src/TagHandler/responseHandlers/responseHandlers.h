// =============================================================================
// Arduino-RF-Toolkit | Tag-Handlers
// =============================================================================

#ifndef ARDUINO_RF_TOOLKIT_RESPONSE_HANDLERS_H
#define ARDUINO_RF_TOOLKIT_RESPONSE_HANDLERS_H

#include "transceiver.h"

namespace ResponseHandler
{
    /// @brief The resposne handler function
    void responseHandler(Transceiver handler);


    // Handlers

    /// @brief ScanDevices Response Handler function
    void scanDevices(Transceiver handler);

    /// @brief PingPong Response Handler function
    void PingPong(Transceiver handler);

    /// @brief sendNumber Response Handler function
    void sendString(Transceiver handler);

    /// @brief sendNumber Response Handler function
    void sendNumber(Transceiver handler);

    /// @brief setPort Response Handler function
    void setPort(Transceiver handler);

    /// @brief setPort Response Handler function
    void getPort(Transceiver handler);

} // Response Handler


#endif //ARDUINO_RF_TOOLKIT_RESPONSE_HANDLERS_H