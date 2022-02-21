#!/usr/bin/bash
set -e
wget https://raw.githubusercontent.com/zer0sh0t/miscellaneous_stuff/master/get_eigen.sh
bash get_eigen.sh
rm get_eigen.sh
pip install numpy
