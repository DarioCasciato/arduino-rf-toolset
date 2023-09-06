// =============================================================================
// Arduino-RF-Toolkit | State
// =============================================================================

#include "state.h"
#include "hardware.h"
#include "configurations.h"
#include "Timer.h"
#include "TagHandler/tagHandlers.h"

Timer counter;

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
            for(;;) {}
    }

    // State implementations
    void stateApp()
    {
        if(Hardware::transceiver.available())
        {
            TagHandler::tagHandler(Hardware::transceiver);
        }
    }

    void stateError()
    {

    }
} // namespace State

//------------------------------------------------------------------------------

// Other Functions