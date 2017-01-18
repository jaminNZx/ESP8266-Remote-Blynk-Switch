# ESP8266-Remote-Blynk-Switch
A simple AC switch using an ESP8266 with Blynk mobile app interface. 

You could use this to control ANY AC or DC load up to the rated value of your relay. 

I have it controlling my garden lights, and even have my DIY ESP8266 Gate Counter and Logger triggering the lights when the gate is opened so you can see where you're going at night. 

You could use it to turn on a coffee maker (soo cliche), turn on the TV when you're not home, or use it to turn off and on lights. Anything really! 

I hacked it in to a 4way power board so I could turn on and off everything plugged in to it at once (again, good for mulitple sets of garden lights).

Feel free to make pull requests if you wish to help develop it. 

There is also a support thread on the Blynk community forums: http://community.blynk.cc/t/mini-esp8266-relay-controlled-ac-power-strip-sonoff-duplicate/9549

![Blynk Dash](http://i.imgur.com/Ez9L1wl.png?1)

## Hardware

* [ESP8266 Mini Dev Board (WeMos clone or other)](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20170114172728&SearchText=esp8266+mini)
* [5VDC Relay Module (with 3.3V level shifter)](https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20170114172728&SearchText=5vdc+relay+module)
* Small project case

### Software

* [Blynk](http://www.blynk.cc/) Mobile App ([iOS](https://itunes.apple.com/us/app/blynk-iot-for-arduino-rpi/id808760481?mt=8) & [Android](https://play.google.com/store/apps/details?id=cc.blynk&hl=en))
* Arduino IDE 1.6.9+
* The project sketch INO

## Wiring

![Wiring diagram](http://community.blynk.cc/uploads/default/original/2X/6/6d62d1d80a1afce405fe832198adab7e5745addc.png)

## Setup

### Libraries

* Blynk Library
* ArduinoOTA
* SimpleTimer 

### Tutorial

* Open the Blynk mobile app and create a new project by scanning the following QR code

![Project QR Code](http://i.imgur.com/BWQowpv.jpg?1)

* Send yourself the generated auth code
* Paste your auth code in to the sketch

```cpp
char auth[] = "xxxxx";
```

* Enter your wifi SSID and PASS

```cpp
char ssid[] = "xxxxx";
char pass[] = "xxxxx";
```

* Upload the sketch to your ESP8266
* Load the Blynk project and hit the PLAY button

