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

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

include_directories(include)

file(GLOB test_files
     "tests/*.cpp"
)

add_library(vector src/vector.cpp)
target_include_directories(vector PUBLIC include/vector)

add_executable(${PROJECT_NAME}_tests ${test_files})
target_link_libraries(${PROJECT_NAME}_tests gtest_main vector)

gtest_discover_tests(${PROJECT_NAME}_tests)

target_clangformat_setup(${PROJECT_NAME}_tests)