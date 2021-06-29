#!/bin/bash

echo "Hello from the shell script"
./a.out &
PID=$!
echo $PID > "pid/data"
echo "After while : " $PID
