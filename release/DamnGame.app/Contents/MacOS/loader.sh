#!/bin/sh
export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:${PWD}/../lib
export DYLD_FRAMEWORK_PATH=$DYLD_FRAMEWORK_PATH:${PWD}/../Frameworks
./LemonGame
