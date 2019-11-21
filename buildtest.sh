#!/bin/bash
# File              : build.sh
# Author            : Vushu <danvu.hustle@gmail.com>
# Date              : 19.11.2019
# Last Modified Date: 19.11.2019
# Last Modified By  : Vushu <danvu.hustle@gmail.com>


rm CMakeCache.txt
cmake -DCMAKE_INSTALL_PREFIX=/_install
make
make install

