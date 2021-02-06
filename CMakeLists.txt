cmake_minimum_required(VERSION 3.18)

project(calgos
  LANGUAGES C
  )

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

add_subdirectory(src/quicksort)
