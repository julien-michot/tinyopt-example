cmake_minimum_required (VERSION 3.5)

project(tinyopt-example VERSION 0.0.1
                        DESCRIPTION "A Tinyopt Example Project"
                        LANGUAGES CXX)

# Compiler flags
set(CMAKE_CXX_STANDARD 20)

find_package(Eigen3) # Only needed if Tinyopt is not found locally

# Find Tinyopt, fetch it if not found
find_package(Tinyopt)

if (NOT Tinyopt_FOUND)
  message("Tinyopt not found locally, fetching it...")
  include(FetchContent)
  FetchContent_Declare(
      tinyopt
      GIT_REPOSITORY  https://github.com/julien-michot/tinyopt.git
      GIT_TAG         main
      GIT_SHALLOW     TRUE
      GIT_PROGRESS    TRUE
  )
  set(TINYOPT_BUILD_TESTS OFF)
  FetchContent_MakeAvailable(tinyopt)
else()
  message("Tinyopt found at ${Tinyopt_INCLUDE_DIRS}")
endif()

# Header-only library
add_executable(example src/example.cpp)
target_link_libraries(example PUBLIC tinyopt) # PULIC when Fetched, INTERFACE otherwise...
target_link_libraries(example PUBLIC Eigen3::Eigen)
