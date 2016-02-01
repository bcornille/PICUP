/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Particles
 * template class.
 *
 * Contents:
 *  * Particles(int N) implementation
 *  * ~Particles() implementation
 *  * getNumParticles() implemenation
 *  * Intantiated templates
 *    * double
 *    * Eigen::Vector2d
 *    * Eigen::Vector3d
 *
 **********************************************************************/
#include "particles.hpp"

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

/* These templates need to be instantiated so that classes of these
 * types my be used elsewhere in the code. */
template class Particles<double>;			//< For 1D PIC runs.
template class Particles<Eigen::Vector2d>;	//< For 2D PIC runs.
template class Particles<Eigen::Vector3d>;	//< For 3D PIC runs.
