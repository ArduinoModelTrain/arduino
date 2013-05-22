// A test logic for TOMIX turnout point control.
// It switches direction every 3 seconds.
// For simplicity, we use Arduino UNO with Arduino Motorshield.
// We take advantage of H-Bridge function(direction change) of Arduino Motorshield.
// Speed control function(by pwm) of Motorshield is not used here.
// Someday, I will make my own H-Bridge circuit for this.

const int a_pwm_pin = 3;	// speed pin of Motorshield for motor A
const int a_dir_pin = 12;	// direction pin of Motorshield for motor A

int a_dir = LOW;

void setup() { 
  pinMode(a_pwm_pin, OUTPUT);
  pinMode(a_dir_pin, OUTPUT);
}

void loop() {
  // change direction everytime
  if(a_dir == LOW) {
    a_dir = HIGH;
  } else {
    a_dir = LOW;
  }
  digitalWrite(a_dir_pin, a_dir);

  // Let the current flows for a SHORT time to keep electric magnet from overheating
  digitalWrite(a_pwm_pin, HIGH);
  delay(50);
  digitalWrite(a_pwm_pin, LOW);

  delay(3000);
}
