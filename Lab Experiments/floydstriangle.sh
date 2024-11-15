#!/bin/bash
echo "enter no. of lines"
read n
flag=1
for((i=0;i<n;i++))
do
	for((j=0;j<i+1;j++))
	do
		echo -n "$flag "
		flag=$((flag+1))
	done
	echo
done
