/*
  Dave Steps

   https://github.com/pastorhudson/MotionLightControl
*/

// Setup Pins
int motionPin = 0;
int state = LOW;
int val = 0;
unsigned long previousMillis = 0;
// const long interval = 5 * 60 * 1000; // 5 minutes in milliseconds
const long interval = 5000; // 5 minutes in milliseconds

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the digital pin for Motion Input
  pinMode(motionPin, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  // overide interval to be shorter

}

// the loop function runs over and over again forever
void loop() {
  val = digitalRead(motionPin);   // read sensor value
  
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(LED_BUILTIN, LOW);   // turn LED ON
    if (state == LOW) {
      Serial.println("Motion detected!");
      previousMillis = millis(); // record the time motion was detected
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
    if (state == HIGH && (millis() - previousMillis >= interval)) {
      digitalWrite(LED_BUILTIN, HIGH); // turn LED OFF after 5 minutes
      Serial.println("LED turned off after 5 minutes!");
      state = LOW;       // update variable state to LOW
    }
  }
}
