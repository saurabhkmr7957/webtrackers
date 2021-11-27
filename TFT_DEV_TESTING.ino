
#include "common.h"

//#ifdef tft
//#undef tft
//
//#endif

TFT_eSPI tft = TFT_eSPI();
String software_version  = "webtrackers v1.0";
boolean SwitchOn = false;
uint16_t ID, oldcolor, currentcolor;




baiscWifi baiscWifi{};

mainfunction mainfunction{};

/*  Store Menu Variables  */
String CurrentPage;
String PrevPage;                      //  remember previous page
int StatusBarColor     =  SKY;        //  default color for the StatusBar
int MenuColor;
int TextColor          =  WHITE;      //  default text color
int BtnBorderColor;
int MenuInfo           =  0;          //  0 = OFF, 1 = ON

/*  LED Brightness control  */
int backlight = 3;
int backlightbox;
int blv;
int barv;

/*  LED Timer control  */
unsigned long LedTimer;
int sleepnever;
int esleep;
unsigned long awakeend;

void setup(void) {

  Serial.begin(115200);
  Serial.println("Serial Monitor started");

  tft.init(); 
   tft.fillScreen(WHITE);

  /*  Set Values Manually | uncomment this and run once if you have not used the EEPROM before on your Arduino */
  blv = 255;                //  Led Brightness value
  esleep  = 7;              //  Set Default Led Sleep Time (10 minutes)

  


  /*  Read Values stored on EEPROM  */
  blv = EEPROM.read(1);                       //  LED Brightness
  esleep = EEPROM.read(2);                    //  LED Timer
//  LoadLedTimer();




  
  delay(150);
  Serial.print("EEPROM read 1: ");        //  uncomment these to show the EEPROM saved values in the serial monitor
  Serial.println(EEPROM.read(1));
  Serial.print("EEPROM read 2: ");
  Serial.println(EEPROM.read(2));
                        // The address of your Display
  tft.setRotation(LCDROTATION);               // Need for the Mega, please changed for your choice or rotation initial
  tft.fillScreen(BLACK);

  StartupScreen();                            //  Display Startup Screen
  delay(1500);
  ClearPage();
  HomeScreen();                               //  Pre-Load the Home Screen

  Serial.println("Starting Loop");
}

void loop(void) {

    Touch();              //  Touchable screen with mappings for buttons

}
