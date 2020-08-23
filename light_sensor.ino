#include <Servo.h>

// Declare constants
#define SERVO_PIN 3
#define LIGHT_LOW 0
#define LIGHT_HIGH 670
#define SERVO_LOW 0
#define SERVO_HIGH 180
#define CLASSES_COUNT 100

const unsigned int LIGHT_STEP = (LIGHT_HIGH - LIGHT_LOW)/CLASSES_COUNT;
const unsigned int SERVO_STEP = (SERVO_HIGH - SERVO_LOW)/CLASSES_COUNT;

// Initialize servo
Servo SERVO;

// Initial setup
// Attach servo to arduino pin
void setup() {
  Serial.begin(9600);
  SERVO.attach(SERVO_PIN);
}

// Main program
// Read light intensity every second and move servo accordingly
void loop() {
  unsigned int lightIntensity;
  lightIntensity = analogRead(A0);

  SERVO.write((lightIntensity/LIGHT_STEP) * SERVO_STEP);
  delay(1000);
}
