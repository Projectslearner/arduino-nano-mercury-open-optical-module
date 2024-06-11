/*
    Project name : Mercury open optical module
    Modified Date: 11-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-mercury-open-optical-module
*/

const int mercuryPin = 2; // Digital pin connected to the Mercury open optical module

void setup() {
  pinMode(mercuryPin, INPUT); // Set the pin as input
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the state of the Mercury open optical module
  int sensorValue = digitalRead(mercuryPin);

  // Print the state to the Serial Monitor
  Serial.print("Mercury Open Optical Module State: ");
  Serial.println(sensorValue);

  // Check if obstruction is detected and print the result
  if (detectObstruction(sensorValue)) {
    Serial.println("Obstruction Detected");
  } else {
    Serial.println("No Obstruction Detected");
  }

  delay(1000); // Add a small delay to avoid spamming the Serial Monitor
}

bool detectObstruction(int value) {
  // Define the threshold value for obstruction detection
  const int threshold = 500;

  // Check if the sensor value is above the threshold
  return value > threshold;
}
