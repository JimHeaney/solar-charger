# Solar Charger

## Overview
The solar charger is a device that will track the position of the sun and align solar panels to generate the most power possible. This power can then be used to charge onboard batteries, or provide power through a 5V USB connection.

To track the position of the sun, two photoresistors with a wall in the middle are used. When the microcontroller detects a difference in the light levels between the two that is above a predefined threshold, a servo will move the arm in the direction of the light until the difference drops below the critical threshold.

If the level of both photoresistors drop below a set level, such as when the sun drops below the horizon, the system will return the photoresistors to the vertical orientation. The photoresistors are slightly tilted off axis so they can detect the rising sun on either side of the system.

The onboard electronics serve two main purposes, to track the sun with the aformentioned system and to provide information about the system status. An RGB LED on the electronics box tells the voltage output of the panels, and whether it is suitable or not to charge the batteries or use the USB port. 

Two buttons on the electronics panel allow for interaction with the system. The first toggles the RGB LED on or off, to help preserve power when not in use. The other sets the tracker to calibration mode; it will sweep from the maximum to minimum motor position, determine what point has the strongest light level, and move there. This can be used if the system ever gets lost or confused, or tracks onto a light source besides the sun. 

All major components are split into small chunks that can fit onto a hobbyist 3D printer, and then assembled with M3 and M5 hardware. The counterweight is filled with M5 bolts to keep balance and reduce load on the servo. 

## Photos & Media
Photos of the project can be found on my portfolio, [here](https://www.jim-heaney.com/solar-charger.html).

## Current Release
Version 1.0

## Current State
The Solar Charger is no longer an active project. I do not plan to update or further maintain it. 

## Support Me
You can buy me a coffee [here](https://www.buymeacoffee.com/jimheaney)!

## License
This project is licensed under the Creative Commons 4.0 Attribution-NonCommercial-ShareAlike. For more information, click [here](https://creativecommons.org/licenses/by-nc-sa/4.0/).

If you want to use this project under a different license, please contact me. 
