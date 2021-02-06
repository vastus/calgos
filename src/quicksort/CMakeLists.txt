add_executable(quicksort
  quicksort.c
  )

target_include_directories(quicksort
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
  )

install(
  TARGETS quicksort
  DESTINATION bin
  )
