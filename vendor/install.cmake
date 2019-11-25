# spdlog

set(SPDLOG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)

#install(DIRECTORY ${SPDLOG_INCLUDE_DIR}/spdlog DESTINATION include)

# Setup a target

add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE
    $<BUILD_INTERFACE:${SPDLOG_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>)

install(TARGETS spdlog EXPORT spdlog-config DESTINATION include)


##GLAD

#set(GLAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/include)
##install(DIRECTORY ${GLAD_INCLUDE_DIR}/glad DESTINATION include)

#add_library(glad INTERFACE)
#target_include_directories(glad INTERFACE
    #$<BUILD_INTERFACE:${GLAD_INCLUDE_DIR}>
    #$<INSTALL_INTERFACE:include>)

#install(TARGETS glad EXPORT glad-config DESTINATION include/pholib)


#glad
#add_subdirectory(vendor/GLAD)
#include_directories(vendor/GLAD/include)

#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/GLFW)
include_directories(vendor/GLFW/include)


