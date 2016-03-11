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
 *  * Mesh<int, double>::generateLaplace() implementation
 *  * Mesh<int, double>::sampleMesh() implementation
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

/* This generic template should never be called or generated. An
 * assert has been added to make sure a specialized mesh generation
 * function is implemented for each type combination. */
template <typename PosInd, typename PosVec>
void Mesh<PosInd, PosVec>::generateLaplace()
{
	assert(false);
}

/* This generic template should never be called or generated. An
 * assert has been added to make sure a specialized mesh generation
 * function is implemented for each type combination. */
template <typename PosInd, typename PosVec>
PosVec Mesh<PosInd, PosVec>::sampleMesh()
{
	assert(false);
}

/* This generic template should never be called or generated. An
 * assert has been added to make sure a specialized mesh generation
 * function is implemented for each type combination. */
template <typename PosInd, typename PosVec>
int Mesh<PosInd, PosVec>::getCell(PosVec x) const
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
 *
 * \throws std::invalid_argument
 */
template <>
void Mesh<int, double>::
generateMesh(int N, double xmin, double xmax)
{
	// Check to make sure a valid mesh is created.
	// Check that N is positive so mesh arrays can be allocated.
	if (N <= 0)
	{
		throw
		{
			std::invalid_argument(
				"N is not positive in Mesh<int, double>::generateMesh");
		}
	}
	/* Check that xmin < xmax so coordinates are monotonically
	 * increasing. */
	if (xmin >= xmax)
	{
		throw
		{
			std::invalid_argument(
					"xmin >= xmax in Mesh<int, double>::generateMesh" );
		}
	}
	// Set number of meshpoints.
	num_meshpoints = N;
	// Set number of cells.
	num_cells = N - 1;
	// Only one indexing dimension.
	num_indices = num_meshpoints;
	// Resize (allocate) vector arrays.
	coordinates.resize(num_meshpoints);
	laplace.resize(num_meshpoints, num_meshpoints);
	// Calculate cell size.
	// Cells are only evenly sized at the moment.
	double dx = (xmax - xmin)/(N - 1);
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
	assert( (cell >= 0) && (cell < num_cells) );
	// Create vector to be returned.
	std::vector<int> vertices {cell - 1, cell, cell + 1, cell + 2};
	if (cell == 0) vertices.erase(vertices.begin());
	if (cell > num_cells - 2) vertices.pop_back();
	if (cell > num_cells - 1) vertices.pop_back();
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
	/* While dx is constant for an evenly spaced mesh it is not saved.
	 * This is because an evenly spaced mesh is not expected to be
	 * permanent. This calculation also assumes the particle size is
	 * equal to the mesh spacing. */
	double xi_diff = std::abs(x - coordinates[vert])
		/(coordinates[vert] - coordinates[vert-1]);
	if (xi_diff < 0.5)
	{
		return 0.75 - xi_diff*xi_diff;
	}
	else if( xi_diff > 1.5)
	{ 
		return 0.0;
	}
	else
	{
		return 0.5*xi_diff*xi_diff - 1.5*xi_diff + 1.125;
	}
}

//! Generates the Laplace operator for the mesh.
/*!
 * The Laplace operator matrix is produced for a mesh that is assumed to
 * be evenly spaced linear elements.
 *
 * \throws laplace_solver.info()
 */
template <>
void Mesh<int, double>::generateLaplace()
{
	// Assume all element sizes are equal.
	double dx = coordinates[1] - coordinates[0];
	/* Eigen claims that this method is efficient for populating the
	 * matrix. */
	laplace.reserve(Eigen::VectorXi::Constant(num_meshpoints, 3));
	for(int i = 0; i < num_meshpoints; i++)
	{
		if(i == 0)
		{
			laplace.insert(i, i) = 2.0/dx;
			laplace.insert(i, i+1) = -1.0/dx;
		}
		else if(i == num_meshpoints - 1)
		{
			laplace.insert(i, i-1) = -1.0/dx;
			laplace.insert(i, i) = 2.0/dx;
		}
		else
		{
			laplace.insert(i, i-1) = -1.0/dx;
			laplace.insert(i, i) = 2.0/dx;
			laplace.insert(i, i+1) = -1.0/dx;
		}
	}
	// Must compress the matrix before factorizing it.
	laplace.makeCompressed();
	// Calls analyze and factorize.
	laplace_solver.compute(laplace);
	if(laplace_solver.info() != Eigen::ComputationInfo::Success)
	{
		throw laplace_solver.info();
	}
}

//! Randomly samples mesh region.
/*!
 * Uniformly distributed sampling of the mesh region. This may be a bad
 * way to sample the mesh because it is independent of the mesh elements
 * so an expensive step of finding the which mesh element the sampled
 * point occupies must be done afterward. While this doesn't pose an
 * issue for an evenly spaced mesh, the implementation and
 * standardization of this step may want to be reconsidered.
 */
template<>
double Mesh<int, double>::sampleMesh()
{
	return (coordinates[num_meshpoints - 1] - coordinates[0])
		*uniform_dist(generator) + coordinates[0];
}

template<>
int Mesh<int, double>::getCell(double x) const
{
	return static_cast<int>(std::floor((x - coordinates[0])
			/(coordinates[num_meshpoints - 1] - coordinates[0])
			*num_meshpoints));
}

/***********************************************************************
 * End specialized Mesh<int, double> routine definitions.
 **********************************************************************/

// Explicitly instantiated Mesh class templates.
template class Mesh<int, double>;
