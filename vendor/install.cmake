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


#GLAD

set(GLAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/include)
install(DIRECTORY ${GLAD_INCLUDE_DIR}/glad DESTINATION include)

add_library(glad INTERFACE)
target_include_directories(glad INTERFACE
    $<BUILD_INTERFACE:${GLAD_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>)

install(TARGETS glad EXPORT glad-config DESTINATION include)
