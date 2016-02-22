/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Fields class.
 *
 * Contents:
 *  * Fields::Fields(const Mesh &mesh) generic template implemenation
 *
 **********************************************************************/
#include "fields.hpp"

template <typename PosInd, typename PosVec>
Fields<PosInd, PosVec>::
Fields(const Mesh<PosInd, PosVec> &mesh) : field_mesh(mesh),
	potential(mesh.getNumMeshpoints(), 0.0),
	rho_q(mesh.getNumMeshpoints(), 0.0),
	e_field(mesh.getNumMeshpoints(), Eigen::Vector3d::Zero()),
	b_field(mesh.getNumMeshpoints(), Eigen::Vector3d::Zero()),
	j_q(mesh.getNumMeshpoints(), Eigen::Vector3d::Zero())
{}

template <typename PosInd, typename PosVec>
template <typename VelVec>
void Fields<PosInd, PosVec>::
accumulateCharge(const Particles<PosVec, VelVec>& particles)
{
	double q = particles.getCharge();
	const std::vector<PosVec, Eigen::aligned_allocator<PosVec> > &x
		= particles.getPositions();
	const std::vector<int> &cells = particles.getCells();
	for (int i = 0; i < particles.getNumParticles(); i++)
	{
		for (const int &l : field_mesh.getVertices(cells[i]))
		{
			rho_q[l] += q; // This will need a weight, but that
			               // functionality is not yet in Mesh.
		}
	}
}

template class Fields<int, double>;
