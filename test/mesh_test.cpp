#include "gtest.h"
#include "mesh.hpp"
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
	std::vector<int> vertices {cell - 1, cell, cell + 1, cell + 2};
	EXPECT_EQ(vertices, mesh_test.getVertices(cell));
}

TEST_F(MeshTest, MeshWeight)
{
	int vert = 50;
	double x = 0.5;
	EXPECT_NEAR(0.5, mesh_test.getWeight(x, vert), 1.0e-14);
}

TEST_F(MeshTest, MeshLaplace)
{
	EXPECT_NO_THROW(mesh_test.generateLaplace());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
