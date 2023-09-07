// =============================================================================
// Arduino-RF-Toolkit | Transceiver
// =============================================================================

#ifndef ARDUINO_RF_TOOLKIT_TRANSCEIVER_H
#define ARDUINO_RF_TOOLKIT_TRANSCEIVER_H

#include <stdint.h>
#include "tlv.h"
#include "TinyRF_TX.h"
#include "TinyRF_RX.h"

class Transceiver
{
public:

    enum class receiveStatus : uint8_t
    {
        noData = TRF_ERR_NO_DATA,
        BufOverflow = TRF_ERR_BUFFER_OVERFLOW,
        corrupted = TRF_ERR_CORRUPTED,
        success = TRF_ERR_SUCCESS
    };

    TLV tlv;

    /// @brief Constructor
    ///
    /// @param deviceAddr The address of the device
    /// @param rxPin The pin that is connected to the receiver
    /// @param txPin The pin that is connected to the transmitter
    Transceiver(const uint16_t deviceAddr, uint8_t rxPin, uint8_t txPin);

    /// @brief  Get the device address
    ///
    /// @return The device address
    uint16_t getDeviceAddr() { return deviceAddr_; }

    /// @brief Transmits a TLV packet
    ///
    /// @param tag The tag of the TLV packet
    /// @param destAddr The destination address of the TLV packet
    /// @param data The data of the TLV packet
    /// @return True if the transmission was successful, false if not
    bool transmit(uint16_t tag, uint16_t destAddr, uint8_t data);
    bool transmit(uint16_t tag, uint16_t destAddr, uint16_t data);
    bool transmit(uint16_t tag, uint16_t destAddr, uint32_t data);
    bool transmit(uint16_t tag, uint16_t destAddr, uint64_t data);
    bool transmit(uint16_t tag, uint16_t destAddr, String data);


    // Receive functions

    /// @brief Checks if there is data available
    ///
    /// @return True if there is data available, false if not
    bool available();

    /// @brief Responds to a received TLV packet
    ///
    /// @param destAddr The destination address of the response
    /// @param data The data of the response
    void respond(uint8_t data);
    void respond(uint16_t data);
    void respond(uint32_t data);
    void respond(uint64_t data);
    void respond(String data);

private:
    uint16_t deviceAddr_;
    uint8_t rxPin_;
    uint8_t txPin_;
    byte receiveBuffer_[255];
    uint8_t receivedBytes_;


};


#endif //ARDUINO_RF_TOOLKIT_TRANSCEIVER_H
