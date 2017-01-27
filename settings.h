/**************************************************************
 *
 *                          Settings
 *
 **************************************************************/
/*
     Blynk Auth Code
*/
  #define AUTH                  "b9af72dccede40e195093c149688c4fb"
/*
   Wifi Credentials
*/
  #define WIFI_SSID             "PrettyFlyForAWiFi"
  #define WIFI_PASS             "custom2015"
/*
   Over The Air Hostname. 
*/
  #define OTA_HOSTNAME          "REMOTE-SWITCH"
/*
   Local Server Settings (uncomment to use local server)
*/
#define USE_LOCAL_SERVER
#define SERVER                  IPAddress(192, 168, 1, 2)
/*
   Hardware Pins
*/
#define SWITCH_PIN              14 // D5
/*
   Virtual Pins - Base
*/
#define vPIN_BUTTON_TIMEOUT     V0 
#define vPIN_BUTTON_MANUAL      V1 
#define vPIN_TIME               V2 
#define vPIN_LED                V3 
#define vPIN_TIMEOUT            V4 
#define vPIN_INFO               V5
