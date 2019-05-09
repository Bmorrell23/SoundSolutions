// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 32x32 RGB LED matrix:
// http://www.adafruit.com/products/607

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <RGBmatrixPanel.h>

int soundPin = A5;
int ledPin = 12;
int sensorValue = 0;

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  Serial.begin(9600);
  runGameStart();
  
}

void loop() {
  int height = 1;
  int maxValue = 0;
  for (int i = 1; i < 20; i++) {
    sensorValue = analogRead (soundPin);
    Blow(height);
    height = height + 2;
    if (sensorValue > maxValue) {
      maxValue = sensorValue;
    }
    //delay(50);//Allows for 9 seconds of data
  }
  if (maxValue > 1000) {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
    matrix.setCursor(5, 0);    // start at top left, with one pixel of spacing
    matrix.setTextSize(0.1);     // size 1 == 8 pixels high
    matrix.setTextWrap(false);
    matrix.setTextColor(matrix.Color333(0, 7, 0));//Set text to green
    matrix.println("You");
    matrix.println(" Got");
    matrix.println(" Over");
    matrix.println("1000!");
  }
  else if (maxValue > 500) {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
    matrix.setCursor(5, 0);    // start at top left, with one pixel of spacing
    matrix.setTextSize(0.1);     // size 1 == 8 pixels high
    matrix.setTextWrap(false);
    matrix.setTextColor(matrix.Color333(0, 7, 0));
    matrix.println("You");
    matrix.println(" Got");
    matrix.println(" Over");
    matrix.println(" 500!");
  }
  else if (maxValue > 100) {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
    matrix.setCursor(5, 0);    // start at top left, with one pixel of spacing
    matrix.setTextSize(0.1);     // size 1 == 8 pixels high
    matrix.setTextWrap(false);
    matrix.setTextColor(matrix.Color333(0, 7, 0));
    matrix.println("You");
    matrix.println(" Got");
    matrix.println(" Over");
    matrix.println(" 100!");
  }
  else {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
    matrix.setCursor(5, 0);    // start at top left, with one pixel of spacing
    matrix.setTextSize(0.1);     // size 1 == 8 pixels high
    matrix.setTextWrap(false);
    matrix.setTextColor(matrix.Color333(7, 0, 0));
    matrix.println();
    matrix.println(" Try");
    matrix.println("Again");
    //      Serial.println("You scored over 1000!");
  }
  //  digitalWrite (ledPin, LOW);
  delay (5000);
}


void runGameStart() {
  matrix.begin();
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(11, 9);    // start at top left, with one pixel of spacing
  matrix.setTextSize(2);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color333(7, 7, 7));
  matrix.print('5');
  delay(250);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  delay(250);
  matrix.begin();
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(11, 9);    // start at top left, with one pixel of spacing
  matrix.setTextSize(2);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color333(7, 7, 7));
  matrix.print('4');
  delay(250);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  delay(250);
  matrix.begin();
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(11, 9);    // start at top left, with one pixel of spacing
  matrix.setTextSize(2);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color333(7, 7, 7));
  matrix.print('3');
  delay(250);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  delay(250);
  matrix.begin();
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(11, 9);    // start at top left, with one pixel of spacing
  matrix.setTextSize(2);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color333(7, 7, 7));
  matrix.print('2');
  delay(250);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  delay(250);
  matrix.begin();
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(11, 9);    // start at top left, with one pixel of spacing
  matrix.setTextSize(2);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color333(7, 7, 7));
  matrix.print('1');
  delay(250);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  delay(250);
  matrix.begin();
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(1, 9);    // start at top left, with one pixel of spacing
  matrix.setTextSize(2);     // size 1 == 8 pixels high
  matrix.setTextWrap(false);
  matrix.setTextColor(matrix.Color333(7, 7, 7));
  matrix.println("Go!");
  delay(500);
  matrix.begin();
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.begin();
}

void Blow(int top)
{
  int      x, y, hue;
  float    dx, dy, d;
  uint8_t  sat, val;
  uint16_t c;

  matrix.begin();

  for(y=32; y > top; y--) {
    dy = 15.5 - (float)y;
    for(x=0; x < matrix.height(); x++) {
      dx = 15.5 - (float)x;
      d  = dx * dx + dy * dy;
      if(d <= (16.5 * 16.5)) { // Inside the circle(ish)?
        hue = (int)((atan2(-dy, dx) + PI) * 1536.0 / (PI * 2.0));
        d = sqrt(d);
        if(d > 15.5) {
          // Do a little pseudo anti-aliasing along perimeter
          sat = 255;
          val = (int)((1.0 - (d - 15.5)) * 255.0 + 0.5);
        } else
        {
          // White at center
          sat = (int)(d / 15.5 * 255.0 + 0.5);
          val = 255;
        }
        c = matrix.ColorHSV(hue, sat, val, true);
      } else {
        c = 0;
      }
      matrix.drawPixel(x, y, c);
    }
  }
  delay(50);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
//  matrix.begin();
//  matrix.fillScreen(matrix.Color333(0, 0, 0));
//  matrix.setCursor(1, 9);    // start at top left, with one pixel of spacing
//  matrix.setTextSize(1);     // size 1 == 8 pixels high
//  matrix.setTextWrap(false);
//  matrix.setTextColor(matrix.Color444(1, 1, 1));
//  matrix.fillScreen(matrix.Color444(3, 4, 7));
//  matrix.println(x);
//  delay(250);
//  matrix.print("Blow");
//  delay(150);
//  matrix.fillScreen(matrix.Color444(3, 4, 7));
//  delay(50);
}
