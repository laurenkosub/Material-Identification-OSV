volatile byte half_revolutions;
unsigned int rpm;
unsigned long timeold;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, magnet_detect, RISING); //initializes interrupt pin (pin 2)
  half_revolutions = 0;
  rpm = 0;
  timeold = 0;
  Serial.println("Start");
}

//measure rpm
void loop() { 
  if (half_revolutions >= 20) {
    rpm = 30*1000/(millis() - timeold)*half_revolutions;
    timeold = millis();
    half_revolutions = 0;
    Serial.println(rpm,DEC);
  }
  Serial.println(half_revolutions); 
  delay(500);
}

//this funciton is called whenever a magnet/interrupt is detected
void magnet_detect() { 
  half_revolutions++;
  Serial.println("detect");
}

