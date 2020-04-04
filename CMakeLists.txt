cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)

# set the project name
project(3DReconstruct)

# add the executable
add_executable(reconstruct src/reconstruct.cpp src/Reconstructor.cpp src/SceneGraph.cpp src/Initializer.cpp src/KeyFrame.cpp)

find_package( OpenCV REQUIRED )
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    include
)
target_link_libraries(reconstruct ${OpenCV_LIBS} )
