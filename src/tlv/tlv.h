// =============================================================================
// Arduino-RF-Toolkit | TLV
// =============================================================================

#include <Arduino.h>
#include <stdint.h>


class TLV
{
public:
    struct TLVPacket
    {
        uint16_t tag;
        uint16_t length;
        uint16_t crc;
        uint16_t senderAddress;
        uint16_t receiverAddress;
        const char* data;
    };

    /// @brief Creates a TLV packet
    ///
    /// @param tag The tag of the TLV packet
    /// @param crc The crc of the TLV packet
    /// @param senderAddress The sender address of the TLV packet
    /// @param receiverAddress The receiver address of the TLV packet
    /// @param data The data of the TLV packet
    void TLV::createPacket(uint16_t tag, uint16_t crc, uint16_t senderAddress,
                                     uint16_t receiverAddress, String data);

    /// @brief Returns the packet as a Arduino String
    ///
    /// @return The packet as a Arduino String
    String toString();

    // create a parse tlv packet function
    /// @brief Parses a TLV packet
    ///
    /// @param packet The packet that needs to be parsed
    /// @return The parsed TLV packet
    TLVPacket parsePacket(char* packet);

private:

    /// @brief Calculates the full size of the packet
    /// @param packet The packet that needs to be calculated
    /// @return The full size of the packet
    uint16_t TLV::getFullPacketSize(TLVPacket packet);

    TLVPacket packet_;
};
