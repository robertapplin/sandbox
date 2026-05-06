cmake_minimum_required(VERSION 3.20)

project(MyApp
	VERSION 0.1.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create library for application code
add_library(my_app_lib
	src/Calculations.cpp
)

target_include_directories(my_app_lib PUBLIC
	inc/
)

# Create executable as an entry point for the application
add_executable(my_app main.cpp)

target_link_libraries(my_app PRIVATE my_app_lib)

# Enable testing
enable_testing()

add_subdirectory(tests)
