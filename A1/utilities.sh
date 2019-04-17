#!/bin/bash

option=0

while [ $option -ne 5 ]; do
	clear
	echo "-----------------------------------------"
	echo "            M A I N - M E N U            "
	echo "-----------------------------------------"
	echo
	echo "1. Ongoing Processor Activity"
	echo "2. Users currently logged in"
	echo "3. Number of users currently logged in"
	echo "4. Users with bash shell"
	echo "5. Exit"
	echo 
	echo "-----------------------------------------"
	echo
	echo "Please enter option [1 - 5]:"
	read option;
	
	case $option in
		1) top;;
		2) who | cut -d " " -f 1 | sort | uniq;;
		3) who | wc -l;;
		4) ps aux | grep bash | grep -v grep | cut -d " " -f 1 | sort | uniq;;
		5) exit;;
		*) echo "Please choose an option between 1 and 5";;
	esac
		
	echo "Press [enter] key to continue..."
	read space
done

