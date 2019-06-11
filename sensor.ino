#include <Adafruit_NeoPixel.h>
#define LED_PIN    11
#define LED_COUNT  1
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define POT_PIN 2

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB);

const int LED_DELAY = 3000;
const int DETECT_DELAY = 1000;
const int MIN_DISTANCE = 3;
const int MAX_DISTANCE = 50;

// defines variables
float pot_pct = 0;
long duration;
int distance;
int pot_value = 0;
float total = 0;
int state = 0;
unsigned long t_state;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200); // Starts the serial communication
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
}

void trigger(int ts) {
  bool new_state = false;
  if (state == 0) {
    t_state = millis();
  }
  if ((state < ts) && ((millis() - t_state) <= DETECT_DELAY)) {
    state = ts;
    new_state = true;
  }
  if (new_state) {
    if (state == 3) {
      Serial.println("GREEN");
      strip.setPixelColor(0, 0, 255, 0);
    } else if (state == 2) {
      Serial.println("BLUE");
      strip.setPixelColor(0, 0, 0, 255);
    } else if (state == 1) {
      Serial.println("RED");
      strip.setPixelColor(0, 255, 0, 0);
    }
    strip.show();
  }
}

void loop() {
  pot_value = analogRead(POT_PIN);
  pot_pct = pot_value / 1024.0;
  total = (MAX_DISTANCE - MIN_DISTANCE) * pot_pct;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2); // 2
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // 10
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  if (duration < 80000) {
    distance = duration * 0.034 * 0.5;
    distance = distance - MIN_DISTANCE;
    // Prints the distance on the Serial Monitor
    //Serial.print("Distance: ");
    //Serial.println(distance);
    //Serial.println(duration);
    //Serial.println(pot_pct);
    float green = total * 0.30;
    float yellow = total * 0.60;
    float red = total * 1.0;
    if (distance < green) {
      trigger(3);
    } else if ((distance >= green) && (distance <= yellow)) {
      trigger(2);
    } else if (distance <= red) {
      trigger(1);
    }
  }
  if ((state != 0) && (millis() - t_state) >= LED_DELAY) {
    state = 0;
    Serial.println("LED OFF");
    strip.clear();
    strip.show();
  }
}
