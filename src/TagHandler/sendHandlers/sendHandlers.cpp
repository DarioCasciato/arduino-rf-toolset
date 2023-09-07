// =============================================================================
// Arduino-RF-Toolkit | Tag-Handlers
// =============================================================================

#include "sendHandlers.h"
#include "tags.h"

namespace SendHandler
{

    void sendHandler(SerialTLV handler)
    {
        Tags::Tag tag = (Tags::Tag)handler.getTag();

        switch (tag)
        {
            case Tags::Tag::ScanDevices:
                break;

            case Tags::Tag::PingPong:
                break;

            case Tags::Tag::SendString:
                break;

            case Tags::Tag::SendNumber:
                break;

            case Tags::Tag::SetPort:
                break;

            case Tags::Tag::GetPort:
                break;

            default:
                break;
        }
    }
} // namespace SendHandler
