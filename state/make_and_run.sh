#!/bin/bash

TARGET=application.out
OUTPUT_LOG=output.txt

g++ example.cpp -I.. -std=c++11 -o $TARGET
if [ $? -eq 0 ]; 
then
  ./$TARGET > $OUTPUT_LOG
  cat $OUTPUT_LOG
fi


