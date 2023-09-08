// =============================================================================
// Arduino-RF-Toolset | Transceiver
// =============================================================================

#include "transceiver.h"
#include "tlv.h"

#include "conversions.h"
#include "CRC16.h"


Transceiver::Transceiver(const uint16_t deviceAddr, uint8_t rxPin, uint8_t txPin)
{
    deviceAddr_ = deviceAddr;
    rxPin_ = rxPin;
    txPin_ = txPin;

    setupReceiver(rxPin_);
    setupTransmitter();
}

// -----------------------------------------------------------------------------

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint8_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    send((uint8_t*)packet.c_str(), packet.length());

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint16_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    send((uint8_t*)packet.c_str(), packet.length());

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint32_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    send((uint8_t*)packet.c_str(), packet.length());

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint64_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, Conversions::uint64ToString(data));
    String packet = tlv.toString();

    send((uint8_t*)packet.c_str(), packet.length());

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, String data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data.c_str(), data.length());

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, data);
    String packet = tlv.toString();

    send((uint8_t*)packet.c_str(), packet.length());

    return true;
}

// -----------------------------------------------------------------------------

bool Transceiver::available()
{
    receiveStatus status = (receiveStatus)getReceivedData(receiveBuffer_,
                                                          (uint8_t)sizeof(receiveBuffer_),
                                                          receivedBytes_);

    // check for transmisssion error
    if(status == receiveStatus::BufOverflow)
    {
        Serial.println("Buffer overflow");
        return false;
    }
    if(status == receiveStatus::noData)
    {
        Serial.println("No data");
        return false;
    }
    if(status == receiveStatus::corrupted)
    {
        Serial.println("Corrupted data");
        return false;
    }

    // save the data to a TLV packet
    tlv.parsePacket((char*)receiveBuffer_, receivedBytes_);

    // check if the packet isn't corrupted
    bool calculatedCrc = Security::CRC16::compare(tlv.getCrc(),
                                                  tlv.getData(),
                                                  tlv.getLength());

    if(!calculatedCrc)
    {
        Serial.println("CRC error");
        return false;
    }

    // check if the packet is for this device
    if(tlv.getReceiverAddress() != deviceAddr_ && tlv.getReceiverAddress() != 0xFFFF)
    {
        Serial.println("Wrong receiver address");
        return false;
    }

    // passed all checks
    return true;
}

// -----------------------------------------------------------------------------

void Transceiver::respond(uint8_t data)
{
    transmit(tlv.getTag(), tlv.getSenderAddress(), data);
}

void Transceiver::respond(uint16_t data)
{
    transmit(tlv.getTag(), tlv.getSenderAddress(), data);
}

void Transceiver::respond(uint32_t data)
{
    transmit(tlv.getTag(), tlv.getSenderAddress(), data);
}

void Transceiver::respond(uint64_t data)
{
    transmit(tlv.getTag(), tlv.getSenderAddress(), data);
}

void Transceiver::respond(String data)
{
    transmit(tlv.getTag(), tlv.getSenderAddress(), data);
}

// -----------------------------------------------------------------------------
