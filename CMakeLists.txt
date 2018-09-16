cmake_minimum_required(VERSION 3.1)

project(gainput-test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads)
find_library(GAINPUT_LIB gainput HINTS /usr/local/lib)
find_library(X11_LIB X11 HINTS /usr/lib/x86_64-linux-gnu)

include_directories("include" "/usr/local/include/" "/usr/include/")

file(GLOB_RECURSE HRP_GROUND_SRC "src/*.cpp")
add_executable(${PROJECT_NAME} ${HRP_GROUND_SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${PROJECT_NAME} PUBLIC ${GAINPUT_LIB})
target_link_libraries(${PROJECT_NAME} PUBLIC ${X11_LIB})
