# Make Google Test and Google Mock library.
set(GTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/gtest PARENT_SCOPE)
set(GMOCK_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}gmock PARENT_SCOPE)
add_definitions(-DGTEST_HAS_PTHREAD=0)
add_library(gmock-gtest-all STATIC gmock-gtest-all.cc)
