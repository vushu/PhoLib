/**
 * pholib/include/PhoLib/log.h
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
 * File              : log.h
 * Author            : Vushu <danvu.hustle@gmail.com>
 * Date              : 22.11.2019
 * Last Modified Date: 22.11.2019
 * Last Modified By  : Vushu <danvu.hustle@gmail.com>
 */
#pragma once
#include "pholib/pholibpch.h"
#include "spdlog/logger.h"


namespace pholib {

    class Log{
        public:
            // constructors, asssignment, destructor
            static void init();
            inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
            inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }
        private:
            static std::shared_ptr<spdlog::logger> s_core_logger;
            static std::shared_ptr<spdlog::logger> s_client_logger;

    };
}

// core macros
//
#define PHO_CORE_TRACE(...) ::pholib::Log::get_core_logger()->trace(__VA_ARGS__)
#define PHO_CORE_ERROR(...) ::pholib::Log::get_core_logger()->error(__VA_ARGS__)
#define PHO_CORE_WARN(...) ::pholib::Log::get_core_logger()->warn(__VA_ARGS__)
#define PHO_CORE_INFO(...) ::pholib::Log::get_core_logger()->info(__VA_ARGS__)
#define PHO_CORE_FATAL(...) ::pholib::Log::get_core_logger()->fatal(__VA_ARGS__)

// client macros
#define PHO_TRACE(...) ::pholib::Log::get_client_logger()->trace(__VA_ARGS__)
#define PHO_ERROR(...) ::pholib::Log::get_client_logger()->error(__VA_ARGS__)
#define PHO_WARN(...) ::pholib::Log::get_client_logger()->warn(__VA_ARGS__)
#define PHO_INFO(...) ::pholib::Log::get_client_logger()->info(__VA_ARGS__)
#define PHO_FATAL(...) ::pholib::Log::get_client_logger()->fatal(__VA_ARGS__)

