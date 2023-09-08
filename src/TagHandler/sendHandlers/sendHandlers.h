// =============================================================================
// Arduino-RF-Toolset | Tag-Handlers
// =============================================================================

#ifndef ARDUINO_RF_TOOLKIT_TAG_HANDLERS_
#define ARDUINO_RF_TOOLKIT_TAG_HANDLERS_

#include "transceiver.h"
#include "serial_tlv.h"

namespace SendHandler
{
    /// @brief The send handler function
    void sendHandler(Transceiver sender, SerialTLV handler);

    /// @brief ScanDevices Send Handler function
    void scanDevices(Transceiver sender, SerialTLV handler);

    /// @brief PingPong Send Handler function
    void PingPong(Transceiver sender, SerialTLV handler);

    /// @brief sendString Send Handler function
    void sendString(Transceiver sender, SerialTLV handler);

    /// @brief sendNumber Send Handler function
    void sendNumber(Transceiver sender, SerialTLV handler);

    /// @brief setPort Send Handler function
    void setPort(Transceiver sender, SerialTLV handler);

    /// @brief setPort Send Handler function
    void getPort(Transceiver sender, SerialTLV handler);

} // namespace sendHandler


#endif //ARDUINO_RF_TOOLKIT_TAG_HANDLERS_