// =============================================================================
// Arduino-RF-Toolset | TLV
// =============================================================================

#include "tlv.h"

//------------------------------------------------------------------------------
// Public methods

TLV::TLV()
{
}

TLV::~TLV()
{
    delete[] dataBuffer_;
}

void TLV::createPacket(uint16_t tag, uint16_t crc, uint16_t senderAddress, uint16_t receiverAddress, String data)
{
    TLV::TLVPacket packet;
    packet.tag = tag;
    packet.length = data.length();
    packet.crc = crc;
    packet.senderAddress = senderAddress;
    packet.receiverAddress = receiverAddress;
    packet.data = data.c_str();

    packet_ = packet;
}

String TLV::toString()
{
    String packetString = "";
    packetString += packet_.tag;
    packetString += packet_.length;
    packetString += packet_.crc;
    packetString += packet_.senderAddress;
    packetString += packet_.receiverAddress;
    packetString += String(packet_.data);

    return packetString;
}

TLV::TLVPacket TLV::parsePacket(char* packet, uint16_t packetSize)
{
    TLVPacket parsedPacket;

    parsedPacket.tag = (uint16_t(packet[0]) << 8) | uint8_t(packet[1]);
    parsedPacket.length = (uint16_t(packet[2]) << 8) | uint8_t(packet[3]);
    parsedPacket.crc = (uint16_t(packet[4]) << 8) | uint8_t(packet[5]);
    parsedPacket.senderAddress = (uint16_t(packet[6]) << 8) | uint8_t(packet[7]);
    parsedPacket.receiverAddress = (uint16_t(packet[8]) << 8) | uint8_t(packet[9]);

    // Delete any existing data
    delete[] dataBuffer_;

    // Allocate new space for data
    dataBuffer_ = new char[parsedPacket.length];

    // Copy the data
    memcpy(dataBuffer_, packet + 10, parsedPacket.length);

    // Point the data in the parsed packet to the new buffer
    parsedPacket.data = dataBuffer_;
    reader = dataBuffer_;
    error_ = 0;

    return parsedPacket;
}

// -----------------------------------------------------------------------------

uint16_t TLV::getTag()
{
    return packet_.tag;
}

uint16_t TLV::getLength()
{
    return packet_.length;
}

uint16_t TLV::getCrc()
{
    return packet_.crc;
}

uint16_t TLV::getSenderAddress()
{
    return packet_.senderAddress;
}

uint16_t TLV::getReceiverAddress()
{
    return packet_.receiverAddress;
}

// -----------------------------------------------------------------------------

void TLV::read(uint8_t& value)
{
    if((0 == error_) && (reader < dataBuffer_ + packet_.length))
    {
        value = *(uint8_t*)reader;
        reader = (uint8_t*)reader + 1;
    }
    else
        error_ = 1;
}

void TLV::read(uint16_t& value)
{
    if((0 == error_) && (reader < dataBuffer_ + packet_.length))
    {
        value = *(uint16_t*)reader;
        reader = (uint16_t*)reader + 1;
    }
    else
        error_ = 1;
}

void TLV::read(uint32_t& value)
{
    if((0 == error_) && (reader < dataBuffer_ + packet_.length))
    {
        value = *(uint32_t*)reader;
        reader = (uint32_t*)reader + 1;
    }
    else
        error_ = 1;
}

void TLV::read(uint64_t& value)
{
    if((0 == error_) && (reader < dataBuffer_ + packet_.length))
    {
        value = *(uint64_t*)reader;
        reader = (uint64_t*)reader + 1;
    }
    else
        error_ = 1;
}

void TLV::read(String& value)
{
    if((0 == error_) && (reader < dataBuffer_ + packet_.length))
    {
        value = String((char*)reader);
        reader = (char*)reader + value.length();
    }
    else
        error_ = 1;
}

uint8_t TLV::readError()
{
    return error_;
}

//------------------------------------------------------------------------------
// Private methods

uint16_t TLV::getFullPacketSize(TLV::TLVPacket packet)
{
    uint16_t packetSize = 0;
    packetSize = sizeof(packet.tag) + sizeof(packet.length) + sizeof(packet.crc) + sizeof(packet.senderAddress) + sizeof(packet.receiverAddress) + packet.length;

    return packetSize;
}


// =============================================================================

// TLVResponse

TLVResponse::TLVResponse()
{
}

String TLVResponse::toString()
{
    String responseString = "";
    for(uint8_t i = 0; i < index_; i++)
    {
        responseString += response_[i];
    }

    return responseString;
}

void TLVResponse::append(uint8_t value)
{
    response_[index_] = value;
    index_++;
}

void TLVResponse::append(uint16_t value)
{
    append(uint8_t(value >> 8));
    append(uint8_t(value));
}

void TLVResponse::append(uint32_t value)
{
    append(uint8_t(value >> 24));
    append(uint8_t(value >> 16));
    append(uint8_t(value >> 8));
    append(uint8_t(value));
}

void TLVResponse::append(uint64_t value)
{
    append(uint8_t(value >> 56));
    append(uint8_t(value >> 48));
    append(uint8_t(value >> 40));
    append(uint8_t(value >> 32));
    append(uint8_t(value >> 24));
    append(uint8_t(value >> 16));
    append(uint8_t(value >> 8));
    append(uint8_t(value));
}

void TLVResponse::append(String value)
{
    for(uint8_t i = 0; i < value.length(); i++)
    {
        append((uint8_t)value[i]);
    }
}

void TLVResponse::append(bool value)
{
    append((uint8_t)value);
}

void TLVResponse::append(int value)
{
    append((uint32_t)value);
}
