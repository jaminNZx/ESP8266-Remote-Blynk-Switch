#define BLYNK_PRINT Serial
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include "settings.h"
#include <wifi_credentials.h>

int switchState, timer1, switchDelay;
SimpleTimer timer;
WidgetBridge gate(vPIN_BRIDGE_GATE);

BLYNK_CONNECTED() {
  gate.setAuthToken("ae5eab51641343209ae3c2b139ef6e0b");
}

void sendWifi() {
  Blynk.setProperty(vPIN_INFO, "label", String("WIFI: ") + String(map(WiFi.RSSI(), -105, -40, 0, 100)) + String("% (") + WiFi.RSSI() + String("dB)") + String(" IP: ") + WiFi.localIP().toString());
}

BLYNK_WRITE(vPIN_BUTTON_TIMEOUT) { // remote delay switch
  if (digitalRead(SWITCH_PIN)) {
    Switch_ON();
    timer.setTimeout(switchDelay, Switch_OFF);
  }
}

BLYNK_WRITE(vPIN_BUTTON_MANUAL) { // manual button
  Switch_Toggle(param.asInt());
}

BLYNK_WRITE(vPIN_TIME) { // timer switch
  gate.virtualWrite(vPIN_BRIDGE_GATE, param.asInt());
  if (param.asInt()) {
    Switch_ON();
  } else {
    Switch_OFF();
  }
}

BLYNK_WRITE(vPIN_TIMEOUT) {
  switchDelay = param[0].asInt() * 60000;
}

void Switch_OFF() {
  digitalWrite(SWITCH_PIN, 1);
  Blynk.virtualWrite(vPIN_BUTTON_MANUAL, 0);
  Blynk.virtualWrite(vPIN_LED, 0);
}

void Switch_ON() {
  digitalWrite(SWITCH_PIN, 0);
  Blynk.virtualWrite(vPIN_BUTTON_MANUAL, 1);
  Blynk.virtualWrite(vPIN_LED, 255);
}

void Switch_Toggle(bool state) {
  digitalWrite(SWITCH_PIN, !state);
  switchState = digitalRead(SWITCH_PIN);
  if (!switchState) {
    switchState = 255;
  }
  Blynk.virtualWrite(vPIN_LED, switchState);
}

void setup() {
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
#ifdef LOCAL_SERVER
  Blynk.begin(AUTH, WIFI_SSID, WIFI_PASS, LOCAL_SERVER);
#else
  Blynk.begin(AUTH, WIFI_SSID, WIFI_PASS);
#endif
  while (Blynk.connect() == false) {}
  ArduinoOTA.setHostname(OTA_HOSTNAME);
  ArduinoOTA.begin();
  pinMode(SWITCH_PIN, OUTPUT);
  digitalWrite(SWITCH_PIN, HIGH);
  switchDelay = 60000;
  Blynk.syncVirtual(vPIN_TIMEOUT, vPIN_TIME);
  timer.setInterval(2000L, sendWifi);
}

void loop() {
  Blynk.run();
  ArduinoOTA.handle();
  timer.run();
}
