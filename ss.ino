#include<KiwisIoT.h>

const char* ssid = "Wifi name "; // Replace with your WiFi network name

const char* pass = "password"; // Replace with your WiFi network password

const char* topic = "dash_1789986828467"; // Replace with your dashboard topic ID

#define SOIL_PIN A0

KiwisIoT kiwisiot(ssid, pass, topic);

void setup() {

Serial.begin(115200);

delay(1000);

kiwisiot.begin();

Serial.println();

Serial.println("Soil Moisture Sensor Started");

}



void loop() {

kiwisiot.run();




// Read analog value

int sensorValue = analogRead(SOIL_PIN);



// Convert to approximate percentage

// Calibration may be required for your sensor

int moisturePercent = map(sensorValue, 1023, 0, 0, 100);



// Keep percentage between 0 and 100

moisturePercent = constrain(moisturePercent, 0, 100);



Serial.print("Sensor Value: ");

Serial.print(sensorValue);



Serial.print(" | Moisture: ");

Serial.print(moisturePercent);

Serial.println("%");

kiwisiot.send("1",moisturePercent);



delay(2000);

}

