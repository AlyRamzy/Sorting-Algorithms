#!/bin/bash
inputs=(1000 5000 10000 50000 75000  100000 500000)
for ((i=0;i<5;i++))
do
	for((j=0;j<${#inputs[@]};j++))
	do

	python runscript.py ${inputs[$j]} data.txt
	./a.out ${i} data.txt output.txt time.txt 

	done
done


