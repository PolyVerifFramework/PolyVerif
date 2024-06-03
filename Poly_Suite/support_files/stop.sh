#!/bin/bash

ade_pid=`cat adePID`
echo $ade_pid
node_pid=`cat node_pid`
kill -9 $node_pid
kill -9 $ade_pid
gnome-terminal --tab --title="ADE Stop" --command="bash -c 'ade stop;exit;$SHELL'"

