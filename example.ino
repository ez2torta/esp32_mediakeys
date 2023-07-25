#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

const uint8_t* media_keys_total[16] = {
  KEY_MEDIA_NEXT_TRACK,
  KEY_MEDIA_PREVIOUS_TRACK,
  KEY_MEDIA_STOP,
  KEY_MEDIA_PLAY_PAUSE,
  KEY_MEDIA_MUTE,
  KEY_MEDIA_VOLUME_UP,
  KEY_MEDIA_VOLUME_DOWN,
  KEY_MEDIA_WWW_HOME,
  KEY_MEDIA_LOCAL_MACHINE_BROWSER,  // Opens "My Computer" on Windows,
  KEY_MEDIA_CALCULATOR,
  KEY_MEDIA_WWW_BOOKMARKS,
  KEY_MEDIA_WWW_SEARCH,
  KEY_MEDIA_WWW_STOP,
  KEY_MEDIA_WWW_BACK,
  KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION,  // Media Selection,
  KEY_MEDIA_EMAIL_READER,
};

const uint8_t* media_keys[6] = { KEY_MEDIA_CALCULATOR, KEY_MEDIA_LOCAL_MACHINE_BROWSER, KEY_MEDIA_VOLUME_UP, KEY_MEDIA_VOLUME_DOWN, KEY_MEDIA_MUTE, KEY_MEDIA_NEXT_TRACK };

const uint8_t* media_keys[6] = { KEY_MEDIA_CALCULATOR, KEY_MEDIA_LOCAL_MACHINE_BROWSER, KEY_MEDIA_VOLUME_UP, KEY_MEDIA_VOLUME_DOWN, KEY_MEDIA_MUTE, KEY_MEDIA_NEXT_TRACK };


int input_pins[6] = { 32, 33, 25, 26, 27, 14 };

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  Serial.println("Server started");

  // Configure the input pins
  for (int i = 0; i < 6; i++) {
    pinMode(input_pins[i], INPUT_PULLUP);
  }
}


void loop() {
  if (bleKeyboard.isConnected()) {
    // Read the input pins and write the values to the output pins
    for (int i = 0; i < 6; i++) {
      int input_value = digitalRead(input_pins[i]);
      if (input_value == LOW) {
        Serial.println("Sending Play/Pause media key...");
        bleKeyboard.write(media_keys[i]);
        delay(300);
      }
    }
  }
}
