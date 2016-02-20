# Add Googlet Test and Google Mock
add_subdirectory(googletest)

# Setup Testing
include_directories(${SRC_DIR} ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

add_executable(particles_tests particles_test.cpp)
add_executable(mesh_tests mesh_test.cpp)

find_library(GMOCK_GTEST_LIBS gmock-gtest-all ${CMAKE_CURRENT_SOURCE_DIR})
find_library(PARTICLES particles ${SRC_DIR})
target_link_libraries(particles_tests gmock-gtest-all particles)

find_library(FIELDS fields ${SRC_DIR})
target_link_libraries(mesh_tests gmock-gtest-all fields)

add_test(NAME ParticlesTests COMMAND particles_tests)
add_test(NAME FieldsTests COMMAND fields_tests)
