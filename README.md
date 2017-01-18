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

## Usage

The dash consists of a few buttons, LED and a slider. 
You have manual control via the MANUAL button. ON and OFF state. 
You can also trigger the device using the TRIGGER TIMEOUT button. It will activate the relay, then deactivate it after the period set by the slider.
The LED just shows the real time state of the relay.

# Deveoping Further

If you're just using this with manual control, then you can easily remove parts of the sketch as well as the dash widgets from the Blynk app. 

If you wish to toggle the relay from another ESP or hardware, then you will need to set up a Blynk Bridge between the two hardwares and make the call to V0. 

```cpp
bridge.virtualWrite(0,HIGH); 
```

Using the new multi-device features of the app, you could use the single Blynk dash to control as many remote switches around your home. This is great because as you can see in the first image, I have set it up to control mulitple zones around my house all from the same dash. 

If you run out of room, you could just add the TABS widget and build on another app page. 
