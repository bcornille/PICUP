/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Fields class.
 *
 * Contents:
 *  * Fields::Fields(const Mesh &mesh) generic template implemenation
 *  * Fields::accumulateCharge generic template implemenation
 *  * Instantiation templates:
 *    * <int, double>
 *
 **********************************************************************/
#include "fields.hpp"

template <typename PosInd, typename PosVec>
Fields<PosInd, PosVec>::
Fields(const Mesh<PosInd, PosVec> &mesh) : field_mesh(mesh),
	potential(Eigen::VectorXd::Constant(mesh.getNumMeshpoints(), 0.0)),
	rho_q(Eigen::VectorXd::Constant(mesh.getNumMeshpoints(), 0.0)),
	e_field(mesh.getNumMeshpoints(), Eigen::Vector3d::Zero()),
	b_field(mesh.getNumMeshpoints(), Eigen::Vector3d::Zero()),
	j_q(mesh.getNumMeshpoints(), Eigen::Vector3d::Zero())
{}

template <typename PosInd, typename PosVec>
template <typename VelVec>
void Fields<PosInd, PosVec>::
accumulateCharge(const Particles<PosVec, VelVec> &particles)
{
	// Query charge of the particle species.
	double q = particles.getCharge();
	// Get reference to the list of particle positions.
	const std::vector<PosVec, Eigen::aligned_allocator<PosVec> > &x
		= particles.getPositions();
	// Get reference to the list of cells occumpied by particles.
	const std::vector<int> &cells = particles.getCells();
	// Loop over particles.
	for (int i = 0; i < particles.getNumParticles(); i++) {
		// Loop over vertices of the cell that the particle is in.
		for (const int &l : field_mesh.getVertices(cells[i])) {
			rho_q[l] += q*field_mesh.getWeight(l);
		}
	}
}

template <typename PosInd, typename PosVec>
void Fields<PosInd, PosVec>::solvePoisson()
{
	potential = field_mesh.laplace_solver.solve(rho_q);
}

/* Only the Mesh<int, double> class is instantiated so we can only
 * instantiate the corresponding Fields template. */
template class Fields<int, double>;
