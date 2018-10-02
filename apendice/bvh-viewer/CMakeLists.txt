cmake_minimum_required(VERSION 3.1)
project(bvh-viewer CXX)

set (CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})

file(GLOB files ${CMAKE_SOURCE_DIR}/bvh-viewer/*.cpp ${CMAKE_SOURCE_DIR}/bvh-viewer/*.h)

add_executable(bvh-viewer ${files})
target_link_libraries(bvh-viewer ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

file(COPY ${CMAKE_SOURCE_DIR}/sample.bvh DESTINATION ${CMAKE_BINARY_DIR})
