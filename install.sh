#!/bin/bash

echo "Building and installing the coordinate library."
make
mv libcoordinate.so /usr/lib/
cp coordinate.h /usr/include/
echo "Finished installing.  To use library, add \'-lcoordinate\' as a flag"
