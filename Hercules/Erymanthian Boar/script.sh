#!/bin/sh

apt-get -qq install at -y
echo "touch newfile.txt ; echo '42' >> newfile.txt" | at 08:42 AM Dec 21
