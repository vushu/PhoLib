cmake_minimum_required(VERSION 3.15)

project(PhoGameLibrary)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(vendor/install.cmake)

add_subdirectory(pholib)
add_subdirectory(sandbox)


install(EXPORT spdlog-config DESTINATION share/glad/cmake)
install(EXPORT glad-config DESTINATION share/spdlog/cmake)
install(EXPORT PhoLibConfig DESTINATION share/PhoLib/cmake)

