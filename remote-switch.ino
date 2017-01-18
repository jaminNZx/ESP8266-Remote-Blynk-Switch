#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
/****************************************************************************/
char auth[] = "xxxxxxxxxxxxxxxxxxx";
char ssid[] = "xxxxxxxxxxxxxxxxxxx";
char pass[] = "xxxxxxxxxxxxxxxxxxx";
#define switchPin 14 // Pin D5 on ESP Dev/WeMos Mini
int switchState, timer1, switchDelay;
SimpleTimer timer;
/****************************************************************************/
void setup() {
  WiFi.mode(WIFI_STA);
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 2));
  while (Blynk.connect() == false) {}
  ArduinoOTA.setHostname("Remote-Switch-1"); // OPTIONAL
  ArduinoOTA.begin();
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
  switchDelay = 60000;
  Blynk.syncVirtual(4);
  timer.setInterval(2000L, sendWifi);
}
/****************************************************************************/
void sendWifi() {
  Blynk.virtualWrite(5, map(WiFi.RSSI(), -105, -40, 0, 100) );
}
/****************************************************************************/
BLYNK_WRITE(0) { // remote delay switch
  if (digitalRead(switchPin)) {
    toggleSwitchON();
    timer.setTimeout(switchDelay, toggleSwitchOFF);
  }
}
BLYNK_WRITE(1) { // manual button
  toggleSwitch(param.asInt());
}
BLYNK_WRITE(2) { // timer switch
  if (param.asInt()) {
    toggleSwitchON();
  } else {
    toggleSwitchOFF();
  }
}
BLYNK_WRITE(4) {
  switchDelay = param[0].asInt() * 60000;
}

void toggleSwitchOFF() {
  digitalWrite(switchPin, 1);
  Blynk.virtualWrite(1, 0);
  Blynk.virtualWrite(3, 0);
}

void toggleSwitchON() {
  digitalWrite(switchPin, 0);
  Blynk.virtualWrite(1, 1);
  Blynk.virtualWrite(3, 255);
}

void toggleSwitch(bool state) {
  digitalWrite(switchPin, !state);
  switchState = digitalRead(switchPin);
  if (!switchState) {
    switchState = 255;
  }
  Blynk.virtualWrite(3, switchState);
}

void loop() {
  Blynk.run();
  ArduinoOTA.handle();
  timer.run();
}
