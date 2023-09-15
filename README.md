
# Arduino RF Toolset

This repository provides a comprehensive toolkit for 433MHz RF communication using MX-05V (receiver) and MX-FS-03V (transmitter) modules with Arduino. It leverages Object-Oriented Programming (OOP) principles and the tinyRF library for efficient and modular code.

## Features

- TLV-structured data transmission for robust and flexible communication.
- Real-time command options via serial monitor.
- Object-Oriented Programming approach for code modularity and reusability.
- PlatformIO integration for streamlined project and dependency management.
- Response and Send Handlers for managing various RF commands.

## Prerequisites

To use this repository, you need to have the following installed:

- [Arduino IDE](https://www.arduino.cc/en/software)
- [PlatformIO Core](https://platformio.org/platformio-ide)
- [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation.html)
- [Git](https://git-scm.com/)

## Getting Started

1. Clone this repository to your local machine using Git.
   ```
   git clone https://github.com/DarioCasciato/arduino-rf-toolset.git
   ```
2. Navigate into the project directory.
   ```
   cd arduino-rf-toolset
   ```
3. Open the project in your preferred integrated development environment (IDE). (VS-Code is recommended).
4. Build and upload the firmware to your Arduino board using PlatformIO.

## Directory Structure

The directory structure of this repository is organized as follows:

```
├───lib
│   └───TinyRF
├───src
│   ├───TagHandler
│   │   ├───responseHandlers
│   │   └───sendHandlers
│   ├───tlv
│   └───transceiver
└───utils
    ├───Arduino
    ├───Buzzer
    ├───Conversions
    ├───EdgeDetection
    ├───LED
    ├───Logging
    ├───Potentiometer
    └───Security
    └───Timer
```

- **`lib/TinyRF/`**: Contains the tinyRF library files.
- **`src/TagHandler/`**: Contains the response and send handlers for managing RF commands.
- **`src/tlv/`**: Contains the TLV (Tag-Length-Value) related files.
- **`src/transceiver/`**: Contains the transceiver class.
- **`utils/`**: Contains useful libraries for various functionalities.

## How it Works

### State Management

The `stateApp()` function serves as the main state manager, handling incoming data from the RF transceiver and serial monitor. It delegates tasks to `ResponseHandler` and `SendHandler` based on the type of data received.

### Response Handler

The `ResponseHandler` class manages incoming RF commands. It supports a variety of tags, such as `ScanDevices`, `PingPong`, `SendString`, `SendNumber`, `SetPort`, and `GetPort`.

### Send Handler

The `SendHandler` class manages outgoing RF commands. Similar to the `ResponseHandler`, it supports a variety of tags for different functionalities.

## Contributing

Contributions to improve this repository are always welcome. If you find any issues or have suggestions for enhancements, please open an issue or submit a pull request.

## License

This repository is licensed under the [MIT License](LICENSE).

## Resources

- [Arduino Reference](https://www.arduino.cc/reference/en/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Arduino Forum](https://forum.arduino.cc/)
- [PlatformIO Community](https://community.platformio.org/)
