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

template <>
void Mesh<int, double>::
generateMesh(int N, double xmin, double xmax)
{
	num_meshpoints = N;
	num_indices = N;
	indices.resize(num_meshpoints);
	coordinates.resize(num_meshpoints);
}
