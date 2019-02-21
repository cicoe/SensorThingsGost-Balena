#!/bin/sh

echo "Starting sensor monitor"
touch /data/sensorlog.log
#./sensorapp | tee /data/sensorlog.log 
./sensorapp > /data/sensorlog.log &

echo "starting go app"
./app

