cmake_minimum_required(VERSION 3.5)

project(observer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(observer main.cpp
                      inc/filelogger.h
                      inc/isubscriber.h
                      inc/ipublisher.h
                      src/publisher.h
                      src/subscriber.h
)

include_directories( inc/
                     src/)

include(GNUInstallDirs)
install(TARGETS observer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
