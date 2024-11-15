#!/bin/bash
echo "enter maximum number"
read n
flag=0
# taking input from user
echo "enter Numbers in array:"
for (( i = 0; i < $n; i++ ))
do
read nos[$i]
done
#printing the number before sorting
echo "Numbers in an array are:"
for (( i = 0; i < $n; i++ ))
do
echo ${nos[$i]}
done
echo enter num
read num
for (( i = 0; i < $n; i++ ))
do
if((num==${nos[$i]}))
then 
	flag=$(($flag+1))
fi
done
echo occurance of $num =$flag
