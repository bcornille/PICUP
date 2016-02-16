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

template class Fields<int, double>;
