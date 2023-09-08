cmake_minimum_required(VERSION 3.5)

project(state_machine_lockup_table LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(state_machine_lockup_table main.cpp)

include(GNUInstallDirs)
install(TARGETS state_machine_lockup_table
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
