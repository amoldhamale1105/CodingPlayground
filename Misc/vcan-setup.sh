#!/bin/bash

#Install can-utils
apt update -y
apt -y install can-utils

#Enable virtual CAN
modprobe vcan
ip link add dev vcan0 type vcan
ip link set vcan0 up