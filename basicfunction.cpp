
#include "common.h"

//#include "FS.h"
TFT_eSPI tft = TFT_eSPI();
//#ifdef tft
//#undef tft
//
//#endif

const char* ssid     = "JioFi2_049175";
const char* password = "k63qmgs9f2";


WiFiClient client;

String Network = ssid;

baiscWifi::baiscWifi(){
  
}

void baiscWifi::check(){
  if(WiFi.status()== WL_CONNECTED){
      tft.setCursor(53.3, 62.25);
      tft.print("Connected to ");
      tft.print(Network);
  }
  else {
    tft.setCursor(53.3, 62.25);
    tft.print("Not Conncted");
  }
}

void baiscWifi::Connect()
{
  WiFi.begin(ssid, password);
  tft.setCursor(53.3, 62.25);
  tft.print("Connecting... to %d ");
  tft.print(Network);
  while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  tft.fillRect(13.3, 41.25, 293.3, 187.5, BLACK);  //  Clear full page
  tft.setCursor(53.3, 62.25);
  tft.print("Connected to ");
  tft.print(Network);
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
}


Httprequest::Httprequest(){
  
}

String Httprequest::sendhttprequest(String url){
const char* root_ca= \
    "-----BEGIN CERTIFICATE-----\n" \
    "MIIFJTCCBA2gAwIBAgISBFoaVbSGcH2rauUVOmcnqst7MA0GCSqGSIb3DQEBCwUA\n" \
    "MDIxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQswCQYDVQQD\n" \
    "EwJSMzAeFw0yMTAzMTEwNDQ3MjVaFw0yMTA2MDkwNDQ3MjVaMBoxGDAWBgNVBAMT\n" \
    "D2lvdC5hbC1hbWVlbi5pbjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB\n" \
    "AKjtF9DfxWgRhfZrTz5xPQ27dcslSNVJHh6L7gI5CvAQ427s3mi2x3QLJ4pOQy+t\n" \
    "74hNqEx4TRezpiObCvv21/ZRL5ZzqWRnRGv85Z8IiW+zM0ESpxVU3eRdJmuIrlFh\n" \
    "gY1BzJWPGOeCys+JRgBGn7xwY8+RMqK2GSxm3zqsnXMFPIILzgdbkleAon3y9fg9\n" \
    "VaZzkUKsBDd8bDgRL1lY/uSkfZ0vblQP59BcCIzMWKdgbY59P3F6MxPRqFM1s4m5\n" \
    "lkHrdHvj3reB5o+8QmGZR5PnLpvBptltZjLYjSpPb67kaUaT3Z3113K/mXFlFccc\n" \
    "5TervqLTUv2n0n970+e0iFsCAwEAAaOCAkswggJHMA4GA1UdDwEB/wQEAwIFoDAd\n" \
    "BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwDAYDVR0TAQH/BAIwADAdBgNV\n" \
    "HQ4EFgQUMzbN6rqMIEW1MMSMVB98dCcV/5kwHwYDVR0jBBgwFoAUFC6zF7dYVsuu\n" \
    "UAlA5h+vnYsUwsYwVQYIKwYBBQUHAQEESTBHMCEGCCsGAQUFBzABhhVodHRwOi8v\n" \
    "cjMuby5sZW5jci5vcmcwIgYIKwYBBQUHMAKGFmh0dHA6Ly9yMy5pLmxlbmNyLm9y\n" \
    "Zy8wGgYDVR0RBBMwEYIPaW90LmFsLWFtZWVuLmluMEwGA1UdIARFMEMwCAYGZ4EM\n" \
    "AQIBMDcGCysGAQQBgt8TAQEBMCgwJgYIKwYBBQUHAgEWGmh0dHA6Ly9jcHMubGV0\n" \
    "c2VuY3J5cHQub3JnMIIBBQYKKwYBBAHWeQIEAgSB9gSB8wDxAHYAXNxDkv7mq0VE\n" \
    "sV6a1FbmEDf71fpH3KFzlLJe5vbHDsoAAAF4H9NPzwAABAMARzBFAiAlXS63X5xx\n" \
    "M/rsiaXl7zjns9TW5pBwck0Uiumc8McRJQIhAOBimdnbwOEgPb/2sUif00lABlMX\n" \
    "/HnrCFvD1tWaLsTAAHcA9lyUL9F3MCIUVBgIMJRWjuNNExkzv98MLyALzE7xZOMA\n" \
    "AAF4H9NPuAAABAMASDBGAiEAyRiThNkz3y1CXIGl30VnFbSaPSD6DbbkB7GssS29\n" \
    "+loCIQD2wshib9DxB3awQQmDx/p9wruHMyPIH+95tTSd7joYlTANBgkqhkiG9w0B\n" \
    "AQsFAAOCAQEABfSf6GvJyAV/EWuXEz1GI4mUZhWjuFQMzcGnCjTdiAyRpheZXqFa\n" \
    "ARencI1dvKDlUHGK2iBUSbuhbPDhk+sqiOhP5RB7rBCFHfLp4x062tA3XCGTTnKi\n" \
    "ugiZWFTK7cJvqCfkqOKpVIoATKLYOhq/Xo+erb7uwKbTPGmKgvIBi5HmWNs4ewXF\n" \
    "B+SAzl/K93bjXAFqBBGBzCVYaN8i15zoyqvg/6RH4C0T07CYAFaqKNdsx167jmIU\n" \
    "yyu0BMkyK1ZuGiHh9OY6wx22lwnTUsmlbXWoQXEWD/YSCRj7x47LTMrVfSPSmmex\n" \
    "QvrLMbwOCPzdV4B/u+RdNQ+1vPvv5JXzJw==\n" \
    "-----END CERTIFICATE-----\n" ;
  

    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      
      
      // Your Domain name with URL path or IP address with path
      http.begin(url);
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        return payload;
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
//        return httpResponseCode;
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
