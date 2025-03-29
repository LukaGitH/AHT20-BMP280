# AHT20 + BMP280 Arduino Example

This Arduino sketch demonstrates how to read temperature, humidity, and pressure data using two I2C sensors:

- [Adafruit AHT20](https://www.adafruit.com/product/4566) — Temp + Humidity
- [Adafruit BMP280](https://www.adafruit.com/product/2651) — Temp + Pressure

## 📦 What's Included

- `AHT20-BMP280.ino`: Example code to read and print sensor data from both sensors
- MIT License

## 🔧 Hardware Required

- Arduino board (Uno, Nano, etc.)
- AHT20 sensor (Adafruit or compatible)
- BMP280 sensor (Adafruit or compatible)
- I2C pull-up resistors (usually built into breakout boards)
- Jumper wires

## 🔌 Wiring

Both sensors use I2C, so you can connect them to the same I2C bus:

| Sensor Pin | Connect to Arduino |
|------------|--------------------|
| SDA        | A4 (Uno/Nano)      |
| SCL        | A5 (Uno/Nano)      |
| VCC        | 3.3V or 5V         |
| GND        | GND                |

> ✅ Both sensors are **5V tolerant** and can be powered from either 3.3V or 5V on typical Arduino boards.

## 🧠 How It Works

- Initializes both sensors on the I2C bus
- Reads temperature and humidity from the AHT20
- Reads temperature and pressure from the BMP280
- Prints the results to the Serial Monitor every second

