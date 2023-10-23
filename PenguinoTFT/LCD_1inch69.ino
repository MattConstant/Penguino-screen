#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"

#include <SoftwareSerial.h>

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
  String receivedString = mySerial.readString();
  Serial.println(receivedString);
  char* c = (char*)receivedString.c_str();
  
        if (c = "Banana") {
        Paint_Clear(YELLOW);
    }  else {
       Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 90, WHITE);
  Paint_Clear(WHITE);
  Paint_DrawString_EN(30, 10, c, &Font24, WHITE, BLACK);
    }
        if (c = "Apple") {
        Paint_Clear(YELLOW);
    }  else {
        Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 90, WHITE);
        Paint_Clear(WHITE);
        Paint_DrawString_EN(30, 10, c, &Font24, WHITE, BLACK);
    }
        if (c = "Mango") {
        Paint_Clear(YELLOW);
    }  else {
        Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 90, WHITE);
        Paint_Clear(WHITE);
        Paint_DrawString_EN(30, 10, c, &Font24, WHITE, BLACK);
    }
        if (c = "Orange") {
        Paint_Clear(YELLOW);
    } else {
        Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 90, WHITE);
        Paint_Clear(WHITE);
        Paint_DrawString_EN(30, 10, c, &Font24, WHITE, BLACK);
    }
  

  }
}
