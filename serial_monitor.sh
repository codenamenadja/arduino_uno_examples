#!/bin/sh

sudo killall putty
sudo putty /dev/ttyACM0 -serial -sercfg 9600,8,n,1,N &
