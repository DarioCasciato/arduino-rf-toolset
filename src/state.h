// =============================================================================
// Arduino-RF-Toolkit | State
// =============================================================================

#ifndef _TEMPLATE_PROJECT_STATE_
#define _TEMPLATE_PROJECT_STATE_

#include "hardware.h"

namespace State
{
    enum States : uint8_t
    {
        st_app,
        st_error
    };

    /// @brief State driver function
    void stateDriver();

    /// @brief Handler for the Idle state
    void stateApp();

    /// @brief Handler for the Error state
    void stateError();
} // namespace State

#endif // _TEMPLATE_PROJECT_STATE_