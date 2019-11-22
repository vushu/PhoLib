cmake_minimum_required(VERSION 3.15)

set(PROJECT_VERSION "1.0.1")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)

set(PHOLIB_INCLUDE_DIRS
    include/PhoLib/pholib.h
    include/PhoLib/application.h
    include/PhoLib/core.h
    include/PhoLib/log.h
    )

set(SOURCE_FILES
    include/PhoLib/pholib.h
    include/PhoLib/application.h
    include/PhoLib/core.h
    include/PhoLib/log.h
    src/log.cpp
    src/application.cpp
    )

project(PhoLib VERSION ${PROJECT_VERSION} DESCRIPTION "PhoLib a simple and small library for game development")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
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

find_package(PkgConfig REQUIRED)

#pkg glfw3
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS} ${SPDLOG_INCLUDE_DIR})

#target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} spdlog)

install(TARGETS ${PROJECT_NAME} spdlog
    EXPORT PhoLibConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/phoLib)

export(TARGETS ${PROJECT_NAME} spdlog FILE PhoLibConfig.cmake)

#install(EXPORT PhoLibConfig DESTINATION share/PhoLib/cmake)

