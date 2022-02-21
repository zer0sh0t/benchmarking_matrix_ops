#!/usr/bin/bash
set -e
if [[ $1 == "" || $2 == "" || $3 == "" ]]
then
    echo "usage: bash benchmark.sh <num_rows_of_matrix> <num_cols_of_matrix> <num_iters>"
else
    g++ eigen_test.cpp -o temp.out 
    ./temp.out $1 $2 $3
    rm temp.out
    python numpy_test.py $1 $2 $3
fi
