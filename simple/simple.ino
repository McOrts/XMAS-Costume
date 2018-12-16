// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN_HELMET_SIDES  5
#define PIN_HELMET_CENTER 6
#define PIN_FRONT_REAR    3
#define PIN_LEGS          11

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS_HELMET_SIDES  9
#define NUMPIXELS_HELMET_CENTER 20
#define NUMPIXELS_FRONT_REAR    135
#define NUMPIXELS_LEGS          120

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels_HELMET_CENTER = Adafruit_NeoPixel(NUMPIXELS_HELMET_CENTER, PIN_HELMET_CENTER, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_HELMET_SIDES  = Adafruit_NeoPixel(NUMPIXELS_HELMET_SIDES, PIN_HELMET_SIDES, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_FRONT_REAR    = Adafruit_NeoPixel(NUMPIXELS_FRONT_REAR, PIN_FRONT_REAR, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_LEGS          = Adafruit_NeoPixel(NUMPIXELS_LEGS, PIN_LEGS, NEO_GRB + NEO_KHZ800);

int delayval = 150; // delay for half a second

void setup() {
  pixels_HELMET_CENTER.begin(); // This initializes the NeoPixel library.
  pixels_HELMET_SIDES.begin(); // This initializes the NeoPixel library. 
  pixels_FRONT_REAR.begin(); // This initializes the NeoPixel library. 
  pixels_LEGS.begin(); // This initializes the NeoPixel library.   
}

void loop() {

  // ############# SET DEFAUL COLOR FOR ALL ############
  Default_ALL(1);

  // ############# HELMET ############
  for(int i=0;i<NUMPIXELS_HELMET_CENTER;i++){
    pixels_HELMET_CENTER.setPixelColor(i, pixels_HELMET_CENTER.Color(200,200,200)); // Moderately bright green color.
    pixels_HELMET_CENTER.show(); // This sends the updated pixel color to the hardware.
    pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(200,200,200)); // Moderately bright green color.
    pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
    pixels_HELMET_CENTER.setPixelColor(i, pixels_HELMET_CENTER.Color(200,0,0)); // Moderately bright green color.
    pixels_HELMET_CENTER.show(); // This sends the updated pixel color to the hardware.
    pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(0,0,200)); // Moderately bright green color.
    pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
  }
  theaterChaseRainbow_HELMET(25); 
  for(int i=0;i<NUMPIXELS_HELMET_CENTER;i++){
    pixels_HELMET_CENTER.setPixelColor(i, pixels_HELMET_SIDES.Color(200,0,0)); // high bright white color.
    pixels_HELMET_CENTER.show(); // This sends the updated pixel color to the hardware.
  }
  FlashWhite_HELMET(100);
  for(int i=0;i<NUMPIXELS_HELMET_SIDES;i++){
    pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(0,0,200)); // high bright white color.
    pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
  }

  // ############# BLINK ALL ############
 // Blink_ALL(100);
//  Default_ALL(1);

  // ############# ALL TheaterChase except  HELMET ############
  // Send a theater pixel chase in...
  theaterChase(pixels_FRONT_REAR.Color(255, 0, 0), pixels_LEGS.Color(255, 0, 0), 50); // Red
  theaterChase(pixels_FRONT_REAR.Color(0, 0, 255), pixels_LEGS.Color(0, 0, 255), 50); // Blue

  // ############# FLASH ALL ############
  FlashWhite_ALL(100);
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c_FRONT_REAR, uint32_t c_LEGS, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < 110; i=i+3) {
        pixels_FRONT_REAR.setPixelColor(i+q, c_FRONT_REAR);    //turn every third pixel on
        pixels_LEGS.setPixelColor(i+q, c_LEGS);    //turn every third pixel on
      }
      pixels_FRONT_REAR.show();
      pixels_LEGS.show();
      delay(wait);
      for (uint16_t i=0; i < 110; i=i+3) {
        pixels_FRONT_REAR.setPixelColor(i+q, 0);        //turn every third pixel off
        pixels_LEGS.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//HELMET Flashing lights in white
void FlashWhite_HELMET(uint8_t wait) {
  for (int q=0; q < 100; q++) {
    for(int i=0;i<NUMPIXELS_HELMET_SIDES;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(0,0,0)); // black color.
      pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
    }
    delay(wait);
    for(int i=0;i<NUMPIXELS_HELMET_SIDES;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(255,255,255)); // high bright white color.
      pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
    }
  }
}

//ALL Flashing lights in white
void FlashWhite_ALL(uint8_t wait) {
  for (int q=0; q < 10; q++) {
    for(int i=0;i<NUMPIXELS_HELMET_SIDES;i++){
      pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(0,0,0)); // black color.
      pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_HELMET_CENTER;i++){
      pixels_HELMET_CENTER.setPixelColor(i, pixels_HELMET_CENTER.Color(0,0,0)); // black color.
      pixels_HELMET_CENTER.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_FRONT_REAR ;i++){
      pixels_FRONT_REAR.setPixelColor(i, pixels_FRONT_REAR.Color(0,0,0)); // black color.
      pixels_FRONT_REAR.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_LEGS ;i++){
      pixels_LEGS.setPixelColor(i, pixels_LEGS.Color(0,0,0)); // black color.
      pixels_LEGS.show(); // This sends the updated pixel color to the hardware.
    }
    delay(wait);
    for(int i=0;i<NUMPIXELS_HELMET_SIDES;i++){
      pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(100,100,100)); // high bright white color.
      pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_HELMET_CENTER;i++){
      pixels_HELMET_CENTER.setPixelColor(i, pixels_HELMET_CENTER.Color(100,100,100)); // high bright white color.
      pixels_HELMET_CENTER.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_FRONT_REAR ;i++){
      pixels_FRONT_REAR.setPixelColor(i, pixels_FRONT_REAR.Color(100,100,100)); // black color.
      pixels_FRONT_REAR.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_LEGS ;i++){
      pixels_LEGS.setPixelColor(i, pixels_LEGS.Color(100,100,100)); // black color.
      pixels_LEGS.show(); // This sends the updated pixel color to the hardware.
    }
  }
}

//ALL Default lights
void Default_ALL(uint8_t wait) {
    for(int i=0;i<NUMPIXELS_HELMET_SIDES;i++){
      pixels_HELMET_SIDES.setPixelColor(i, pixels_HELMET_SIDES.Color(0,0,200)); // black color.
      pixels_HELMET_SIDES.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_HELMET_CENTER;i++){
      pixels_HELMET_CENTER.setPixelColor(i, pixels_HELMET_CENTER.Color(200,0,0)); // black color.
      pixels_HELMET_CENTER.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_FRONT_REAR ;i++){
      pixels_FRONT_REAR.setPixelColor(i, pixels_FRONT_REAR.Color(0,0,200)); // black color.
      pixels_FRONT_REAR.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=0;i<NUMPIXELS_LEGS-46 ;i++){
      pixels_LEGS.setPixelColor(i, pixels_LEGS.Color(100,100,100)); // black color.
      pixels_LEGS.show(); // This sends the updated pixel color to the hardware.
    }
    for(int i=NUMPIXELS_LEGS-45;i<NUMPIXELS_LEGS ;i++){
      pixels_LEGS.setPixelColor(i, pixels_LEGS.Color(200,0,0)); // black color.
      pixels_LEGS.show(); // This sends the updated pixel color to the hardware.
    }
}

//ALL Blink
void Blink_ALL(uint8_t wait) {
  for (int q=1; q=200 ; q++) {
    pixels_HELMET_SIDES.fill((0,0,200-q));
    pixels_HELMET_CENTER.fill((200-q,0,0));
    pixels_FRONT_REAR.fill((0,0,200-q));
    pixels_LEGS.fill((200-q,200-q,200-q));
    pixels_HELMET_SIDES.show();
    pixels_HELMET_CENTER.show();
    pixels_FRONT_REAR.show();
    pixels_LEGS.show();
    delay(wait);
   }
 for (int q=1; q=200 ; q++) {
    pixels_HELMET_SIDES.fill((0,0,q));
    pixels_HELMET_CENTER.fill((q,0,0));
    pixels_FRONT_REAR.fill((0,0,q));
    pixels_LEGS.fill((q,q,q));
    pixels_HELMET_SIDES.show();
    pixels_HELMET_CENTER.show();
    pixels_FRONT_REAR.show();
    pixels_LEGS.show();
    delay(wait);
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow_HELMET(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < pixels_HELMET_CENTER.numPixels(); i=i+3) {
        pixels_HELMET_CENTER.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      pixels_HELMET_CENTER.show();

      delay(wait);

      for (uint16_t i=0; i < pixels_HELMET_CENTER.numPixels(); i=i+3) {
        pixels_HELMET_CENTER.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels_HELMET_CENTER.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels_HELMET_CENTER.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels_HELMET_CENTER.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
