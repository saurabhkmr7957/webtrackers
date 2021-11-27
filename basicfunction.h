#ifndef MY_BASICFUNCTION_H
#define MY_BASICFUNCTION_H
//#include "common.h"
#include <Arduino.h>
#include <SPIFFS.h>
#include "FS.h"

//#ifdef tft
//#undef tft
//
//#endif

class baiscWifi{
   public:
   baiscWifi();
   void check();
   void Connect();
};


class Httprequest{
  public:
  Httprequest();
  String sendhttprequest(String url);
};

#endif
