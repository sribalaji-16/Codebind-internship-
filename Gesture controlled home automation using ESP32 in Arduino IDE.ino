// Gesture controlled home automation using ESP32

/* Function Highlights
apds.init() → Initializes the gesture sensor.

apds.enableGestureSensor(true) → Enables gesture detection mode.

apds.isGestureAvailable() → Checks if a gesture is detected.

apds.readGesture() → Reads the type of gesture performed.

digitalWrite(RELAY_PIN, HIGH/LOW) → Turns the appliance ON or OFF.

Blynk.virtualWrite(V1, "status") → Sends status to the Blynk app.

*/

// This code used will turn on and off the device which we onnected to wifi where this is controlled using the gesture
// The code of this project is given below given below

#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Blynk credentials
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "GestureHomeAuto"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// Pin Definitions
#define RELAY_PIN 13

// Objects
SparkFun_APDS9960 apds = SparkFun_APDS9960();

void setup() {
  Serial.begin(115200);

  // Relay
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Start with OFF

  // Connect to WiFi and Blynk
  WiFi.begin(ssid, pass);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Initialize Gesture Sensor
  if (apds.init()) {
    Serial.println("APDS-9960 initialized");
  } else {
    Serial.println("APDS-9960 initialization failed");
    while (1);
  }

  // Enable gesture mode
  if (apds.enableGestureSensor(true)) {
    Serial.println("Gesture sensor enabled");
  } else {
    Serial.println("Gesture sensor failed to enable");
    while (1);
  }
}

void loop() {
  Blynk.run();

  if (apds.isGestureAvailable()) {
    int gesture = apds.readGesture();

    switch (gesture) {
      case DIR_UP:
        Serial.println("Gesture: UP -> Turn ON");
        digitalWrite(RELAY_PIN, HIGH);
        Blynk.virtualWrite(V1, "Appliance ON");
        break;

      case DIR_DOWN:
        Serial.println("Gesture: DOWN -> Turn OFF");
        digitalWrite(RELAY_PIN, LOW);
        Blynk.virtualWrite(V1, "Appliance OFF");
        break;

      case DIR_LEFT:
        Serial.println("Gesture: LEFT -> No Action");
        break;

      case DIR_RIGHT:
        Serial.println("Gesture: RIGHT -> No Action");
        break;

      default:
        Serial.println("Unknown Gesture");
        break;
    }
  }
}


