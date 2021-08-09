cmake_minimum_required(VERSION 3.11.0)
project(FrazStructs VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  message("-- Compiling with MSVC")
  add_compile_options(-W4)
  string(REGEX REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  message("-- Compiling with Clang")
  add_compile_options(-Wall -Wextra -Werror -Wdouble-promotion -fno-common -Wno-sign-compare)
else()
  message("-- Compiling with GCC")
  add_compile_options(-Wall -Wextra -Werror -Wdouble-promotion -Wconversion -fno-common -Wno-sign-compare)
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
include(FetchContent)
include(GoogleTest)
enable_testing()

add_library(Vector INTERFACE)
target_include_directories(Vector INTERFACE include/Vector)

add_library(LinkedList INTERFACE)
target_include_directories(LinkedList INTERFACE include/LinkedList)

file(GLOB_RECURSE test_files
     "tests/*.cpp"
)

file(GLOB_RECURSE src_files
     "src/*.cpp"
)

file(GLOB_RECURSE include_files
     "include/*.hpp"
)

add_subdirectory(tests)

add_executable(${PROJECT_NAME} ${src_files} )
target_link_libraries(${PROJECT_NAME} Vector LinkedList)

clangformat_setup(
  ${test_files}
  ${src_files}
  ${include_files}
)