cmake_minimum_required(VERSION 3.0)

project(project)
set(CMAKE_CXX_STANDARD 14)



add_executable(project main.cpp)
set(SFML_STATIC_LIBRARIS TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)


include_directories(C:/SFML/include)
target_link_libraries(project sfml-system sfml-window sfml-graphics sfml-audio sfml-network)