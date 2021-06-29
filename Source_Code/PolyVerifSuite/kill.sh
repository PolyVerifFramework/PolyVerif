#!/usr/bin

read pid < "pid/data"
kill -9  $pid
