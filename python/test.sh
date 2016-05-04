#!/bin/sh

for i in $(seq 1 10);
    do
        echo "Hello" | nc localhost 10000;
    done
