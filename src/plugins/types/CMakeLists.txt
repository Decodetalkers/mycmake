project(types)
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_library(${PROJECT_NAME}
	STATIC
	types
	types.cpp	
)
target_include_directories(${PROJECT_NAME} PUBLIC .) #${INCLUDE_DIRECTORIES})
