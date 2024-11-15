#!/bin/bash
i=9
while [ $i -ne 0 ];
do
echo "1)Add 2)Sub 3)Multi 4)div"
read op
echo "Enter a and b"
read a
read b
if (($op==1)) 
then
	echo "sum= $((a+b))"	
elif (($op==2))  
then
	echo "diffrence= $((a-b))"
elif (($op==3))  
then
	echo "product= $((a*b))"	
elif (($op==4))  
then
	echo "quotient= $((a/b))"
else 
	echo exiting
	i=0
fi
done
