#!/bin/bash
wget -P .. https://raw.githubusercontent.com/ClintonCMOs/alx-low_level_programming/master/0x18-dynamic_libraries/test.so
export LD_PRELOAD="$PWD/../test.so"

