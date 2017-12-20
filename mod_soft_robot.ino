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
  if (digitalRead(onSwitch) == HIGH) {
    Serial.println("Turning on the pump.");
    // Open the inlet valve
    analogWrite(inletValve, 255);
    // Turn on the pump for 2 seconds
    analogWrite(pumpControl, 255);
    delay(2000);
    // Turn off the pump
    analogWrite(pumpControl, 0);
    // Close the valve
    analogWrite(inletValve, 0);
  } else if (digitalRead(offSwitch) == HIGH) {
    // TOFIX: get this working, switch works on power instead of ground
    // Open the release valve
    Serial.println("Releasing pressure");
    analogWrite(outletValve, 255);
    delay(2000);
    analogWrite(outletValve, 0);
  }
  delay(1);
}
