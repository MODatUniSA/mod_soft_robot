/*
  MOD. Soft Robot pump
  Turns on an off the air pump to expand and contract our soft robots.
  Uses a pressure sensor to control the pump.
 
  This example code is in the public domain.
 */
 
// Pin connections
int onSwitch = 2;
int offSwitch = 3;
int pumpControl = 5;
int inletValve = 6;
int outletValve = 7;
int ledPin = 13;
int pressurePin = A5;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(onSwitch, INPUT);
  pinMode(offSwitch, INPUT);
  pinMode(pumpControl, OUTPUT);
  pinMode(inletValve, OUTPUT);
  pinMode(outletValve, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(pressurePin);
  Serial.print("Pressure: ");
  Serial.println(sensorValue);
  if (digitalRead(onSwitch) == HIGH) {
    Serial.println("Turning on the pump.");
    // Open the inlet valve
    digitalWrite(inletValve,LOW);
    digitalWrite(outletValve,HIGH);
    digitalWrite(ledPin,HIGH);
    // Turn on the pump for 2 seconds
    analogWrite(pumpControl, 255);
    delay(2000);
    // Turn off the pump
    analogWrite(pumpControl, 0);
    // Close the valve
    digitalWrite(inletValve,HIGH);
    digitalWrite(ledPin,LOW);
  } else if (digitalRead(onSwitch) == LOW) {
    // TOFIX: get this working, switch works on power instead of ground
    // Open the release valve
    Serial.println("Releasing pressure");
    digitalWrite(outletValve,LOW);
    delay(2000);
    digitalWrite(outletValve,HIGH);
  }
  delay(1);
}
