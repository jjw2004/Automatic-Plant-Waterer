# Automatic-Plant-Waterer
Automatic plant waterer for my dads plant using ESP32 and some sensors with a screen


## Version 1.0

### Overview
Version 1.0 is a basic soil moisture monitoring system that reads an analog soil moisture sensor value and converts it into a percentage value for easier interpretation.

The sensor outputs a raw analog reading between **0 and 4095**, which is then mapped to a moisture percentage range of **0% to 100%**.

Based on the calculated moisture level, the system provides visual feedback using three LEDs:

- 🔴 **Red LED** – Soil is too dry (**0% - 39%**)
- 🟢 **Green LED** – Soil moisture is in the optimal range for plant growth (**40% - 80%**)
- 🔵 **Blue LED** – Soil is too wet (**81% - 100%**)

### How It Works

1. The soil moisture sensor measures the moisture content in the soil.
2. The analog value (0-4095) is converted into a percentage (0%-100%).
3. The system compares the moisture percentage against predefined thresholds.
4. The corresponding LED illuminates to indicate the current soil condition.

This version serves as a simple proof-of-concept for soil moisture monitoring and provides an easy-to-understand visual indication of plant watering conditions.

<img width="242" height="350" alt="soilV1" src="https://github.com/user-attachments/assets/4fc47964-3c81-4de1-9f2d-d159ecf76b1c" />

