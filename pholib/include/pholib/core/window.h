#pragma once

#include "pholib/pholibpch.h"
#include "pholib/events/event.h"
#include <string>

namespace pholib {

    struct window_props {

        std::string title;
        unsigned int width;
        unsigned int height;

        window_props(const std::string& title = "pholib game", unsigned int width = 1280, unsigned int height = 720)
            : title(title), width(width), height(height) {

            }

    };

    class window{
        public:
            // constructors, asssignment, destructor
            window();
            window(const window&);
            window& operator=(const window&);
            ~window();

        private:

    };
}
