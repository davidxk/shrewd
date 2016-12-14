#!/bin/bash

# Change extention recursively for all files in dir
# Usage: ./ch_ext.sh dir txt cpp

dir=$1
from=$2
to=$3
for each in $(find $dir -type f); do
	if [[ $each == *.$from ]]; then
		mv $each ${each%.$from}.$to
	fi
done
