cmake_minimum_required (VERSION 3.18)
project(aanetwork)
enable_testing()
enable_language(CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(INCLUDE_DIR /Users/toilettrauma/Desktop/myAppFrameworks/include)

# All following targets should search these directories for headers
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${INCLUDE_DIR}
  ${CURL_INCLUDE_DIR}
)

#########################################################################################
# Define Targets

set(CMAKE_INSTALL_PREFIX "iosbuild")

file(GLOB_RECURSE HeaderFileList "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB_RECURSE SourceFileList "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${PROJECT_NAME} STATIC ${HeaderFileList} ${SourceFileList} ${OBJCSourceFileList})

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib/static)

