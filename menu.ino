
/*  Menus  */

void  HomeScreen()  {
  ClearPage();
  CurrentPage     =  "Home";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   SKY;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawHomeMenu();     //  Draw Home Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  DashBoard()  {
  ClearPage();
  CurrentPage     =   "DashBoard";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   BLACK;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawDashBoard();     //  Draw DashBoard
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedMenu()  {
  ClearPage();
  CurrentPage     =   "Led Menu";
  MenuInfo        =   1;
  StatusBarColor  =   GREEN;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   WHITE;
  StatusBar();        //  Draw Status Bar
//  drawLedMenu();     //  Draw Home Buttons
//  function.wifi();
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  InReg()  {
  ClearPage();
  CurrentPage     =   "Registraion";   // under the home button of registraion or in first click registraion button on home page
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   PINK;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   WHITE;
  StatusBar();        //  Draw Status Bar
  drawRegOption();     //  Draw Reg option buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  SettingsMenu()  {
  ClearPage();
  CurrentPage     =   "Settings";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   WHITE;
  MenuColor       =   StatusBarColor;
  BtnBorderColor  =   MenuColor;
  TextColor       =   TextColor;
  StatusBar();                //  Draw Status Bar
  drawSettingsMenu();         //  Draw Menu 5 Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}

void SoundMenu(){
  ClearPage();
  CurrentPage     =   "Sound";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   WHITE;
  MenuColor       =   StatusBarColor;
  BtnBorderColor  =   MenuColor;
  TextColor       =   TextColor;
  StatusBar();                //  Draw Status Bar
  drawSoundOption();         //  Draw Menu 5 Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
  
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  LedSettingsMenu()  {
  ClearPage();
  CurrentPage     =   "Led Options";  
  MenuInfo        =   1;                //  Enable Info Page
  StatusBarColor  =   GOLD;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  StatusBar();                          //  Draw Status Bar
  drawLedOptionsMenu();                 //  Draw Led Settings Menu
//  OSVersion();                        //  Display OS Version at bottom-right corner
  PrevPage      =   CurrentPage;        //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  CreditsMenu()  {
  ClearPage();
  CurrentPage     =   "Credits";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   GREY;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  StatusBar();        //  Draw Status Bar
  drawCreditsMenu();    //  Draw DashBoard
//  OSVersion();        //  Display OS Version at bottom-right corner
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  Menu1()  {
  ClearPage();
  CurrentPage     =   "Menu1";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawMenu1();        //  Draw Menu 1 Buttons
//  OSVersion();        //  Display OS Version at bottom-right corner
  PrevPage      =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  Menu2()  {
  ClearPage();
  CurrentPage     =   "Menu2";
  MenuInfo        =   0;                //  Info Page OFF
  StatusBarColor  =   GOLD;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();        //  Draw Status Bar
  drawMenu2();        //  Draw Menu 2 Buttons
  PrevPage        =   CurrentPage;    //  Reset Previous Page variable
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  InfoPage() {                            /*  INFO PAGE  */
  ClearPage();
  CurrentPage     =  "Info";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
  drawInfoPage();                            //  Draw info page
  PrevPage        =   CurrentPage;           //  Reset Previous Page variable

}
void  wifi() {                            /*  INFO PAGE  */
  ClearPage();
  CurrentPage     =  "Wi-Fi";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
  baiscWifi.check();
  drawwifioption();                          
  PrevPage        =   CurrentPage;           //  Reset Previous Page variable

}


void NewWiFi(){
  ClearPage();
  CurrentPage     =  "New Connection";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
  baiscWifi.Connect();                            
  drawokandbackbutton();
  PrevPage        =   CurrentPage;           //  Reset Previous Page variable
}

void DeviceOption(){
  ClearPage();
  CurrentPage     =  "Device Option";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar                            
  DrawDeviceOption();
  PrevPage        =   CurrentPage;           //  Reset Previous Page variable
}

void  Deviceinfo() {                            /*  INFO PAGE  */
  ClearPage();
  CurrentPage     =  "Deviceinfo";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
  drawdeviceinfo();                            //  Draw info page
  PrevPage        =   CurrentPage;           //  Reset Previous Page variable

}

void RegisterDevicemenu(){
  ClearPage();
  CurrentPage     =  "Register Device";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
  String resp = "Reg-Device_tested";
//  String resp = RegisterDevice();    
  drawRegDeviceinfo(resp);   
  drawokandbackbutton();                 
  PrevPage        =   CurrentPage;           //  Reset Previous Page variable
}


void RegisterStaff(){
  ClearPage();
  CurrentPage     =  "Register staff";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
//  keyBoard.drawKeyBoard();
  String rfid = "111122";
  String deviceID = "308";
  String adminID = "123";
 String staffregstatus = mainfunction.Registerstaff(rfid,deviceID,adminID);
  if(staffregstatus == "true"){
      String msgone = "Thank You";
      String msgtwo = "You" + rfid + "are registered";
      String regstatus = "welcome to webtrackers";
      drawRegstaffinfo(msgone,msgtwo,regstatus);
  }
  else{
      String msgone = "Oops";
      String msgtwo = "Something went Wrong";
      String regstatus = "kindly get in touch with It team";
      drawRegstaffinfo(msgone,msgtwo,regstatus); 
  }
  PrevPage        =   CurrentPage;        
}
void RegisterStudent(){
  ClearPage();
  CurrentPage     =  "Register student";
  MenuInfo        =   0;                     //  Info Page OFF
  StatusBarColor  =   SALMON;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();                               //  Draw Status Bar
  String rfid = "111122";
  String deviceID = "308";
  String reg_no = "123";
 String staffregstatus = mainfunction.Registerstudent(rfid,deviceID,reg_no);
  if(staffregstatus == "true"){
      String msgone = "Thank You";
      String msgtwo = "You" + rfid + "are registered";
      String regstatus = "welcome to webtrackers";
      drawRegstudentinfo(msgone,msgtwo,regstatus);
  }
  else{
      String msgone = "Oops";
      String msgtwo = "Something went Wrong";
      String regstatus = "kindly get in touch with It team";
      drawRegstudentinfo(msgone,msgtwo,regstatus); 
  }
  PrevPage        =   CurrentPage;        
}


  
