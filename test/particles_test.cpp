#include "gtest.h"
#include "particles.hpp"

/*
TEST(ParticlesTest, NullConstructor)
{
	Particles<double> particles_test;
	EXPECT_EQ (0, particles_test.getNumParticles());
}
*/

TEST(ParticlesTest, LargeConstructor)
{
	Particles<double> particles_test(1000);
	EXPECT_EQ (1000, particles_test.getNumParticles());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
