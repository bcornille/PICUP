#include "gtest.h"
#include "particles.hpp"

TEST(ParticlesTest, LargeConstructor)
{
	Particles<double> particles_1d_test(1000);
	EXPECT_EQ (1000, particles_1d_test.getNumParticles());
	Particles<Eigen::Vector2d> particles_2d_test(1000);
	EXPECT_EQ (1000, particles_2d_test.getNumParticles());
	Particles<Eigen::Vector3d> particles_3d_test(1000);
	EXPECT_EQ (1000, particles_3d_test.getNumParticles());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
