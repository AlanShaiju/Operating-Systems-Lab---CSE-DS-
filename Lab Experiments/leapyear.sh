#!/bin/bash
echo "Enter the year"
read y
if ((y%4==0))
then
	echo "$y is a leap year"
else 	
	echo "$y is not a leap year"
fi
