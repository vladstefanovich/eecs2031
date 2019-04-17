#!/bin/bash

value1=$1
operand=$2
value2=$3

if [ -z $1 ] || [ -z $2 ] || [ -z $3 ]
then
	echo "Usage - ./calculator.sh value1 operator value2"
	echo "where,"
	echo "value1: numeric value"
	echo "value2: numeric value"
	echo "operator: one of +,-,/,x"
elif [ $3 -eq 0 ] && [ $2 = "/" ]
then
	echo "Division-by-zero Error!"
elif [ $operand = "x" ]
then
	let answer=$value1"*"$value2
	echo $answer
else
	let answer=$value1$operand$value2
	echo $answer
fi
