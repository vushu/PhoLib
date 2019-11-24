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
if [ ! -f ./compile_commands.json ]; then
    read -r -p "Do you want to add compile_commands.json to root? [y/N] " response

    case "$response" in
        [yY][eE][sS]|[yY])
            ln -s ./build/compile_commands.json ./
            ;;
        *)

            ;;
    esac

fi
#sudo make install
echo "To install to your system: sudo make install"

echo "Test by running ./build/bin/PhoSandbox"
