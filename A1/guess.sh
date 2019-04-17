#!/bin/bash

clear

rand=$(($RANDOM%64))
let rand=$rand+1

echo Welcome to the number game. I have a number, guess it!
echo Guess a number between 1 and 64.
#echo $rand
read guess

for i in 1 2 3 4 5 6
do
	if [ $guess -eq $rand ]
	then
		echo You won!
		break
	elif [ $guess -gt $rand ]
	then
		if [ $i -eq 6 ]
		then
			echo You lost.
			break
		fi

		echo Too big. 
		echo Try again.
		read guess
	else
		if [ $i -eq 6 ]
		then
			echo You lost.
			break
		fi
		echo Too small 
		echo Try again.
		read guess
	fi
done
