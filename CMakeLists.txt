cmake_minimum_required(VERSION 3.0.2)
project(aa)
# ## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)
# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_FLAGS "-O3")

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS thread signals)

###########
## Build ##
###########
## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
include
)

add_executable(test_data_dispatcher
  src/test_data_dispatcher.cpp
)

target_link_libraries(test_data_dispatcher
  ${catkin_LIBRARIES}
  -pthread
)
