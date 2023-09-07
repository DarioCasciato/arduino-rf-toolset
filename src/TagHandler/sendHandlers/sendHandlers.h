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

    /// @brief ScanDevices Send Handler function
    void scanDevices(SerialTLV handler);

    /// @brief PingPong Send Handler function
    void PingPong(SerialTLV handler);

    /// @brief sendString Send Handler function
    void sendString(SerialTLV handler);

    /// @brief sendNumber Send Handler function
    void sendNumber(SerialTLV handler);

    /// @brief setPort Send Handler function
    void setPort(SerialTLV handler);

    /// @brief setPort Send Handler function
    void getPort(SerialTLV handler);

} // namespace sendHandler


#endif //ARDUINO_RF_TOOLKIT_TAG_HANDLERS_