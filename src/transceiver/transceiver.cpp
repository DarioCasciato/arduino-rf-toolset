// =============================================================================
// Arduino-RF-Toolkit | Transceiver
// =============================================================================

#include "transceiver.h"
#include "tlv.h"
#include "TinyRF_TX.h"
#include "TinyRF_RX.h"

Transceiver::Transceiver(uint16_t deviceAddr, uint8_t rxPin, uint8_t txPin)
{
    deviceAddr_ = deviceAddr;
    rxPin_ = rxPin;
    txPin_ = txPin;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint8_t data)
{
    TLV tlv;
    tlv.createPacket(tag, 0, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    // TODO: Implement TinyRF_TX sending

    return true;
}

bool Transceiver::transmit(uint16_t tag, uint16_t destAddr, uint16_t data)
{
    TLV tlv;
    tlv.createPacket(tag, 0, deviceAddr_, destAddr, String(data));
    String packet = tlv.toString();

    // TODO: Implement TinyRF_TX sending

    return true;
}