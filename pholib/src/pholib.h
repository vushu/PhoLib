#ifndef PHO_H
#define PHO_H
#include <iostream>

void hello() {
    std::cout << "hello!" << std::endl;
}

void helloAgain() {
    hello();
    hello();
}

#include "common/application.h"

#endif
