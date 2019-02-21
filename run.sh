#!/bin/sh

echo "Starting sensor monitor"
touch /data/monitorapp.log
./monitor/monitorapp > /data/monitorapp.log &

echo "starting go app"
./app

