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
#include <new>
#include <stdexcept>
#include <string>

template <typename PosInd, typename PosVec>
Mesh<PosInd, PosVec>::Mesh() : num_meshpoints(0) {}

template <typename PosInd, typename PosVec>
unsigned int Mesh<PosInd, PosVec>::getNumMeshpoints() const
{
	return num_meshpoints;
}

template <typename PosInd, typename PosVec>
void Mesh<PosInd, PosVec>::
generateMesh(PosInd N, PosVec xmin, PosVec xmax) {}

//! Specialized mesh setup routine for Mesh<int, double>.
/*!
 * This is the setup routine for a one-dimensional mesh.
 *
 * Currently it is implemented to generate an evenly spaced mesh from
 * \p xmin to \p xmax with \p N total meshpoints.
 *
 * The code is not currently safe to xmin > xmax and will not catch
 * this type of error. 
 *
 * \param N
 * \param xmin
 * \param xmax
 */
template <>
void Mesh<int, double>::
generateMesh(int N, double xmin, double xmax)
{
	// Resize (allocate) vector arrays.
	// Use the exceptions from resize to test valid N.
	indices.resize(N);
	coordinates.resize(N);
	// Check to make sure a valid mesh is created.
	// Have not decided on error checking system yet.
	if (xmin >= xmax)
		throw std::invalid_argument(
				"xmin >= xmax in Mesh<int, double>::generateMesh" );
	// Set number of meshpoints.
	num_meshpoints = N;
	// Only one indexing dimension.
	num_indices = num_meshpoints;
	// Calculate cell size.
	double dx = (N - 1)/(xmax - xmin);
	// Set the index and coordinate values.
	for (int i=0; i < num_meshpoints; i++)
	{
		indices[i] = i;
		coordinates[i] = xmin + dx*i;
	}
}

template class Mesh<int, double>;
