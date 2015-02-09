project(RobotXMSER)
cmake_minimum_required(VERSION 2.8.12.2 FATAL_ERROR)

find_package(OpenCV REQUIRED)

# Project Executable
add_executable (main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
