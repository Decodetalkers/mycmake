project(videos)
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
file(GLOB MP4 "mp4/*")
file(GLOB MOV "mov/*")
add_library(${PROJECT_NAME}
	STATIC
	video
	base_video.h
	video.cpp	
	${MP4}
	${MOV}
)
target_include_directories(${PROJECT_NAME} PUBLIC .) #${INCLUDE_DIRECTORIES})
