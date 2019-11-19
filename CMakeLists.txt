# CMakeList.txt : CMake project for PracticeC, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(Cpractice)
# Add source to this project's executable.
add_subdirectory(DSpractice)
add_executable (Cpractice "Cpractice.cpp")

target_link_libraries(Cpractice PUBLIC DSpractice)

target_include_directories(Cpractice PUBLIC 
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/DSpractice")
# TODO: Add tests and install targets if needed.
