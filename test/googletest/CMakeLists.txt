# Make Google Test and Google Mock library.
set(GTEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
set(GMOCK_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/gmock)
add_library(gmock-gtest-all STATIC gmock-gtest-all.cc)
find_library(GMOCK_GTEST_LIBS gmock-gtest-all ${CMAKE_CURRENT_SOURCE_DIR})
