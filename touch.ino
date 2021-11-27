
/*  Touch Buttons - Define here the touch buttons and their functions  */

void  Touch() {
  
  uint16_t x, y;

  

  tft.getTouch(&x, &y);

  int p_x = x;
  int p_y = y;
  int p_z = tft.getTouchRawZ();

  
  // minimum pressure we consider 'valid' - pressure of 0 means no pressing!
  if (p_z > MINPRESSURE && p_z < MAXPRESSURE) {

    Serial.print("in map_x pressure");
//    delay(10);

    // scale from 0->1023 to tft.width
//    p_x = map(p_x, TS_MINp_x, TS_MAX_x, tft.width(), 0);
//    p_y = map(p_y, TS_MINY, TS_MAXY, tft.height(), 0);

    /*  Display Touch coordinates and pressure to the Serial console  */
    Serial.print("p_p_x = ");
    Serial.print(p_x);
    Serial.print("  |  p_y = ");
    Serial.print(p_y);
    Serial.print("  |  Pressure = ");
    Serial.println(p_z);

  /*  -------------------------------------------------------------------------------------------------------  */
    if  (CurrentPage != "Home") {                           //  if not in home menu display home button
              //  Top-Left corner of the Status Bar  - RIGHT  &  EDGE & TOP  & BOTTOM EDGE
              if (p_y > 4 && p_y < 36.6 && p_x > 3.3 && p_x < 28) {
                HomeScreen();   //  Go Back to Home Screen
              }
    }
  if(CurrentPage == "Home") {
                //  Button 1(TIME)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 41 && p_y < 93 && p_x > 13 && p_x < 153) {
                  DashBoard();
              }
          
              //  Button 2(ATTENDANCE)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              else if (p_y > 41 && p_y < 93 && p_x > 166 && p_x < 306) {
          
                  LedMenu();
                
              }
          
              //    Button 3(REGISTRATION)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 108 && p_y < 160 && p_x > 13 && p_x < 153) {
                Serial.print("regis.. clicked...");
                  InReg(); 
              }
          
              //  Button 4(DEVICE INFO)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 108 && p_y < 160 && p_x > 166 && p_x < 306) {
                  Deviceinfo();
              }
          
              //      Button 5 (ANALYTICS) - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 176 && p_y < 228 && p_x > 13 && p_x < 153) {
                  Menu2();
              }
                  //  Home Button 6(SETTINGS)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE    -  SETTINGS  / CANCEL
              if (p_y > 176 && p_y < 228 && p_x > 166 && p_x < 306) {
                SettingsMenu();
                Serial.println(" setting clicked");
                Serial.println(CurrentPage); 
                    
                }

  }

  if(CurrentPage == "Settings"){
                    //  Button 1(wi-fi)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 41 && p_y < 93 && p_x > 13 && p_x < 153) {
//                  DashBoard();
                    wifi();
              }
          
              //  Button 2(Device)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              else if (p_y > 41 && p_y < 93 && p_x > 166 && p_x < 306) {
          
                  DeviceOption();
                
              }
          
              //    Button 3(server)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 108 && p_y < 160 && p_x > 13 && p_x < 153) {
                Serial.print("regis.. clicked...");
                  InReg(); 
              }
          
              //  Button 4(Sound)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 108 && p_y < 160 && p_x > 166 && p_x < 306) {
                  SoundMenu();
              }
          
              //      Button 5 (BRIGHTNESS) - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
              if (p_y > 176 && p_y < 228 && p_x > 13 && p_x < 153) {
                  LedSettingsMenu();
              }
                  //  Home Button 6(RESET)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE    -  SETTINGS  / CANCEL
              if (p_y > 176 && p_y < 228 && p_x > 166 && p_x < 306) {
                Serial.println(" RESET clicked");
                Serial.println(CurrentPage); 
                  SettingsMenu();   
                }
    
  }

   if(CurrentPage == "Sound"){

          if (SwitchOn)
                  {
                    if ((p_x > REDBUTTON_X) && (p_x < (REDBUTTON_X + REDBUTTON_W))) {
                      if ((p_y > REDBUTTON_Y) && (p_y <= (REDBUTTON_Y + REDBUTTON_H))) {
                        Serial.println("Red btn hit");
                        redBtn();
                      }
                    }
                  }
          else //Record is off (SwitchOn == false)
                  {
                    if ((p_x > GREENBUTTON_X) && (p_x < (GREENBUTTON_X + GREENBUTTON_W))) {
                      if ((p_y > GREENBUTTON_Y) && (p_y <= (GREENBUTTON_Y + GREENBUTTON_H))) {
                        Serial.println("Green btn hit");
                        greenBtn();
                      }
                    }
                  }
    
        if (p_y > 202.5 && p_y < 225 && p_x > 80 && p_x < 146.6) {    //back button touch
                 SettingsMenu();    
            }
    
        if (p_y > 202.5 && p_y < 225 && p_x > 173.3 && p_x < 239.9) {   //save button touch
                  SettingsMenu(); 
            }
 }
 if(CurrentPage == "Wi-Fi"){

          if (p_y > 202.5 && p_y < 225 && p_x > 80 && p_x < 146.6) {    //back button touch
                 SettingsMenu();    
            }
    
        if (p_y > 202.5 && p_y < 225 && p_x > 173.3 && p_x < 239.9) {   //NEW button touch
                  NewWiFi(); 
            }
  
 }
if(CurrentPage == "New Connection"){

        if (p_y > 202.5 && p_y < 225 && p_x > 80 && p_x < 146.6) {    //ok button touch
                 ClearPage();
                 wifi();    
            }
    
        if (p_y > 202.5 && p_y < 225 && p_x > 173.3 && p_x < 239.9) {   //back button touch
                  ClearPage();
                  wifi(); 
            }
  
 }

if(CurrentPage == "Device Option"){   
    //  Button 1(device info)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
      if (p_y > 41 && p_y < 93 && p_x > 13 && p_x < 153) {
                  Deviceinfo();
              }
          
              //  Button 2(regiter device)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
      else if (p_y > 41 && p_y < 93 && p_x > 166 && p_x < 306) {
          
//                  RegisterDevicemenu();
                
              }
}

if(CurrentPage == "Register Device"){

        if (p_y > 202.5 && p_y < 225 && p_x > 80 && p_x < 146.6) {    //ok button touch
                 ClearPage();
                 SettingsMenu();    
            }
    
        if (p_y > 202.5 && p_y < 225 && p_x > 173.3 && p_x < 239.9) {   //back button touch
                  ClearPage();
                  Deviceinfo(); 
            }
  
 }


if(CurrentPage == "Registraion"){

//  this is the reg staff button
  if (p_y > 41 && p_y < 93 && p_x > 13 && p_x < 153) {
      RegisterStaff();
  }

  //  Button 2(reg student)  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
  else if (p_y > 41 && p_y < 93 && p_x > 166 && p_x < 306) {

      RegisterStudent();
    
  }
  
 }


    



    /*  LED BRIGHTNESS + - BUTTONS  BEGIN*/

    //  Button "+"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Brightness UP
    if (p_y > 97.5 && p_y < 135 && p_x > 266.5 && p_x < 306.5) {

      if  (CurrentPage == "Led Options") {
        LedBrightUp();
      }
    }

    //  Button "-"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Brightness DOWN
    if (p_y > 97.5 && p_y < 135 && p_x > 13.3 && p_x < 53.3) {

      if  (CurrentPage == "Led Options") {
        LedBrightDown();
      }
    }
    /*  LED BRIGHTNESS + - BUTTONS  END */



    /*  LED TIMER + - BUTTONS  BEGIN */

    //  Button "+"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Timer Increase
    if (p_y > 97.5 && p_y < 135 && p_x > 266.5 && p_x < 306.5) {

      if  (CurrentPage == "Led Options") {
        LedTimerUp();
      }
    }

    //  Button "-"  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  Led Time Decrease
    if (p_y > 97.5 && p_y < 135 && p_x > 13.3 && p_x < 53.3) {

      if  (CurrentPage == "Led Options") {
        LedTimerDown();
      }
    }
    /*  LED TIMER + - BUTTONS  END */



    /*  BACK & SAVE BUTTONS BEGIN  */

    //  BACK Button - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  BACK TO PREVIOUS PAGE
    if (p_y > 202.5 && p_y < 225 && p_x > 80 && p_x < 146.6) {

      if  (CurrentPage == "Home") {
      }
      else if  (CurrentPage == "Led Options") {
        //  Serial.println("Go back to Led Menu");
        SettingsMenu();
      }

//      else {
//        //      Do Nothing
//      }
    }

    //  SAVE Button - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  SAVE TO EEPROM
    if (p_y > 202.5 && p_y < 225 && p_x > 173.3 && p_x < 239.9) {

      if  (CurrentPage == "Led Options") {
        SaveToEEPROM();
        
      }
    }

    /*  BACK & SAVE BUTTONS END  */



    /*  ICON VIEW TOUCH SETTINGS  BEGIN*/

    //  Icon 12 - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p_y > 22 && p_y < 85 && p_x > 371 && p_x < 475) {

      if  (CurrentPage == "Led Menu") {
        LedSettingsMenu();
      }
    }

    /*  ICON VIEW TOUCH SETTINGS  END*/



    /*  INFO AREA BEGIN*/

    //  Info area - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE   -   show info menu
    if (p_y > 0 && p_y < 40 && p_x > 5 && p_x < 60) {

//      if  (CurrentPage == "Led Menu") {
      if  (MenuInfo == 0) {
        //  Serial.println("There's no menu for this page");
      }
      if  (MenuInfo == 1) {
        InfoPage();
      }
    }

    /*  INFO AREA  END*/

  }

}
