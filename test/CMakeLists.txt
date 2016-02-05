# Enable testing
enable_testing()

# Add Googlet Test and Google Mock
add_subdirectory(googletest)

# Setup Testing
include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
