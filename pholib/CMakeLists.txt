cmake_minimum_required(VERSION 3.15)

set(PROJECT_VERSION "1.0.1")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
    src/pholib.h
    src/common/application.h
    src/common/core.h
    src/common/application.cpp
    )

project(pho VERSION ${PROJECT_VERSION} DESCRIPTION "phoLib a simple and small library for game development")

add_library(pho SHARED ${SOURCE_FILES})
#window compatibility
set(CMAKE_WINDOW_EXPORT_ALL_SYMBOLS ON)


#set_target_properties(mylib PROPERTIES SOVERSION 1)

#set_target_properties(pho PROPERTIES PUBLIC_HEADER src/pholib.h)

# private header
target_include_directories(pho PRIVATE .)

message(BUILDING_pho...)
# Let's set compiler-specific flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # G++
    target_compile_options(pho PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    # MSVC
    target_compile_options(pho PRIVATE /EHsc /MTd /W2 /c)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(pho PRIVATE WIN_EXPORT)
endif()

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set_target_properties(pho
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION})

#pkg config

find_package(PkgConfig REQUIRED)

#pkg glfw3
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#creating library

target_link_libraries(pho ${GLFW_LIBRARIES})

install(TARGETS pho DESTINATION lib)

install(FILES
    src/common/application.h
    src/common/core.h
    DESTINATION include/PhoLib/common)

install(FILES src/pholib.h DESTINATION include/PhoLib)

