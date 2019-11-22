#!/bin/bash
# File              : build.sh
# Author            : Vushu <danvu.hustle@gmail.com>
# Date              : 19.11.2019
# Last Modified Date: 19.11.2019
# Last Modified By  : Vushu <danvu.hustle@gmail.com>


#rm CMakeCache.txt
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/

make
sudo make install

echo "Test by running ./build/bin/PhoSandbox"
