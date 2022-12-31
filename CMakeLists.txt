cmake_minimum_required(VERSION 3.10)

project(etl CXX)

include(CTest)

include_directories( ${PROJECT_SOURCE_DIR} )

add_subdirectory(tests)
