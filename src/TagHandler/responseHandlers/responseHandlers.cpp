// =============================================================================
// Arduino-RF-Toolkit | Tag-Handlers
// =============================================================================

#include "responseHandlers.h"
#include "tags.h"

namespace TagHandler
{

    void tagHandler(Transceiver handler)
    {
        Tags::Tag tag = (Tags::Tag)handler.tlv.getTag();

        switch (tag)
        {
            case Tags::Tag::ScanDevices:
                scanDevices(handler);
                break;

            case Tags::Tag::PingPong:
                PingPong(handler);
                break;

            case Tags::Tag::SendString:
                sendString(handler);
                break;

            case Tags::Tag::SendNumber:
                sendNumber(handler);
                break;

            case Tags::Tag::SetPort:
                setPort(handler);
                break;

            case Tags::Tag::GetPort:
                getPort(handler);
                break;

            default:
                break;
        }

        return;
    }

} // namespace TagHandler
