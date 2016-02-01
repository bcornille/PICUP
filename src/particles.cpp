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

template <typename PosVec, typename VelVec>
Particles<PosVec, VelVec>::Particles(int N)
{
	num_particles = N;
	positions.resize(N);
	velocities.resize(N);
}

template <typename PosVec, typename VelVec>
Particles<PosVec, VelVec>::~Particles()
{
	num_particles = 0;
}

template <typename PosVec, typename VelVec>
int Particles<PosVec, VelVec>::getNumParticles() { return num_particles; }

/* These templates need to be instantiated so that classes of these
 * types my be used elsewhere in the code. */
// For 1-D PIC runs.
template class Particles<double, double>;
// For 1-1/2-D PIC runs.
template class Particles<double, Eigen::Vector2d>;
// For 1-2/2-D PIC runs.
template class Particles<double, Eigen::Vector3d>;
// For 2-D PIC runs.
template class Particles<Eigen::Vector2d, Eigen::Vector2d>;
// For 2-1/2-D PIC runs.
template class Particles<Eigen::Vector2d, Eigen::Vector3d>;
// For 3-D PIC runs.
template class Particles<Eigen::Vector3d, Eigen::Vector3d>;
