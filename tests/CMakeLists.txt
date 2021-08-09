cmake_minimum_required(VERSION 3.11.0)

project(Tests)

set(CMAKE_CXX_STANDARD 17)

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
  option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
  option(INSTALL_GTEST "Enable installation of googletest." OFF)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

include_directories(../include)

file(GLOB Sources
     *.cpp
)

add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} gtest_main)

gtest_discover_tests(${PROJECT_NAME})

# target_clangformat_setup(${PROJECT_NAME})