/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Mesh template
 * class.
 *
 * Contents:
 *  * Mesh::Mesh() generic template implementation
 *  * Mesh::getNumMeshpoints() generic template implementation
 *  * Mesh<int, double>::generateMesh(int N, double xmin, double xmax)
 *    implementation
 *  * Mesh<int, double>::getVertices(int cell) const implementation
 *  * Mesh<int, double>::getWeight(double x, int vert) const
 *    implementation
 *  * Instantiated templates
 *    * <int, double>
 *
 **********************************************************************/
#include "mesh.hpp"
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

/* This generic template should never be called or generated. An
 * assert has been added to make sure a specialized mesh generation
 * function is implemented for each type combination. */
template <typename PosInd, typename PosVec>
void Mesh<PosInd, PosVec>::
generateMesh(PosInd N, PosVec xmin, PosVec xmax) { assert(false); }

/* This generic template should never be called or generated. An
 * assert has been added to make sure a specialized mesh generation
 * function is implemented for each type combination. */
template <typename PosInd, typename PosVec>
std::vector<int> Mesh<PosInd, PosVec>::getVertices(int cell) const
{
	assert(false);
}

/* This generic template should never be called or generated. An
 * assert has been added to make sure a specialized mesh generation
 * function is implemented for each type combination. */
template <typename PosInd, typename PosVec>
double Mesh<PosInd, PosVec>::getWeight(PosVec x, int vert) const
{
	assert(false);
}

/***********************************************************************
 * End generalized template routine definitions.
 **********************************************************************/

/***********************************************************************
 * Begin specialized Mesh<int, double> routine definitions.
 **********************************************************************/

/*!
 * Specialized mesh setup routine for Mesh<int, double>.
 *
 * This is the setup routine for a one-dimensional mesh.
 *
 * Currently it is implemented to generate an evenly spaced mesh from
 * \p xmin to \p xmax with \p N total meshpoints.
 *
 * \param N number of mesh vertices
 * \param xmin minimum x coordinate
 * \param xmax maximum x coordinate
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

/*!
 * Specialized query of the list of vertices around a cell for
 * Mesh<int, double>.
 *
 * This queries the vertices of a sinple one-dimensional mesh. It needs
 * only return a vector with integers \p cell and
 * <CODE> cell + 1 </CODE>.
 *
 * \param cell index
 *
 * \returns <CODE> std::vector vertices {cell, cell + 1} </CODE>
 */
template <>
std::vector<int> Mesh<int, double>::getVertices(int cell) const
{
	// Check to make sure the cell index is valid.
	assert( (cell > 0) && (cell < num_cells) );
	// Create vector to be returned.
	std::vector<int> vertices {cell, cell + 1};
	return vertices;
}

/*!
 * Specialized calculation of the particle weighting for
 * Mesh<int, double>.
 *
 * Currently assumes square particle of the size of the cell it is in.
 *
 * \param x position of the particle
 * \param vert overall index of the vertex
 *
 * \returns <CODE> weight </CODE>
 */
template <>
double Mesh<int, double>::getWeight(double x, int vert) const
{
	// Get distance from vertex and test which side the particle is on.
	double x_diff = x - coordinates[vert];
	if (x_diff < 0) // Test if particle is behind vertex.
	{ // Use vert and vert-1 to calculate weight.
		return 1.0 - x_diff/(coordinates[vert] - coordinates[vert-1]);
	} else { // Use vert+1 and vert to calculate weight.
		return 1.0 - x_diff/(coordinates[vert+1] - coordinates[vert]);
	}
}

/***********************************************************************
 * End specialized Mesh<int, double> routine definitions.
 **********************************************************************/

// Explicitly instantiated Mesh class templates.
template class Mesh<int, double>;
