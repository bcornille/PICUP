/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Mesh template
 * class.
 *
 * Contents:
 *  * Mesh(PosInd N) implementation; where PosInd can be:
 *    * int
 *    * Vector2i
 *    * Vector3i
 *
 **********************************************************************/
#include "mesh.hpp"

template <typename PosVec>
Mesh<int, PosVec>::Mesh(int N)
{
	num_meshpoints = N;
	indices.resize(N);
	coordinates.resize(N);
}

template <typename PosVec>
Mesh<Vector2i, PosVec>::Mesh(Vector2i N)
{
	num_meshpoints = N;
	indices.resize(N(0)*N(1));
	coordinates.resize(N(0)*N(1));
}

template <typename PosVec>
Mesh<Vector3i, PosVec>::Mesh(Vector3i N)
{
	num_meshpoints = N;
	indices.resize(N(0)*N(1)*N(2));
	coordinates.resize(N(0)*N(1)*N(2));
}
