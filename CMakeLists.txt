cmake_minimum_required(VERSION 3.10)

# Set the path to the CMake executable
set(CMAKE_COMMAND "C:/Users/night.LAPTOP-SVBS9GCE/Desktop/PRAKSE RTU/hz/bin/cmake.exe")

project(OpenCV-C-)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Add directory to enable OpenCV files
include_directories(${OpenCV_INCLUDE_DIRS})

# Add project file
add_executable(${PROJECT_NAME} src/Main.cpp)

# Project + OpenCV
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
