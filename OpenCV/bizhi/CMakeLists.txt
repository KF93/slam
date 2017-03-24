cmake_minimum_required(VERSION 2.8)
project(image_vim)
set(CMAKE_CXX_FLAGS "-std=c++11")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(image_vim image_vim.cpp)
target_link_libraries(image_vim ${OpenCV_LIBS})

