#pragma once
#include "spdlog/logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <memory>

namespace PhoLib {

    class Log{
        public:
            // constructors, asssignment, destructor
            static void init();
            inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
            inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }
        private:
            static std::shared_ptr<spdlog::logger> s_coreLogger;
            static std::shared_ptr<spdlog::logger> s_clientLogger;

    };
}


