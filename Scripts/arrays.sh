#!/bin/bash

echo "Declare Array Variables: "; 
read TEXT;
a=(${TEXT});

echo "Which element do you wish to print to console? ";
read NUMBER;

echo "Your choice of element $NUMBER in the array 'a' is storing the value: ${a[${NUMBER}]}"
