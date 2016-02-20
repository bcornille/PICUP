#include "gtest.h"
#include "fields.hpp"
#include <new>
#include <stdexcept>

class MeshTest : public ::testing::Test
{
	protected:
		Mesh<int, double> mesh_test;

		virtual void SetUp()
		{
			mesh_test.generateMesh(100, 0.0, 1.0);
		}
};

TEST_F(MeshTest, MeshGeneration)
{
	EXPECT_EQ(100, mesh_test.getNumMeshpoints());
}

TEST_F(MeshTest, MeshVertices)
{
	int cell = 50;
	std::vector<int> vertices {cell, cell + 1};
	EXPECT_EQ(vertices, mesh_test.getVertices(cell));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
