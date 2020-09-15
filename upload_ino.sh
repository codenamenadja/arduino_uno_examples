#!/bin/sh
arduino-cli upload -p $1 --fqbn arduino:avr:uno $2
