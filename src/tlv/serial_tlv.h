// =============================================================================
// Arduino-RF-Toolset | SerialTLV
// =============================================================================

#ifndef SERIAL_TLV_H
#define SERIAL_TLV_H

#include <Arduino.h>

/// @class SerialTLV
///
/// @brief Handles reading and parsing of serial data in TLV (Tag-Length-Value) format.
///
/// The SerialTLV class is designed to facilitate the reading and parsing of data from a serial port
/// in a TLV (Tag-Length-Value) format. The class provides methods to read data into an internal buffer,
/// extract the tag, and read various types of values (uint8_t, uint16_t, uint32_t, uint64_t, and String).
///
/// @par Key Features:
/// - Tag Parsing: Reads a tag as a hexadecimal uint16_t value.
/// - Value Parsing: Supports reading values of types uint8_t, uint16_t, uint32_t, uint64_t, and String.
/// - Error Handling: Provides a method to check if an error occurred during read operations.
/// - Buffer Management: Uses an internal buffer to store incoming serial data for parsing.
///
/// @par Usage:
/// 1. getSerialInput(): Call this method to read available data from the serial port into the internal buffer.
///    Returns true if any data was read.
/// 2. getTag(): After calling getSerialInput(), use this method to extract the tag from the internal buffer.
/// 3. read(): Use these overloaded methods to read the value corresponding to the tag.
///    The value type must match the method's parameter type.
/// 4. readError(): Call this method to check if an error occurred during the read operations.
///
/// @par Data Format:
/// - Tag: Read as a hexadecimal uint16_t value.
/// - Length: Read as a uint16_t value (not explicitly handled in the current implementation).
/// - Value: Read according to the type specified in the read method.
/// - Separator: The tag and value should be separated with ";"
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