#external directory
cmake .. -DCMAKE_INSTALL_PREFIX=./_install
#install on computer
cmake -DCMAKE_INSTALL_PREFIX=/usr/local/

cmake .
make
sudo make install
