#!/bin/sh
ifconfig -a link | grep ether | sed 's/ether//g' | cut -c3-
