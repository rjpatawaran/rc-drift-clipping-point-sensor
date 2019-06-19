#include <IRremote.h>
#include <Adafruit_NeoPixel.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define LED_PIN    8
#define LED_COUNT  16

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB);
// GRB
const uint32_t OFF = strip.Color(0, 0, 0);
const uint32_t RED = strip.Color(0, 255, 0);
const uint32_t YELLOW = strip.Color(255, 255, 0);
const uint32_t ORANGE = strip.Color(100, 255, 0);
const uint32_t GREEN = strip.Color(255, 0, 0);

const int redPin = 10;
const int greenPin = 11;

unsigned long previousMillis = 0;
int loop_delay = 0;
int loop_type = 0;
int red_state = LOW; 
int green_state = LOW; 
int BRIGHTNESS = 100;

const int min_delays[] = {0, 5700, 5700, 5700, 100, 100};
const int max_delays[] = {0, 15000, 15000, 15000, 3000, 3000};

void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("HI");
  previousMillis = 0;
  clear();
  hello();  
}

void hello() {
  for( int n = 0; n < 4; n++ ) {  
    for( int i = 0; i < LED_COUNT; i++ ) {
       strip.setPixelColor(i, random(255), random(255) , random(255));
    }
    strip.show();
    delay(2);
  }
  strip.clear();
  strip.show();
}

void clear() {
  Serial.println("CLEAR");
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.setBrightness(BRIGHTNESS);
  strip.clear();
  strip.show();
  delay(500);
}

void basic() {
  clear();
  strip.setPixelColor(8, RED);
  strip.setPixelColor(7, RED);
  strip.setPixelColor(9, RED);
  strip.setPixelColor(6, RED);
  strip.show();
  delay(1000);
  strip.setPixelColor(5, RED);
  strip.setPixelColor(10, RED);
  strip.setPixelColor(4, RED);
  strip.setPixelColor(11, RED);
  strip.show();
  delay(1000);
  strip.setPixelColor(2, ORANGE);
  strip.setPixelColor(3, ORANGE);
  strip.setPixelColor(12, ORANGE);
  strip.setPixelColor(13, ORANGE);
  strip.show();
  delay(1000);  
  strip.setPixelColor(0, GREEN);
  strip.setPixelColor(1, GREEN);
  strip.setPixelColor(14, GREEN);
  strip.setPixelColor(15, GREEN);
  strip.show();
  delay(1000);  
}


void basic_fill() {
  clear();
  strip.setPixelColor(8, RED);
  strip.setPixelColor(7, RED);
  strip.setPixelColor(9, RED);
  strip.setPixelColor(6, RED);
  strip.show();
  delay(1000);
  strip.setPixelColor(5, RED);
  strip.setPixelColor(10, RED);
  strip.setPixelColor(4, RED);
  strip.setPixelColor(11, RED);
  strip.show();
  delay(1000);
  strip.setPixelColor(2, ORANGE);
  strip.setPixelColor(3, ORANGE);
  strip.setPixelColor(12, ORANGE);
  strip.setPixelColor(13, ORANGE);
  strip.show();
  delay(1000);  
  strip.fill(GREEN, 0, 16);
  strip.show();
  delay(1000);  
}


void drag() {
  clear();
  strip.setPixelColor(8, YELLOW);
  strip.show();
  delay(500);
  strip.setPixelColor(7, YELLOW);
  strip.show();
  delay(1200);
  strip.setPixelColor(9, YELLOW);
  strip.show();
  delay(400);
  strip.setPixelColor(6, YELLOW);
  strip.show();
  delay(1200);
  strip.setPixelColor(5, ORANGE);
  strip.setPixelColor(10, ORANGE);
  strip.show();
  delay(600);
  strip.setPixelColor(5, OFF);
  strip.setPixelColor(10, OFF);
  strip.setPixelColor(4, ORANGE);
  strip.setPixelColor(11, ORANGE);
  strip.show();
  delay(600);
  strip.setPixelColor(4, OFF);
  strip.setPixelColor(11, OFF);
  strip.setPixelColor(3, ORANGE);
  strip.setPixelColor(12, ORANGE);
  strip.show();
  delay(600);
  strip.setPixelColor(3, OFF);
  strip.setPixelColor(12, OFF);
  strip.setPixelColor(0, GREEN);
  strip.setPixelColor(1, GREEN);
  strip.setPixelColor(2, GREEN);
  strip.setPixelColor(13, GREEN);
  strip.setPixelColor(14, GREEN);
  strip.setPixelColor(15, GREEN);  
  strip.show();
}

void alt_red() {
  red_state = !red_state;
  if (red_state) {
      strip.fill(RED, 0, 16);
  } else {
      strip.clear();
  }
  strip.show();  
}

void alt_green() {
  green_state = !green_state;
  if (green_state) {
      strip.fill(GREEN, 0, 16);
  } else {
      strip.clear();
  }
  strip.show();  
}


void loop(){
    if (irrecv.decode(&results)){
        Serial.println(results.value);
        hello();
        switch(results.value){
          case 16753245: //Keypad button "1"
            loop_type = 0;
            basic();
            break;
            
          case 16736925: //Keypad button "2"
            loop_type = 0;
            basic_fill();
            break;
            
          case 16769565: //Keypad button "3"
            loop_type = 0;
            drag();
            break;

          case 16720605: //Keypad button "4"
            loop_delay = 10000;
            previousMillis = loop_delay * -1;
            loop_type = 1;
            break;

          case 16712445: //Keypad button "5"
            loop_delay = 10000;
            previousMillis = loop_delay * -1;
            loop_type = 2;
            break;          

          case 16761405: //Keypad button "6"
            loop_delay = 10000;
            previousMillis = loop_delay * -1;
            loop_type = 3;
            break;   

          case 16769055: //Keypad button "7"
            loop_delay = 15000;
            previousMillis = loop_delay * -1;
            loop_type = 1;
            break;

          case 16754775: //Keypad button "8"
            loop_delay = 15000;
            previousMillis = loop_delay * -1;
            loop_type = 2;
            break;          

          case 16748655: //Keypad button "9"
            loop_delay = 15000;
            previousMillis = loop_delay * -1;
            loop_type = 3;
            break;   

          case 16738455: //Keypad button *
            loop_delay = 700;
            previousMillis = loop_delay * -1;
            loop_type = 4;
            break;

          case 16756815: //Keypad button #
            loop_delay = 700;
            previousMillis = loop_delay * -1;
            loop_type = 5;
            break;        

          case 16716015: //Keypad button left
            if (min_delays[loop_type] < loop_delay) 
                loop_delay -= 100;
            break;

          case 16734885: //Keypad button right
            if (max_delays[loop_type] > loop_delay) 
                loop_delay += 100;
            break;

          case 16718055: //Keypad button up
            if (BRIGHTNESS < 255)
                BRIGHTNESS += 25;
            strip.setBrightness(BRIGHTNESS);
            break;

          case 16730805: //Keypad button up
            if (BRIGHTNESS > 10)
                BRIGHTNESS -= 25;
            strip.setBrightness(BRIGHTNESS);
            break;
          
          case 16750695:
            clear();
            loop_type = 0;

        }
        irrecv.resume(); 
    }

    unsigned long currentMillis = millis();
    //Serial.print("currentMillis: ");
    //Serial.println(currentMillis);
    //Serial.print("previousMillis: ");
    //Serial.println(previousMillis);
    //Serial.print("currentMillis - previousMillis: ");
    //Serial.println(currentMillis - previousMillis);
    //Serial.print("loop_type: ");
    //Serial.println(loop_type);
    if ((loop_type != 0) && (currentMillis - previousMillis >= loop_delay)) {      
      // save the last time you blinked the LED
      switch(loop_type) {
          case 1:
              basic();
              break;
          case 2:
              basic_fill();
              break;
          case 3:
              drag();
              break;
          case 4:
              alt_red();
              break;
          case 5:
              alt_green();
              break;         
      }
      previousMillis = currentMillis;
   }
}
