#include "gtest.h"
#include "particles.hpp"

TEST(ParticlesTest, LargeConstructor)
{
	Particles<double, double> particles_11d_test(1000, 1.0, 1.0);
	EXPECT_EQ (1000, particles_11d_test.getNumParticles());
	Particles<double, Eigen::Vector2d>
		particles_12d_test(1000, 1.0, 1.0);
	EXPECT_EQ (1000, particles_12d_test.getNumParticles());
	Particles<double, Eigen::Vector3d>
		particles_13d_test(1000, 1.0, 1.0);
	EXPECT_EQ (1000, particles_13d_test.getNumParticles());
	Particles<Eigen::Vector2d, Eigen::Vector2d>
		particles_22d_test(1000, 1.0, 1.0);
	EXPECT_EQ (1000, particles_22d_test.getNumParticles());
	Particles<Eigen::Vector2d, Eigen::Vector3d>
		particles_23d_test(1000, 1.0, 1.0);
	EXPECT_EQ (1000, particles_23d_test.getNumParticles());
	Particles<Eigen::Vector3d, Eigen::Vector3d>
		particles_33d_test(1000, 1.0, 1.0);
	EXPECT_EQ (1000, particles_33d_test.getNumParticles());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
