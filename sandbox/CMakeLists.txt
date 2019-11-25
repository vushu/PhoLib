cmake_minimum_required(VERSION 3.15)

project(PhoSandbox)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
    src/sandbox_app.cpp
    )

add_executable(PhoSandbox ${SOURCE_FILES})

target_link_libraries(PhoSandbox pholib)

