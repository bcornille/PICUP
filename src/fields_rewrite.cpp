/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Fields class.
 *
 * Contents:
 *
 **********************************************************************/
#include "fields.hpp"

template<pdim>
Fields<pdim>::Fields(const Mesh<pdim> &mesh) : field_mesh(mesh),
	potential(Eigen::VectorXd::Constant(mesh.getNumMeshPoints(), 0.0)),
	rho_q(Eigen::VectorXd::Constant(mesh.getNumMeshPoints(), 0.0)),
	e_field(Eigen::VectorXd::Constant(mesh.getNumMeshEdges(), 0.0)),
	b_field(Eigen::VectorXd::Constant(mesh.getNumMeshFaces(), 0.0)),
	j_q(Eigen::VectorXd::Constant(mesh.getNumMeshEdges(), 0.0))
{}

template<pdim>
void Fields<pdim>::accumulateCharge(const Species<pdim> &particles)
{
	// Query charge of the particle species.
	double q = particles.getCharge();
	// Get reference to the list of particles.
	const std::vector<Particle<pdim> > &part_list
		= particles.getParticles();
	// Loop over particles.
	for (int i = 0; i < particles.getNumParticles(); i++)
	{
		/* generate vector of std::pair<int, double> containing the
		 * vertex IDs and q weights */
	}
}
