cmake_minimum_required(VERSION 3.21)
project(shit2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.76.0 )

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(shit2 main.cpp RSP/ReedsShepp.cpp RSP/ReedsShepp.h)
    target_link_libraries(shit2 ${Boost_LIBRARIES})
endif()

