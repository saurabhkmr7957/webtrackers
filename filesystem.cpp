#include <SPIFFS.h>
#include "FS.h"
#include <Arduino.h>
#include "filesystem.h"
//#ifndef FS_H
//#define FS_H


SpiffAccess::SpiffAccess(){
        if(!SPIFFS.begin(true)){
          Serial.println("An Error has occurred while mounting SPIFFS");
          return;
        }
}

String SpiffAccess::readFile(fs::FS &fs, const char * path){
  Serial.printf("Reading file: %s\r\n", path);
  File file = fs.open(path, "r");
  if(!file || file.isDirectory()){
    Serial.println("- empty file or failed to open file");
    return "Empty File";
  }
//  Serial.println("- read from file:");
  String fileContent;
  while(file.available()){
    fileContent+=String((char)file.read());
  }
//  Serial.println(fileContent);
  return fileContent;
}
  
void SpiffAccess::writeFile(fs::FS &fs, const char * path, const char * message){
  Serial.printf("Writing file: %s\r\n", path);
  File file = fs.open(path, "w");
  if(!file){
    Serial.println("- failed to open file for writing");
    return;
  }
  if(file.print(message)){
    Serial.println("- file written");
  } else {
    Serial.println("- write failed");
  }
}
  
  // Replaces placeholder with stored values
String SpiffAccess::processor(const String& var){
  //Serial.println(var);
  if(var == "inputString"){
    return readFile(SPIFFS, "/inputString.txt");
  }
  else if(var == "inputInt"){
    return readFile(SPIFFS, "/inputInt.txt");
  }
  else if(var == "inputFloat"){
    return readFile(SPIFFS, "/inputFloat.txt");
  }
  return String();
}
  
  
void SpiffAccess::listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\r\n", dirname);
  File root = fs.open(dirname);
  if (!root) {
    Serial.println("- failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println(" - not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("\tSIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
};

//#endif
