#!/bin/sh

echo "Starting sensor monitor"
./monitor/monitorapp > /data/monitorapp.log &

echo "starting go app"
./app

