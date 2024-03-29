/**
 * pholib/src/application.cpp
 * Copyright (c) 2019 Vushu <danvu.hustle@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/**
 * File              : application.cpp
 * Author            : Vushu <danvu.hustle@gmail.com>
 * Date              : 22.11.2019
 * Last Modified Date: 22.11.2019
 * Last Modified By  : Vushu <danvu.hustle@gmail.com>
 */
#include "pholib/core/application.h"
#include "pholib/core/log.h"
//#include ""
namespace pholib {

    Application::Application() {
        Log::init();
    }

    Application::~Application() {
    }

    void Application::run() {
        is_running = true;
        PHO_INFO("PhoLib App Running");
        while (is_running) {

        }
        PHO_INFO("PhoLib App Ended");
    }

    void Application::stop(){
        is_running = false;
    }

}



