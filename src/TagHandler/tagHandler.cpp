// =============================================================================
// Arduino-RF-Toolkit | Tag-Handlers
// =============================================================================

#include "tagHandlers.h"
#include "tags.h"

namespace TagHandler
{

    void tagHandler(Transceiver handler)
    {
        Tags::Tag tag = (Tags::Tag)handler.tlv.getTag();

        switch (tag)
        {
            case Tags::Tag::PingPong:
                PingPong(handler);
                break;

            default:
                break;
        }

        return;
    }

} // namespace TagHandler
