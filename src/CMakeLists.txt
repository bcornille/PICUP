# Set to only use MPL2 liscensed portions of the Eigen teplate library.
add_definitions(-DEIGEN_MPL2_ONLY)

add_library(particles STATIC particles.cpp)
add_library(mesh STATIC mesh.cpp)

# Main program executable.
add_executable(PICUP PICUP.cpp)
target_link_libraries(PICUP particles mesh)
