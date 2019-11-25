cmake_minimum_required(VERSION 3.15)

set(PROJECT_VERSION "1.0.2")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)

set(PHOLIB_INCLUDE_DIRS
    include/pholib/pholibpch.h
    include/pholib/pholib.h
    include/pholib/core/application.h
    include/pholib/core/core.h
    include/pholib/core/log.h
    )

set(SOURCE_FILES
    src/core/log.cpp
    src/core/application.cpp
    )

file(GLOB ALL_SOURCES
    "*.h"
    "*.cpp"
    )

project(pholib VERSION ${PROJECT_VERSION} DESCRIPTION "PhoLib a simple and small library for game development")

file(GLOB_RECURSE source_list
    "${CMAKE_CURRENT_LIST_DIR}/src/core/*.cpp")

file(GLOB_RECURSE header_list
    "${CMAKE_CURRENT_LIST_DIR}/include/*.h")

add_library(${PROJECT_NAME} SHARED ${header_list} ${source_list})
#window compatibility
set(CMAKE_WINDOW_EXPORT_ALL_SYMBOLS ON)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# Let's set compiler-specific flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # G++
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    # MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT)
endif()


set_target_properties(${PROJECT_NAME}
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION})

#pkg config

#find_package(PkgConfig REQUIRED)

#pkg glfw3
#pkg_search_module(GLFW REQUIRED glfw3)

#include_directories(
    #${GLFW_INCLUDE_DIRS}
    #${SPDLOG_INCLUDE_DIR}
    #${GLAD_INCLUDE_DIR})

#target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} glfw spdlog)

install(TARGETS ${PROJECT_NAME} spdlog
    EXPORT pholibConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

export(TARGETS ${PROJECT_NAME} glfw spdlog FILE pholibConfig.cmake)

#install(EXPORT spdlog-config DESTINATION share/spdlog/cmake)
#install(EXPORT PhoLibConfig DESTINATION share/PhoLib/cmake)

