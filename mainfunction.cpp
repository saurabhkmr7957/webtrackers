#include "common.h"


Httprequest Httprequest{};


mainfunction::mainfunction(){
  
}

String mainfunction::RegisterDevice(){
  String RegisterUrl = "https://iot.al-ameen.in/attendance/register_device";
  String response =  Httprequest.sendhttprequest(RegisterUrl);
  const size_t bufferSize = JSON_OBJECT_SIZE(3);
  const size_t bufferSize1 = JSON_OBJECT_SIZE(1024);
  DynamicJsonBuffer jsonBuffer(bufferSize);
  DynamicJsonBuffer jsonBuf(bufferSize1);
  JsonObject& doc = jsonBuffer.createObject();
  JsonObject &data_config = jsonBuf.parseObject(response); //====> Error while compiling
  if (!data_config.success()){
    Serial.println("parseObject() failed");
    return "failed parseing Object";
  }
  //weatherMain = root["weather"]["main"].as<String>();
  String  Device_id = data_config["device_id"].as<String>();
  Device_id.toLowerCase();
  return Device_id;
}


String mainfunction::Registerstaff(String StaffEpcCode, String Device_id, String AdminId){
  String RegisterUrl = "http://iot.al-ameen.in/attendance/register_rfid?device_id=" + Device_id + "&admin_id="+ AdminId + "&rfid=" + StaffEpcCode;
  String response =  Httprequest.sendhttprequest(RegisterUrl);
  Serial.print(response);
  const size_t bufferSize = JSON_OBJECT_SIZE(3);
  const size_t bufferSize1 = JSON_OBJECT_SIZE(1024);
  DynamicJsonBuffer jsonBuffer(bufferSize);
  DynamicJsonBuffer jsonBuf(bufferSize1);
  JsonObject& doc = jsonBuffer.createObject();
  JsonObject &data_config = jsonBuf.parseObject(response); //====> Error while compiling
  if (!data_config.success()){
    Serial.println("parseObject() failed");
    return "failed parseing Object";
  }
      String  staffregstatus = data_config["status"].as<String>();
      staffregstatus.toLowerCase();
      return staffregstatus;
}
String mainfunction::Registerstudent(String StaffEpcCode, String Device_id, String reg_no){
  String RegisterUrl = "http://iot.al-ameen.in/attendance/register_rfid?device_id=" + Device_id + "&reg_no="+ reg_no + "&rfid=" + StaffEpcCode;
  String response =  Httprequest.sendhttprequest(RegisterUrl);
  Serial.print(response);
  const size_t bufferSize = JSON_OBJECT_SIZE(3);
  const size_t bufferSize1 = JSON_OBJECT_SIZE(1024);
  DynamicJsonBuffer jsonBuffer(bufferSize);
  DynamicJsonBuffer jsonBuf(bufferSize1);
  JsonObject& doc = jsonBuffer.createObject();
  JsonObject &data_config = jsonBuf.parseObject(response); //====> Error while compiling
  if (!data_config.success()){
    Serial.println("parseObject() failed");
    return "failed parseing Object";
  }
      String  staffregstatus = data_config["status"].as<String>();
      staffregstatus.toLowerCase();
      return staffregstatus;
}
