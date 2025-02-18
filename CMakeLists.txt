cmake_minimum_required(VERSION 3.10)
project(PhysicsSimulator)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics)

add_executable(PhysicsSimulator main.cpp World.cpp Ball.cpp Painter.cpp)

target_link_libraries(PhysicsSimulator sfml-graphics)