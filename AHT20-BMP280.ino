#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>

// Create sensor instances
Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp; // Default I2C address is 0x77

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10); // For boards like Leonardo

  // Initialize AHT20
  if (!aht.begin()) {
    Serial.println("Failed to find AHT20 sensor!");
    while (1) delay(10);
  }
  Serial.println("AHT20 found");

  // Initialize BMP280
  if (!bmp.begin(0x77)) {
    Serial.println("Could not find BMP280 at 0x77!");
    while (1) delay(10);
  }
  Serial.println("BMP280 found");

  // Optional: configure BMP280
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,   // temperature
                  Adafruit_BMP280::SAMPLING_X16,  // pressure
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);
}

void loop() {
  sensors_event_t humidity, temp_aht;
  aht.getEvent(&humidity, &temp_aht); // Get AHT20 events

  float temp_bmp = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F; // hPa
  float altitude = bmp.readAltitude(1013.25); // Use sea-level pressure in hPa

  Serial.print("AHT20 Temperature: ");
  Serial.print(temp_aht.temperature);
  Serial.println(" °C");

  Serial.print("AHT20 Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  Serial.print("BMP280 Temperature: ");
  Serial.print(temp_bmp);
  Serial.println(" °C");

  Serial.print("BMP280 Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("BMP280 Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");

  Serial.println("-----------------------------");
  delay(2000);
}
