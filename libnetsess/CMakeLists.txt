cmake_minimum_required (VERSION 3.18)
project(netsess)
enable_testing()
enable_language(CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(INCLUDE_ROOT_DIR /Users/toilettrauma/Desktop/myAppFrameworks)
set(INCLUDE_DIR ${INCLUDE_ROOT_DIR}/include)
set(CURL_INCLUDE_DIR ${INCLUDE_ROOT_DIR}/curlpp/curl_include)

# All following targets should search these directories for headers
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${INCLUDE_DIR}
  ${CURL_INCLUDE_DIR}
)

#########################################################################################
# Define Targets

set(CMAKE_INSTALL_PREFIX "iosbuild")

file(GLOB_RECURSE HeaderFileList "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SourceFileList "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${HeaderFileList} ${SourceFileList} ${OBJCSourceFileList})

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib/static)

