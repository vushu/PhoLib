# spdlog

#if((NOT SPDLOG_INCLUDE_DIR) OR (NOT EXISTS ${SPDLOG_INCLUDE_DIR}))
#message("Unable to find spdlog, cloning...")

#execute_process(COMMAND git submodule update --init -- vendor/spdlog
    #WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


set(SPDLOG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)
    #CACHE PATH "spdlog include directory")

    #include_directories(${SPDLOG_INCLUDE_DIR})

message(${SPDLOG_INCLUDE_DIR})

install(DIRECTORY ${SPDLOG_INCLUDE_DIR}/spdlog DESTINATION include)

# Setup a target

add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE
    $<BUILD_INTERFACE:${SPDLOG_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>)

install(TARGETS spdlog EXPORT spdlog-config DESTINATION include)
#install(EXPORT spdlog-config DESTINATION share/spdlog/cmake)


#endif()
