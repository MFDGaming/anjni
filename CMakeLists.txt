cmake_minimum_required (VERSION 3.5)

project(anjni LANGUAGES C)

file(GLOB_RECURSE ANJNI_SRC anjni/*.c)

add_library(anjni ${ANJNI_SRC})
target_include_directories(anjni PUBLIC ${PROJECT_SOURCE_DIR})