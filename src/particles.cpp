/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Particles
 * template class.
 *
 * Contents:
 *  * Particles::Particles(double q, double m) generic template
 *      implementation
 *  * Particles::getNumParticles() generic template implemenation
 *  * Particles::getCharge() generic template implemenation
 *  * Particles::getPositions() generic template implemenation
 *  * Particles::getCells() generic template implemenation
 *  * Instantiated templates
 *    * <double, double>
 *    * <double, Eigen::Vector2d>
 *    * <dobule, Eigen::Vector3d>
 *    * <Eigen::Vector2d, Eigen::Vector2d>
 *    * <Eigen::Vector2d, Eigen::Vector3d>
 *    * <Eigen::Vector3d, Eigen::Vector3d>
 *
 **********************************************************************/
#include "particles.hpp"

template <typename PosVec, typename VelVec>
Particles<PosVec, VelVec>::Particles(double q, double m = 1.0)
	: num_particles(0), charge(q), mass(m), qm_ratio(q/m) {}

template <typename PosVec, typename VelVec>
int Particles<PosVec, VelVec>::
getNumParticles() const { return num_particles; }

template <typename PosVec, typename VelVec>
double Particles<PosVec, VelVec>::
getCharge() const { return charge; }

template <typename PosVec, typename VelVec>
const std::vector<PosVec, Eigen::aligned_allocator<PosVec> >&
Particles<PosVec, VelVec>::getPositions() const { return positions; }

template <typename PosVec, typename VelVec>
const std::vector<int>& Particles<PosVec, VelVec>::getCells() const
{
	return cell_index;
}

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
