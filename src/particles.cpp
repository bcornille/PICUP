/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Species
 * template class.
 *
 * Contents:
 *  * Species::Species(double q, double m) generic template
 *      implementation
 *  * Species::getNumParticles() generic template implemenation
 *  * Species::getCharge() generic template implemenation
 *  * Species::getParticles() generic template implemenation
 *  * Instantiated templates
 *    * <double, double>
 *
 **********************************************************************/
#include "particles.hpp"

template <typename PosVec, typename VelVec>
Species<PosVec, VelVec>::Species(double q, double m)
	: num_particles(0), charge(q), mass(m), qm_ratio(q/m) {}

template <typename PosVec, typename VelVec>
int Species<PosVec, VelVec>::
getNumParticles() const { return num_particles; }

template <typename PosVec, typename VelVec>
double Species<PosVec, VelVec>::
getCharge() const { return charge; }

template <typename PosVec, typename VelVec>
const std::vector<Particle<PosVec, VelVec> >& Species<PosVec, VelVec>::
getParticles() const { return particle_list; }

template <typename PosVec, typename VelVec>
template <typename PosInd>
void Species<PosVec, VelVec>::
generateParticles(int N, Mesh<PosInd, PosVec> &mesh)
{
	num_particles = N;
	particle_list.resize(N);
	for(int i = 0; i < N; i++)
	{
		particle_list[i].position = mesh.sampleMesh();
		particle_list[i].cell = mesh.getCell(particle_list[i].position);
	}
}

template <typename PosVec, typename VelVec>
void Species<PosVec, VelVec>::sortParticles()
{
	std::sort(particle_list.begin(), particle_list.end());
}

/* These templates need to be instantiated so that classes of these
 * types my be used elsewhere in the code. */
// For 1-D PIC runs.
template class Species<double, double>;
template void Species<double, double>::
generateParticles<int>(int N, Mesh<int, double> &mesh);
// For 1-1/2-D PIC runs.
// template class Species<double, Eigen::Vector2d>;
// For 1-2/2-D PIC runs.
// template class Species<double, Eigen::Vector3d>;
// For 2-D PIC runs.
// template class Species<Eigen::Vector2d, Eigen::Vector2d>;
// For 2-1/2-D PIC runs.
// template class Species<Eigen::Vector2d, Eigen::Vector3d>;
// For 3-D PIC runs.
// template class Species<Eigen::Vector3d, Eigen::Vector3d>;
