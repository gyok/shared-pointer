cmake_minimum_required(VERSION 3.10.2)

project(mySharedPointer CXX)

set(SHAREDPOINTER "SharedPointer.h")
add_library(sharedPointer STATIC ${SHAREDPOINTER})
set_target_properties(sharedPointer PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} sharedPointer)
