#!/bin/bash

g++ example.cpp -I.. -std=c++11 -o app.out
if [ $? -eq 0 ]; 
then
  ./app.out > console.log
  cat console.log
fi


