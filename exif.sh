#!/bin/bash

fname=$1
if [ "$fname" = "conditions" ]
then	
	echo We found it
elif [ "$fname" = "something else" ]
then
	echo "Not there"
else
	echo "Nope"
fi
