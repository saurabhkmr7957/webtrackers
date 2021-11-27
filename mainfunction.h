#ifndef MY_MAINFUNCTION_H
#define MY_MAINFUNCTION_H
#include "common.h"
#include <Arduino.h>

class mainfunction{
  
  public:
  mainfunction();
  String RegisterDevice();
  String Registerstaff(String StaffEpcCode, String Device_id, String AdminId);
  String Registerstudent(String StaffEpcCode, String Device_id, String reg_no);
  
  
};
#endif
