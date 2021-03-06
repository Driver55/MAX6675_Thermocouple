# MAX6675 Thermocouple Library

For Arduino boards.

The Library implements a set of methods for working with a thermocouple based on the MAX6675 driver.
Provides a temperature reading in Celsius, Fahrenheit and Kelvin.
Modified version of the [MAX6675-library](https://github.com/adafruit/MAX6675-library).

MAX6675 driver measures the output of a K Thermocouple and provides the result to the Arduino via a SPI interface.
**********************************************************************************************************
## Integration from Nicola Deliso (Driver55) https://github.com/Driver55/MAX6675_Thermocouple
MAX6675 supports an SCK up to 4.3 MHz. This means that the minimum duration of an SCK clock can be 200ns.
I integrated the following methods into the library to reduce reading time from the MAX6675:
FastReadCelcius ()
FastSpiRead ()
With the use of this routine the reading times are reduced from about 33 ms. to about 250 us,
therefore reducing this phase of about 130 times.
**********************************************************************************************************

## Installation

1. [Download](https://github.com/YuriiSalimov/MAX6675_Thermocouple/releases) the Latest release from gitHub.
2. Unzip and modify the Folder name to "MAX6675_Thermocouple" (Remove the '-version')
3. Paste the modified folder on your Library folder (On your `libraries` folder inside Sketchbooks or Arduino software).
4. Restart the Arduino IDE.

## Circuit Diagram

![Circuit Diagram](CircuitDiagram.png)

SO: The module’s serial output. Your Arduino will read this output.

CS: Chip Select. Setting low, selects the Module and tells it to supply an output that is synchronize with a clock.

SCK: The Serial Clock, an input from your Arduino.

VCC: 5V supply

GND: Ground.

## Methods

```cpp
    // Instantiation:
    /**
        SCK_PIN - SCK digital port number.
        CS_PIN - CS digital port number.
        SO_PIN - SO digital port number.
    */
    MAX6675_Thermocouple thermocouple(SCK_PIN, CS_PIN, SO_PIN);

    // Read a temperature in Celsius.
    double celsius = thermocouple.readCelsius();
    // Read a temperature in Kelvin.
    double Kelvin = thermocouple.readKelvin();
    // Read a temperature in Fahrenheit.
    double fahrenheit = thermocouple.readFahrenheit();
    // For older devices.
    double farenheit = thermocouple.readFarenheit();
```

### Examples

[Serial Reading](/examples/SerialReading/SerialReading.ino)

[SerialFastReading](/examples/SerialFastReading/SerialFastReading.ino)  Created by Nicola Deliso (Driver55).

[Average Measurement](/examples/AverageMeasurement/AverageMeasurement.ino)

[Smooth Measurement](/examples/SmoothMeasurement/SmoothMeasurement.ino)

[All examples...](/examples)

Created by Yurii Salimov.
