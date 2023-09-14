// =============================================================================
// Arduino-RF-Toolset | State
// =============================================================================

#include "state.h"
#include "hardware.h"
#include "configurations.h"
#include "Timer.h"
#include "logging.h"
#include "responseHandlers/responseHandlers.h"
#include "sendHandlers/sendHandlers.h"

//------------------------------------------------------------------------------

namespace State
{
    States state = States::st_app;

    void stateDriver()
    {
        switch (State::state)
        {
        case State::st_app: stateApp(); break;
        case State::st_error: stateError(); break;

        default:    // catch invalid state (implement safety backup)
        goto exception;
            break;
        }

        return;

        exception:
            for(;;) { delay(500); Logging::log("Caught exception"); }
    }

    // State implementations
    void stateApp()
    {
        if(Hardware::transceiver.available())
        {
            ResponseHandler::responseHandler(Hardware::transceiver);
        }

        if(Hardware::serialTLV.getSerialInput())
        {
            SendHandler::sendHandler(Hardware::transceiver, Hardware::serialTLV);
        }
    }

    void stateError()
    {

    }
} // namespace State

//------------------------------------------------------------------------------

// Other Functions