#!/bin/bash

if [ $# -eq 0 ]; then
	echo "No arguments supplied"
else
	for i in $@
		do
			touch "$i.c"
		done
fi