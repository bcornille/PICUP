add_library(particles STATIC mesh.cpp particles.cpp)
add_library(fields STATIC mesh.cpp fields.cpp)
#add_library(mesh_rewrite STATIC elements.cpp mesh_rewrite.cpp)
add_library(particles_rewrite STATIC random.cpp elements.cpp mesh_rewrite.cpp particles_rewrite.cpp)

# Main program executable.
add_executable(PICUP PICUP.cpp)
target_link_libraries(PICUP particles particles_rewrite)
