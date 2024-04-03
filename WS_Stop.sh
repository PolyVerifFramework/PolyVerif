#!/bin/bash

pid=$(<ppid)  
kill -9 $pid
