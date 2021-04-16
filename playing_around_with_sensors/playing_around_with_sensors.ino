#include <HTS221Sensor.h>
#include <LPS22HBSensor.h>

#define DEV_I2C Wire
#define SerialPort Serial

// Components.
HTS221Sensor HumTemp(&DEV_I2C);
LPS22HBSensor PressTemp(&DEV_I2C);

void setup() {
  // Led.
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize serial for output.
  SerialPort.begin(115200);
  
  // Initialize I2C bus.
  DEV_I2C.begin();

  // Initialize components.
  HumTemp.begin();
  HumTemp.Enable();
  PressTemp.begin();
  PressTemp.Enable();
}

void loop() {
  // Read humidity and temperature.
  float humidity, temperature;
  HumTemp.GetHumidity(&humidity);
  HumTemp.GetTemperature(&temperature);
  
  // Read pressure and temperature.
  float pressure, temperature2;
  PressTemp.GetPressure(&pressure);
  PressTemp.GetTemperature(&temperature2);
  
  SerialPort.print("| Hum[%]: ");
  SerialPort.print(humidity, 2);
  SerialPort.print(" | Temp[C]: ");
  SerialPort.print(temperature, 2);
  SerialPort.print(" | Pres[hPa]: ");
  SerialPort.print(pressure, 2);
  SerialPort.print(" | Temp2[C]: ");
  SerialPort.println(temperature2, 2);

  delay(5000);
}
