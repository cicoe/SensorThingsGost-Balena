#!/bin/sh

echo "Starting sensor monitor"
touch /data/THlog.log
#./sensorapp | tee /data/sensorlog.log 
./sensorapp > /data/THlog.log &

echo "starting go app"
./app

