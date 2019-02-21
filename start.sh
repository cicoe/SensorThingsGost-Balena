#!/bin/sh

echo "Starting sensor monitor"
touch /data/sensorlog.log
./sensorapp 
#./monitor/monitorapp > /data/monitorapp.log &

#echo "starting go app"
#./app

