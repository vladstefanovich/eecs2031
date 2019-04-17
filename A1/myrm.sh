#!/bin/bash

mkdir -p /tmp/vlad98/eecs2031m/a1/recycle-bin

arg=$1
if [ -z $arg ] 
then
	echo "Error: no target specified"
	echo "Usage: ./myrm <files>"
else
	for arg in "$@"
	do
		echo deleting $arg
		mv $arg /tmp/vlad98/eecs2031m/a1/recycle-bin
	done		
fi
