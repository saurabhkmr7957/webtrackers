#include <TouchScreen.h>
#include "Adafruit_GFX.h"
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "basicfunction.h"
#include "mainfunction.h"
//#include "keyboard.h"




#include <Arduino.h>
#include "WiFi.h"
#include <TouchScreen.h>
#include "Adafruit_GFX.h"
//#include <SPIFFS.h>
//#include "FS.h"
#include <HTTPClient.h>

#include <SPI.h>

#include <ArduinoJson.h>


#include <EEPROM.h>                   //  To save button status on EEPROM



#define LCDROTATION    1

#define TS_MINX 150 //  150
#define TS_MINY 120 //  120
#define TS_MAXX 920 //  920
#define TS_MAXY 940 //  940


#define MINPRESSURE 300
#define MAXPRESSURE 3000




// Comment out to stop drawing black spots
#define BLACK_SPOT

// Switch position and size
#define FRAME_X 100
#define FRAME_Y 64
#define FRAME_W 120
#define FRAME_H 50

// Red zone size
#define REDBUTTON_X FRAME_X
#define REDBUTTON_Y FRAME_Y
#define REDBUTTON_W (FRAME_W/2)
#define REDBUTTON_H FRAME_H

// Green zone size
#define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
#define GREENBUTTON_Y FRAME_Y
#define GREENBUTTON_W (FRAME_W/2)
#define GREENBUTTON_H FRAME_H







                                               
#define BLACK           0x0000
#define WHITE           0xFFFF
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x2685
#define CYAN            0x07FF
#define LIME            0x5FE0
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define TURQUOISE       0x0F1B
#define ORANGE          0xFBA0
#define PINK            0xF813
#define SKY             0x667F        // nice light blue
#define GREY            0xE73C
#define DarkTURQUOISE   0x3491
#define DarkGREY        0x39C7
#define DarkRED         0x8986
#define DarkGREEN       0x3446
#define DarkMAGENTA     0x612F
#define DarkBLUE        0x298B
#define DarkYELLOW      0x83E5
#define DarkORANGE      0xA347
#define DarkPINK        0xA1EF
#define GOLD            0xF3FF00      //  nice yellow
#define SALMON          0xFB2C        //  nice red




//TFT_eSPI tft = TFT_eSPI();
