#!/bin/bash

if [ ! $# -eq 1 ]
then
    echo "The format should be run.sh <filename>"
    return
fi

filename=$(echo $1 | cut -d'.' -f1)

g++ ./header.h $1 -o $filename