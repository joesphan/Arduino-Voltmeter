# Arduino-Voltmeter
Arduino Voltmeter
The standard way of measuring voltage on the arduino is connecting the voltage directly to the arduino analog pins. When you want to measure something greater than VCC + 0.5V, it requires a voltage divider, which causes a loss in resolution. What I have done is implemented a digitpot instead of a fixed voltage divider.

!!CAUTION!! Implement this project at your own risk. It is possible to damage the arduino if coded incorrectly.
