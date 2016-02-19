/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Mesh template
 * class.
 *
 * Contents:
 *  * Mesh::Mesh() generic template implementation
 *  * Mesh::getNumMeshpoints() generic template implementation
 *  * Mesh::generateMesh(int N, double xmin, double xmax) implementation
 *  * Instantiated templates
 *    * <int, double>
 *
 **********************************************************************/
#include "mesh.hpp"
#include <new>
#include <stdexcept>
#include <string>
#include <cassert>

/***********************************************************************
 * Begin generalized template routine definitions.
 **********************************************************************/

template <typename PosInd, typename PosVec>
Mesh<PosInd, PosVec>::Mesh() : num_meshpoints(0), num_cells(0) {}

template <typename PosInd, typename PosVec>
int Mesh<PosInd, PosVec>::getNumMeshpoints() const
{
	return num_meshpoints;
}

template <typename PosInd, typename PosVec>
void Mesh<PosInd, PosVec>::
generateMesh(PosInd N, PosVec xmin, PosVec xmax) { assert(false); }

template <typename PosInd, typename PosVec>
std::vector<int> Mesh<PosInd, PosVec>::getVertices(int l) const
{
	assert(false);
}

/***********************************************************************
 * End generalized template routine definitions.
 **********************************************************************/

/***********************************************************************
 * Begin specialized Mesh<int, double> routine definitions.
 **********************************************************************/

//! Specialized mesh setup routine for Mesh<int, double>.
/*!
 * This is the setup routine for a one-dimensional mesh.
 *
 * Currently it is implemented to generate an evenly spaced mesh from
 * \p xmin to \p xmax with \p N total meshpoints.
 *
 * \param N
 * \param xmin
 * \param xmax
 */
template <>
void Mesh<int, double>::
generateMesh(int N, double xmin, double xmax)
{
	// Check to make sure a valid mesh is created.
	// Check that N is positive so mesh arrays can be allocated.
	if (N <= 0)
		throw std::invalid_argument(
			"N is not positive in Mesh<int, double>::generateMesh");
	/* Check that xmin < xmax so coordinates are monotonically
	 * increasing. */
	if (xmin >= xmax)
		throw std::invalid_argument(
				"xmin >= xmax in Mesh<int, double>::generateMesh" );
	// Set number of meshpoints.
	num_meshpoints = N;
	// Set number of cells.
	num_cells = N - 1;
	// Only one indexing dimension.
	num_indices = num_meshpoints;
	// Resize (allocate) vector arrays.
	coordinates.resize(num_meshpoints);
	// Calculate cell size.
	// Cells are only evenly sized at the moment.
	double dx = (N - 1)/(xmax - xmin);
	// Set the index and coordinate values.
	for (int i=0; i < num_meshpoints; i++)
	{
		coordinates[i] = xmin + dx*i;
	}
}

template <>
std::vector<int> Mesh<int, double>::getVertices(int l) const
{
	// Check to make sure the cell index is valid.
	assert( (l > 0) && (l < num_cells) );
	// Create vector to be returned.
	std::vector<int> vertices {l, l + 1};
	return vertices;
}

/***********************************************************************
 * End specialized Mesh<int, double> routine definitions.
 **********************************************************************/

template class Mesh<int, double>;
