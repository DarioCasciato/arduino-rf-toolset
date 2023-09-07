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

    /// @brief Constructor
    TLV();

    /// @brief Destructor
    ~TLV();

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
    TLVPacket parsePacket(char* packet, uint16_t packetSize);

    /// @brief Returns the tag of the packet
    ///
    /// @return The tag of the packet
    uint16_t getTag();

    /// @brief Returns the length of the packet
    ///
    /// @return The length of the packet
    uint16_t getLength();

    /// @brief Returns the crc of the packet
    ///
    /// @return The crc of the packet
    uint16_t getCrc();

    /// @brief Returns the sender address of the packet
    ///
    /// @return The sender address of the packet
    uint16_t getSenderAddress();

    /// @brief Returns the receiver address of the packet
    ///
    /// @return The receiver address of the packet
    uint16_t getReceiverAddress();

    /// @brief Returns the data of the packet
    ///
    /// @return The data of the packet
    void* getData();

    /// @ save the data to passed variable
    /// @param value The value that needs to be saved
    void read(uint8_t& value);
    void read(uint16_t& value);
    void read(uint32_t& value);
    void read(uint64_t& value);
    void read(String& value);

    /// @brief Returns if error occured
    ///
    /// @return If error occured
    uint8_t readError();

private:

    /// @brief Calculates the full size of the packet
    /// @param packet The packet that needs to be calculated
    /// @return The full size of the packet
    uint16_t TLV::getFullPacketSize(TLVPacket packet);

    TLVPacket packet_;
    char* dataBuffer_;
    void* reader;
    uint8_t error_;
};


class TLVResponse
{
private:
    uint8_t response_[255];
    uint8_t index_ = 0;

    void append(uint8_t value);
    void append(uint16_t value);
    void append(uint32_t value);
    void append(uint64_t value);
    void append(String value);

public:
    /// @brief Constructor
    TLVResponse();

    /// @brief Destructor
    ~TLVResponse();

    template <typename T>
    TLVResponse operator<<(T value)
    {
        append(value);
        return *this;
    }

    /// @brief Returns the response as a Arduino String
    ///
    /// @return The response as a Arduino String
    String toString();
};