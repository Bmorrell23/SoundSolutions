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
  matrix.begin();
}

void runGameStart() {
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
}

void loop() {

    runGameStart();
    int maxValue = 0;
    for (int i = 0; i < 15; i++) {
      sensorValue = analogRead (soundPin);
      if (sensorValue > maxValue) {
        maxValue = sensorValue;
      }
      delay(250);
    }
    if (maxValue > 1000) {
        matrix.fillScreen(matrix.Color333(0, 0, 0));
        matrix.setCursor(5, 0);    // start at top left, with one pixel of spacing
        matrix.setTextSize(0.1);     // size 1 == 8 pixels high
        matrix.setTextWrap(false);
        matrix.setTextColor(matrix.Color333(0, 7, 0));
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
        matrix.println("500!");
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
        matrix.println("100!");
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
