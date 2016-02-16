#include "gtest.h"
#include "fields.hpp"
#include <new>
#include <stdexcept>

TEST(FieldsTest, MeshGeneration)
{
	Mesh<int, double> mesh_test;
	EXPECT_EQ(0, mesh_test.getNumMeshpoints());
	EXPECT_THROW(mesh_test.generateMesh(-1, 0.0, 1.0), std::bad_alloc);
	EXPECT_EQ(0, mesh_test.getNumMeshpoints());
	EXPECT_THROW(mesh_test.generateMesh(100, 1.0, 0.0),
			std::invalid_argument);
	mesh_test.generateMesh(100, 0.0, 1.0);
	EXPECT_EQ(100, mesh_test.getNumMeshpoints());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
