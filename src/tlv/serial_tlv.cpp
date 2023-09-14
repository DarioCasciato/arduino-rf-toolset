// =============================================================================
// Arduino-RF-Toolset | SerialTLV
// =============================================================================

#include "serial_tlv.h"


bool SerialTLV::getSerialInput()
{
    if (Serial.available() > 0)
    {
        size_t bytesRead = Serial.readBytes(buffer_, sizeof(buffer_));
        if (bytesRead > 0)
        {
            reader = buffer_ + 3; // skip tag and separator ( ; )
            return true;
        }
    }
    return false;
}

uint16_t SerialTLV::getTag()
{
    return (uint16_t)buffer_[0] << 8 | buffer_[1];
}

void SerialTLV::read(uint8_t& value)
{
    if (reader < buffer_ + sizeof(buffer_))
    {
        value = *reader++;
    }
    else
    {
        error_ = 1;
    }
}

void SerialTLV::read(uint16_t& value)
{
    if (reader + 1 < buffer_ + sizeof(buffer_))
    {
        value = (uint16_t)reader[0] << 8 | reader[1];
        reader += 2;
    }
    else
    {
        error_ = 1;
    }
}

void SerialTLV::read(uint32_t& value)
{
    if (reader + 3 < buffer_ + sizeof(buffer_))
    {
        value = (uint32_t)reader[0] << 24 | (uint32_t)reader[1] << 16 |
                (uint32_t)reader[2] << 8 | reader[3];
        reader += 4;
    }
    else
    {
        error_ = 1;
    }
}

void SerialTLV::read(uint64_t& value)
{
    if (reader + 7 < buffer_ + sizeof(buffer_))
    {
        value = (uint64_t)reader[0] << 56 | (uint64_t)reader[1] << 48 |
                (uint64_t)reader[2] << 40 | (uint64_t)reader[3] << 32 |
                (uint64_t)reader[4] << 24 | (uint64_t)reader[5] << 16 |
                (uint64_t)reader[6] << 8 | reader[7];

        reader += 8;
    }
    else
    {
        error_ = 1;
    }
}

void SerialTLV::read(String& value)
{
    char str[64];
    uint8_t i = 0;
    while (reader < buffer_ + sizeof(buffer_) && *reader != '\0' && i < sizeof(str) - 1)
    {
        str[i++] = *reader++;
    }
    str[i] = '\0';
    value = String(str);
}

uint8_t SerialTLV::readError()
{
    return error_;
}
