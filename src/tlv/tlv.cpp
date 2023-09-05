// =============================================================================
// Arduino-RF-Toolkit | TLV
// =============================================================================

#include "tlv.h"


//------------------------------------------------------------------------------
// Public methods

TLV::TLVPacket TLV::createPacket(uint16_t tag, uint16_t crc, uint16_t senderAddress, uint16_t receiverAddress, uint8_t* value)
{
    TLV::TLVPacket packet;
    packet.tag = tag;
    packet.length = TLV::getValueSize(value);
    packet.crc = crc;
    packet.senderAddress = senderAddress;
    packet.receiverAddress = receiverAddress;
    packet.value = value;

    return packet;
}

TLV::TLVPacket TLV::parsePacket(char* packet)
{
    TLV::TLVPacket parsedPacket;
    parsedPacket = *(TLV::TLVPacket*)packet;

    return parsedPacket;
}

//------------------------------------------------------------------------------
// Private methods

uint16_t TLV::getValueSize(uint8_t* value)
{
    return sizeof(value);
}

uint16_t TLV::getFullPacketSize(TLV::TLVPacket packet)
{
    uint16_t packetSize = 0;
    packetSize = sizeof(packet);

    return packetSize;
}