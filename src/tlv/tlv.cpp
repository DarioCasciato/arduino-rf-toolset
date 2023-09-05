// =============================================================================
// Arduino-RF-Toolkit | TLV
// =============================================================================

#include "tlv.h"


//------------------------------------------------------------------------------
// Public methods

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

TLV::TLVPacket TLV::parsePacket(char* packet)
{
    TLV::TLVPacket parsedPacket;
    parsedPacket = *(TLV::TLVPacket*)packet;

    return parsedPacket;
}

//------------------------------------------------------------------------------
// Private methods

uint16_t TLV::getFullPacketSize(TLV::TLVPacket packet)
{
    uint16_t packetSize = 0;
    packetSize = sizeof(packet) + packet.length;

    return packetSize;
}