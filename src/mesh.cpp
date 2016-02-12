/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Mesh template
 * class.
 *
 * Contents:
 *  * Mesh() implementation
 *
 **********************************************************************/
#include "mesh.hpp"

template <typename PosInd, typename PosVec>
Mesh<PosInd, PosVec>::Mesh() : num_meshpoints(0) {}

template <typename PosInd, typename PosVec>
int Mesh<PosInd, PosVec>::getNumMeshpoints() { return num_meshpoints; }

template <typename PosInd, typename PosVec>
void Mesh<PosInd, PosVec>::
generateMesh(PosInd N, PosVec xmin, PosVec xmax) {}

//! Specialized mesh setup routine for Mesh<int, double>.
/*!
 * This is the setup routine for a one-dimensional mesh.
 *
 * \param int N
 * \param double xmin
 * \param double xmax
 *
 * Currently it is implemented to generate an evenly spaced mesh from
 * \p xmin to \p xmax with \p N total meshpoints.
 */
template <>
void Mesh<int, double>::
generateMesh(int N, double xmin, double xmax)
{
	num_meshpoints = N;
	num_indices = num_meshpoints;
	indices.resize(num_meshpoints);
	coordinates.resize(num_meshpoints);
	double dx = (N - 1)/(xmax - xmin);
	for (int i=0; i < num_meshpoints; i++)
	{
		indices[i] = i;
		coordinates[i] = xmin + dx*i;
	}
}
