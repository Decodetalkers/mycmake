cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 
add_subdirectory(plugins/types)
add_subdirectory(plugins/videos)
add_executable(
	${PROJECT_NAME}
	train.h
	train.cpp
	main.cpp
)
target_link_libraries(
	${PROJECT_NAME}
	types
	videos
	sound
	libsvm
	libcsv
)
