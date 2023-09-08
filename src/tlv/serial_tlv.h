// =============================================================================
// Arduino-RF-Toolset | SerialTLV
// =============================================================================

#ifndef SERIAL_TLV_H
#define SERIAL_TLV_H

#include <Arduino.h>


class SerialTLV {
public:
  /// @brief Reads serial data into an internal buffer
  ///
  /// This method reads available data from the serial port and stores it in an internal buffer.
  /// @return true if any data was read, otherwise false
  bool getSerialInput();

  /// @brief Returns the tag field from the internal buffer
  ///
  /// This method extracts the tag (first uint16_t) from the internal buffer and returns it.
  /// @return The tag as a uint16_t
  uint16_t getTag();

  /// @brief Reads a uint8_t value from the internal buffer
  /// @param value The variable to store the read uint8_t value
  void read(uint8_t& value);

  /// @brief Reads a uint16_t value from the internal buffer
  /// @param value The variable to store the read uint16_t value
  void read(uint16_t& value);

  /// @brief Reads a uint32_t value from the internal buffer
  /// @param value The variable to store the read uint32_t value
  void read(uint32_t& value);

  /// @brief Reads a uint64_t value from the internal buffer
  /// @param value The variable to store the read uint64_t value
  void read(uint64_t& value);

  /// @brief Reads a string value from the internal buffer
  /// @param value The variable to store the read string value
  void read(String& value);

  /// @brief Returns the error status for the read operations
  /// @return 1 if an error occurred, otherwise 0
  uint8_t readError();

private:
  uint8_t buffer_[255];
  uint8_t *reader = buffer_;
  uint8_t error_ = 0;
};

#endif // SERIAL_TLV_H