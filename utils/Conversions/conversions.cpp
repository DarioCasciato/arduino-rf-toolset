// =============================================================================
// Utils | Conversions
// =============================================================================

#include "conversions.h"
#include <Arduino.h>

namespace Conversions
{

String uint64ToString(uint64_t num)
{
  String str = "";
  do
  {
    char digit = char(num % 10) + '0';
    str = digit + str;
    num /= 10;
  } while (num > 0);
  return str;
}

} // namespace Conversions