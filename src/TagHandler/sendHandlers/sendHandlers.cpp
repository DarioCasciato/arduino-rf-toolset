// =============================================================================
// Arduino-RF-Toolset | Tag-Handlers
// =============================================================================

#include "transceiver.h"
#include "sendHandlers.h"
#include "tags.h"

namespace SendHandler
{

    void sendHandler(Transceiver sender, SerialTLV handler)
    {
        Tags::Tag tag = (Tags::Tag)handler.getTag();

        switch (tag)
        {
            case Tags::Tag::ScanDevices:
                scanDevices(sender, handler);
                break;

            case Tags::Tag::PingPong:
                PingPong(sender, handler);
                break;

            case Tags::Tag::SendString:
                sendString(sender, handler);
                break;

            case Tags::Tag::SendNumber:
                sendNumber(sender, handler);
                break;

            case Tags::Tag::SetPort:
                setPort(sender, handler);
                break;

            case Tags::Tag::GetPort:
                getPort(sender, handler);
                break;

            default:
                break;
        }
    }
} // namespace SendHandler
