// =============================================================================
// Arduino-RF-Toolkit | Transceiver
// =============================================================================

#ifndef ARDUINO_RF_TOOLKIT_TRANSCEIVER_H
#define ARDUINO_RF_TOOLKIT_TRANSCEIVER_H

#include <stdint.h>
#include "tlv.h"

class Transceiver
{
public:
    Transceiver(uint16_t deviceAddr, uint8_t rxPin, uint8_t txPin);

    /// @brief Transmits a TLV packet
    ///
    /// @param tag The tag of the TLV packet
    /// @param destAddr The destination address of the TLV packet
    /// @param data The data of the TLV packet
    /// @return True if the transmission was successful, false if not
    bool transmit(uint16_t tag, uint16_t destAddr, uint8_t data);

    /// @brief Transmits a TLV packet
    ///
    /// @param tag The tag of the TLV packet
    /// @param destAddr The destination address of the TLV packet
    /// @param data The data of the TLV packet
    /// @return True if the transmission was successful, false if not
    bool transmit(uint16_t tag, uint16_t destAddr, uint16_t data);

    /// @brief Transmits a TLV packet
    ///
    /// @param tag The tag of the TLV packet
    /// @param destAddr The destination address of the TLV packet
    /// @param data The data of the TLV packet
    /// @return True if the transmission was successful, false if not
    bool transmit(uint16_t tag, uint16_t destAddr, uint32_t data);

    /// @brief Transmits a TLV packet
    ///
    /// @param tag The tag of the TLV packet
    /// @param destAddr The destination address of the TLV packet
    /// @param data The data of the TLV packet
    /// @return True if the transmission was successful, false if not
    bool transmit(uint16_t tag, uint16_t destAddr, uint64_t data);

    /// @brief Transmits a TLV packet
    ///
    /// @param tag The tag of the TLV packet
    /// @param destAddr The destination address of the TLV packet
    /// @param data The data of the TLV packet
    /// @return True if the transmission was successful, false if not
    bool transmit(uint16_t tag, uint16_t destAddr, String data);

    // Receive functions

private:
    uint16_t deviceAddr_;
    uint8_t rxPin_;
    uint8_t txPin_;


};


#endif //ARDUINO_RF_TOOLKIT_TRANSCEIVER_H