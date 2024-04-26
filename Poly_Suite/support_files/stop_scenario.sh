#!/bin/bash

pid=19940

value=`cat pidfile`
per_node_pid=`cat per_node_pid`
node_pid=`cat node_pid`
echo $per_node_pid
echo "PID about to stop : $pid"
kill -9 $per_node_pid
kill -9 $node_pid

#kill -9 $pid
#echo $value
#kill -KILL -$value

exit


