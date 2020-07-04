# Arduino-Voltmeter
Arduino Voltmeter
The standard way of measuring voltage on the arduino is connecting the voltage directly to the arduino analog pins. When you want to measure something greater than VCC + 0.5V, it requires a voltage divider, which causes a loss in resolution. What I have done is implemented a digitpot instead of a fixed voltage divider.

![picture](./gh/working.jpg)

# !!CAUTION!! Implement this project at your own risk. It is possible to damage the arduino if coded incorrectly.

# General Schematic Hookup:
![schematic](./gh/schematic.jpg)

As you may have noticed, there isn't any zener diodes present for circuit protection. This is done on purpose as diodes cause the voltage to drift by about a hundred mV. The code that prevents overvoltage is explained in the next section.

# Angry Pixies Choreography:
At the beginning, the :b:arduino will reset both the digipots to the 1 position, causing a 1/100 divided voltage. The :b:arduino will iteratively increase the digipot, until it "clips" in reference to the 1.1V internal reference (AKA it will increase until it hits 1.1V). Then it will back it off one step and take the reading.

Here you can see it working on my oscope. The little peak is where the :b:arduino decided that it's clipping, it gets backed off one step, then instantaneously resets to low position to prevent damage if a high voltage were connected.

Here's a picture of a scope reading that illustrates this:
![oscope](./gh/scope_digipot_ramp.jpg)
After the little peak, the digipot "hangs" for a while. 

Figuring out the exact time for the digipot to settle allows optimization of minimal time in this high state:
![oscope](./gh/fine tuned.jpg)


# Libraries used:
SSD1306 OLED (Kudos to software I2C compatibility):
https://github.com/lexus2k/ssd1306
