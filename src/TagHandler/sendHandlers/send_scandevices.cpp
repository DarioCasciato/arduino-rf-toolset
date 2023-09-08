// =============================================================================
// Arduino-RF-Toolset | Handlers
// =============================================================================

#include "sendHandlers.h"
#include "tags.h"
#include "logging.h"


void SendHandler::scanDevices(Transceiver sender, SerialTLV handler)
{
    uint16_t allDevices = 0xFFFF;
    sender.transmit((uint16_t)Tags::Tag::ScanDevices, allDevices, "");

    Logging::log("Scanning for devices...");

    return;
}