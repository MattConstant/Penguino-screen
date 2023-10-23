#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"

#include <SoftwareSerial.h>

#define ORANGE 0xFD20  // Orange color in RGB565 format
#define txPin 2
#define rxPin 3
#define baud 9600

SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(baud);
  Serial.begin(baud);
  Config_Init();
  LCD_Init();
  LCD_SetBacklight(100);
}

void loop() {
  if (mySerial.available() > 0) {
    String mapping = mySerial.readStringUntil('>');
    String arg = mySerial.readStringUntil(';');

    Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 90, WHITE);  // Clear screen for fresh drawing
    Paint_Clear(WHITE);

    Serial.println(arg);
    Serial.println(mapping);

if(mapping.equalsIgnoreCase("feed")) {
   if (arg.equalsIgnoreCase("banana")) {
    // Top ellipse for banana
    Paint_DrawCircle(120, 130, 50, YELLOW, DOT_PIXEL_DFT, DRAW_FILL_FULL);
    // Bottom ellipse for banana
    Paint_DrawCircle(120, 170, 50, YELLOW, DOT_PIXEL_DFT, DRAW_FILL_FULL);
    // Drawing a white rectangle to carve out the middle and give a banana-like shape
    Paint_DrawRectangle(70, 130, 170, 170, WHITE, DOT_PIXEL_DFT, DRAW_FILL_FULL);
}
else if (arg.equalsIgnoreCase("apple")) {
    // Centralizing the apple
    Paint_DrawCircle(120, 140, 35, RED, DOT_PIXEL_DFT, DRAW_FILL_FULL); 
    Paint_DrawString_EN(115, 130, ".", &Font24, BLACK, WHITE);  // Apple's dimple
} 
else if (arg.equalsIgnoreCase("orange")) {
    // Centralizing the orange
    Paint_DrawCircle(120, 140, 35, ORANGE, DOT_PIXEL_DFT, DRAW_FILL_FULL);
} 
else if (arg.equalsIgnoreCase("mango")) {
    // Centralizing the mango
    Paint_DrawCircle(120, 140, 35, ORANGE, DOT_PIXEL_DFT, DRAW_FILL_FULL);
    Paint_DrawString_EN(115, 130, ".", &Font24, BLACK, WHITE);  // Mango's dimple
}
 } else {
      Paint_DrawString_EN(30, 10, arg.c_str(), &Font24, WHITE, BLACK); 
    }
  }
}

