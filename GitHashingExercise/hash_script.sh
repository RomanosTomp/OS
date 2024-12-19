#!/bin/bash


#Checking for input
if [ -z "$1" ]; then
	echo "Give an input"
	exit 1
fi

#Taking as input a 4-digit number
if [[ ! $1 =~ ^[0-9]{4}$ ]]; then
	echo "Error: Input must be a 4-digit number."
	exit 1
fi

#Generate SHA-256 hash
hash=$(echo -n "$1" | sha256sum | awk '{print $1}')
printf "$hash" > hash_output.txt
echo "SHA-256 hash on hash_output.txt"
