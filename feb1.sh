#!/bin/bash

echo 
echo '### Trying "$*"'
for arg in "$*"
do
	echo $arg
done

echo '### Trying "$@"'
for arg in "$@"
do 
	echo $arg
done

echo '### Trying $*'
for arg in $*
do
	echo $arg
done

echo '### Trying $@'
for arg in $@
do
	echo $arg
done
