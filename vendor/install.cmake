# spdlog

set(SPDLOG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)

message(${SPDLOG_INCLUDE_DIR})

install(DIRECTORY ${SPDLOG_INCLUDE_DIR}/spdlog DESTINATION include)

# Setup a target

add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE
    $<BUILD_INTERFACE:${SPDLOG_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>)

install(TARGETS spdlog EXPORT spdlog-config DESTINATION include)
