// =============================================================================
// Arduino-RF-Toolkit | Transceiver
// =============================================================================

#include "transceiver.h"
#include "tlv.h"
#include "TinyRF_TX.h"
#include "TinyRF_RX.h"

#include "conversions.h"
#include "CRC16.h"


Transceiver::Transceiver(uint16_t deviceAddr, uint8_t rxPin, uint8_t txPin)
{
    deviceAddr_ = deviceAddr;
    rxPin_ = rxPin;
    txPin_ = txPin;
}

// -----------------------------------------------------------------------------

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint8_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    // TODO: Implement TinyRF_TX sending

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint16_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    // TODO: Implement TinyRF_TX sending

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint32_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    // TODO: Implement TinyRF_TX sending

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint64_t data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data, sizeof(data));

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, Conversions::uint64ToString(data));
    String packet = tlv.toString();

    // TODO: Implement TinyRF_TX sending

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, String data)
{
    TLV tlv;
    uint16_t crc16 = Security::CRC16::generate((void*)data.c_str(), data.length());

    tlv.createPacket(tag, crc16, deviceAddr_, destAddr, data);
    String packet = tlv.toString();

    // TODO: Implement TinyRF_TX sending

    return true;
}

// -----------------------------------------------------------------------------

