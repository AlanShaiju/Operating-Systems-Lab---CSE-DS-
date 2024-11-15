#!/bin/bash
echo enter number
read num
flag=9
x=$num/2
for((i=2;i<x+1;i++))
do
	if(($num%$i==0))
	then
		flag=0
	fi
done
if((flag==0))
then
	echo not prime
else
	echo  prime
fi
