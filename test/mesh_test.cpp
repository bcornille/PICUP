#include "gtest.h"
#include "mesh.hpp"

class MeshTest : public ::testing::Test
{
	protected:
		int N = 100;
		Mesh<int, double> mesh_test;

		virtual void SetUp()
		{
			try
			{
				mesh_test.generateMesh(N, 0.0, 1.0);
			}
			catch (std::invalid_argument &e)
			{
				std::cerr << "Invalid argument: " << e.what()
					<< std::endl;
			}
		}
};

TEST_F(MeshTest, MeshGeneration)
{
	EXPECT_EQ(N, mesh_test.getNumMeshpoints());
}

TEST_F(MeshTest, MeshVertices)
{
	int cell = N/2;
	std::vector<int> vertices {cell - 1, cell, cell + 1, cell + 2};
	EXPECT_EQ(vertices, mesh_test.getVertices(cell));

	cell = 0;
	vertices = std::vector<int> {cell, cell + 1, cell + 2};
	EXPECT_EQ(vertices, mesh_test.getVertices(cell));

	cell = N - 2;
	vertices = std::vector<int> {cell - 1, cell, cell + 1};
	EXPECT_EQ(vertices, mesh_test.getVertices(cell));
}

TEST_F(MeshTest, MeshWeight)
{
	int vert = N/2;
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
