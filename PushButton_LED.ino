const int BUTTON_PIN = 2;
const int LED_PIN = 13;
const unsigned long DEBOUNCE_DELAY = 50; // ms

bool ledState = false;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading == LOW && lastButtonState == HIGH) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      Serial.println(ledState ? "LED toggled: ON" : "LED toggled: OFF");
    }
  }

  lastButtonState = reading;
}
