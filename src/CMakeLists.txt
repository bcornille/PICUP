add_library(particles STATIC mesh.cpp particles.cpp)
add_library(fields STATIC mesh.cpp fields.cpp)

# Main program executable.
add_executable(PICUP PICUP.cpp)
target_link_libraries(PICUP particles fields)
