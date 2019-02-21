#!/bin/sh

echo "Starting sensor monitor"
touch /data/monitorapp.log
./monitorapp 
#./monitor/monitorapp > /data/monitorapp.log &

#echo "starting go app"
#./app

