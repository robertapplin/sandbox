cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(QtGuiThread)

find_package(
  Qt5
  COMPONENTS Core Gui Widgets
  REQUIRED
)

add_subdirectory(option1)
add_subdirectory(option2)
