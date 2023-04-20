#!/bin/bash

source env/bin/activate

xvfb-run --server-args='-core -noreset -screen 0 640x480x24' --server-num=101 autotest -R test_SimpleRandomTest -n $1 -a $2 -w $3 -o $4_results

echo hello
