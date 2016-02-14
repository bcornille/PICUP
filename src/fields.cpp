/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the *Field classes.
 *
 * Contents:
 *  * ScalarField
 *
 **********************************************************************/
#include "fields.hpp"

template <typename PosInd, typename PosVec>
PotentialField<PosInd, PosVec>::
PotentialField(const Mesh<PosInd, PosVec> &mesh) : field_mesh(&mesh),
	potential(mesh.getNumMeshpoints(), 0.0),
	rho_q(mesh.getNumMeshpoints(), 0.0)
{}

template class PotentialField<int, double>;
