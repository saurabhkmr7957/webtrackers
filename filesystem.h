#ifndef MY_FILESYSTEM_H
#define MY_FILESYSTEM_H

class  SpiffAccess {
  public:
  SpiffAccess();
  String readFile(fs::FS &fs, const char * path);
  void writeFile(fs::FS &fs, const char * path, const char * message);
  String processor(const String& var);
  void listDir(fs::FS &fs, const char * dirname, uint8_t levels);
};

#endif
