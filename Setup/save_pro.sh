#!/bin/bash

#Create System Preferences Backup folder
S="$HOME/Desktop/Setup/Profiles/gene_pref/"

#Create Application Preferences Backup folder
A="$HOME/Desktop/Setup/Profiles/app_pref/"

clear
d="$(date +"%d-%m-%Y")"
mkdir -p "$S"/"$d"
#Create system Preferences Backup folder
mkdir -p "$A"/"$d"

for file in ~/Library/Preferences/*
do
	printf "\x1B[32m█"
	sleep .05
	cp -rf "${file}" "$S"/"$d"/ 2>/dev/null
done
printf "\nGeneral Preference Saved. 😃 \n\n"

for file in ~/Library/Application\ Support/*
do
	printf "\x1B[22m█"
	sleep .1
	cp -rf "${file}" "$A"/"$d"/ 2>/dev/null
done
printf "\nGeneral App_preference Saved. 😃 \n\n"
