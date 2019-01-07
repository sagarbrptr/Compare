#!/bin/bash

#loop counter
y=0
g++ -std=c++11 test_generator.cpp -o ./test_generator 
g++ -std=c++11 first_program.cpp -o ./first_program 
g++ -std=c++11 second_program.cpp -o ./second_program 
while [ $y -lt 100000 ]
do 
	
	#test file
	
	./test_generator > t1 

	#program 1
	
	./first_program < t1 > o1

	#program 2
	
	./second_program < t1 > o2
	
	#compare o1 and o2
	if cmp -s "o1" "o2"
	then
		var=1
	else
	   echo "Differ at : "
	   cat t1
	   echo " "
	   echo " "
	   echo  "Code1 op : "
	   #echo " "
	   cat o1
	   echo " "
	   echo "Code2 op : "
	   #echo " "
	   cat o2
	   echo " " 
	   exit 0
	fi

	y=$((y+1))
	
done

echo "No differences found. EXIT!!!!!"
