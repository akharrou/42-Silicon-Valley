#!/bin/bash
# Preferences Backup folder
S="$HOME/Desktop/Setup/Profiles/gene_pref/"
# Application Preferences Backup folder
A="$HOME/Desktop/Setup/Profiles/app_pref/"
d="$(ls -tr "$S" | tail -1)"
k="$(ls -tr "$A" | tail -1)"
for file in "$S""$d"/*
do
    printf "\x1B[32m█"
    sleep .1
    cp -rf "${file}" ~/Library/Preferences/
done
printf "\033[0;91m\nFile restored with success in Preferences\n\n\033[32m"
for file in "$A""$k"/*
do
    printf "\x1B[32m█"
    sleep .1
    cp -rf "${file}" ~/Library/Application\ Support/
done
printf "\033[0;91m\nFile restored with success in Application support\n\n\033[0m"


# ____________Set mouse and keyboard settings________________
defaults write -g com.apple.mouse.scaling -float 8.5 2> /dev/null
defaults write -g InitialKeyRepeat -int 10 2> /dev/null
#defaults write -g KeyRepeat -int 1 2> /dev/null
echo "Keyboard and mouse settings restored!"

#____________Mouse right click__________________________________
defaults write com.apple.driver.AppleBluetoothMultitouch.mouse Button2 -int 2

#enabled Dark Mode
# Toggle dark mode
osascript -e 'tell application "System Events" to tell appearance preferences to set dark mode to not dark mode'

# Enable dark mode, even it it's already enabled
osascript -e 'tell application "System Events" to tell appearance preferences to set dark mode to true'

defaults write /Library/Preferences/.GlobalPreferences #com.apple.autologout.AutoLogOutDelay -int 5000
defaults write /Library/Preferences/.GlobalPreferences com.apple.securitypref.logoutvalue -int 5000

# Boot out user
i="5"
while [ $i -gt 0 ]
do
    printf "\033[0;95mYour session will Lougout in: \033[0;106m$i"
    sleep 1
    printf "\r"
    i=$[$i-1]
done
launchctl bootout gui/"$(id -u "$USER")"
