/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Particles
 * template class.
 *
 * Contents:
 *
 **********************************************************************/

Particles::Particles()
{
	num_particles = 0;
	positions = NULL;
	velocities = NULL;
}

Particles::Particles(int N)
{
	num_particles = N;
	positions = new Vector[N];
	velocities = new Vector[N];
}

Particles::~Particles()
{
	delete[] positions;
	delete[] velocities;
	num_particles = 0;
}
