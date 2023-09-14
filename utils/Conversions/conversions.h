// =============================================================================
// Utils | Conversions
// =============================================================================

#ifndef UTILS_CONVERSIONS_
#define UTILS_CONVERSIONS_

#include <Arduino.h>

namespace Conversions
{
    /// @brief Converts a uint64_t to a String
    ///
    /// @param num The uint64_t to convert
    /// @return String The converted String
    String uint64ToString(uint64_t num);
} // namespace Con


#endif // UTILS_CONVERSIONS_