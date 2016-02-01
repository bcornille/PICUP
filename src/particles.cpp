/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Particles
 * template class.
 *
 * Contents:
 *
 **********************************************************************/
#include "particles.hpp"

/*
template <typename Vector>
Particles<Vector>::Particles()
{
	num_particles = 0;
	positions = NULL;
	velocities = NULL;
}
*/

template <typename Vector>
Particles<Vector>::Particles(int N)
{
	num_particles = N;
	positions = new Vector[N];
	velocities = new Vector[N];
}

template <typename Vector>
Particles<Vector>::~Particles()
{
	delete[] positions;
	positions = NULL;
	delete[] velocities;
	velocities = NULL;
	num_particles = 0;
}

template <typename Vector>
int Particles<Vector>::getNumParticles() { return num_particles; }

template class Particles<double>;
//template class Particles<Vector3d>;
