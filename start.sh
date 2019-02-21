#!/bin/sh

echo "Starting sensor monitor"
touch /data/sensorlog.log
./sensorapp | teet /data/sensorlog.log 
#./monitor/monitorapp > /data/monitorapp.log &

#echo "starting go app"
#./app

