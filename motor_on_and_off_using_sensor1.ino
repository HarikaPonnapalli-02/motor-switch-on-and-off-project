int bottomSensor = 2; // Bottom sensor
int topSensor = 3;    // Top sensor
int relayPin = 4;     // Relay control pin

void setup() {
  // Initialize the sensors and relay pin
  pinMode(bottomSensor, INPUT);
  pinMode(topSensor, INPUT);
  pinMode(relayPin, OUTPUT);

  // Initialize Serial Monitor for communication
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  // Read the state of the sensors
  int bottomState = digitalRead(bottomSensor);
  int topState = digitalRead(topSensor);
  
  // If water is below the bottom sensor, turn on the motor
  if (bottomState == LOW) {
    digitalWrite(relayPin, HIGH);  // Turn motor ON
    Serial.println("Motor is ON: Water level is low, activating pump.");
  }
  // If water reaches the top sensor, turn off the motor
  else if (topState == HIGH) {
    digitalWrite(relayPin, LOW);   // Turn motor OFF
    Serial.println("Motor is OFF: Water level reached the top.");
  }
}


