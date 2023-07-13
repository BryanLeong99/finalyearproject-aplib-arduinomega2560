int RELAY = 9;
int BUZZER = 8;
int RED = 5;
int YELLOW = 6;
int GREEN = 7;
String readInput; 

void setup() {
  // setup pin
  Serial3.begin(115200);
  Serial.begin(115200);
  pinMode(RELAY, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  // initial setting
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}

void loop() {
  // trigger the codes whenever an input is detected from the serial channel
  if (Serial3.available() || Serial.available()) {
    readInput = "";
    while (Serial3.available() || Serial.available()) {
      Serial.println("input detected");

      // cut the string
      readInput = Serial3.readStringUntil('\n');
      Serial.println(readInput);

      // unlock the entrance when it is true, else lock the entrance
      if (readInput.indexOf("true") > -1) {
        digitalWrite(RELAY, HIGH);
        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, HIGH);
        tone(BUZZER, 100);
        delay(300);
        noTone(BUZZER);
        tone(BUZZER, 1000);
        noTone(BUZZER);
        Serial.println("Door is opened");
      } else if (readInput.indexOf("false") > -1) {
        digitalWrite(RELAY, LOW);
        digitalWrite(RED, HIGH);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, LOW);
        tone(BUZZER, 100);
        delay(300);
        noTone(BUZZER);
        tone(BUZZER, 1000);
        noTone(BUZZER);
        Serial.println("Door is closed");
      }
    }
    
  }
}
