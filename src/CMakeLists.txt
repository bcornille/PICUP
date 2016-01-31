# Set to only use MPL2 liscensed portions of the Eigen teplate library.
add_definitions(-DEIGEN_MPL2_ONLY)

# Main program executable.
add_executable(PICUP PICUP.cpp)
