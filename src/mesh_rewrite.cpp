/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Mesh template
 * class.
 *
 * Contents:
 *  *
 *
 **********************************************************************/

#include "mesh_rewrite.hpp"

Mesh1D::Mesh1D(int N, Vectord<1> xmin = Vectord<1>::Zero(),
		Vectord<1> xmax = Vectord<1>::Identity()) :
	num_vertices(N+1), num_edges(N)
{
	// Check to make sure a valid mesh is created.
	// Check that N is positive so mesh arrays can be allocated.
	if (N <= 0)
	{
		throw std::invalid_argument(
				"N is not positive in Mesh<int, double>::generateMesh");
	}
	/* Check that xmin < xmax so coordinates are monotonically
	 *  * increasing. */
	if (xmin >= xmax)
	{
		throw std::invalid_argument(
				"xmin >= xmax in Mesh<int, double>::generateMesh" );
	}
	// Cells are only evenly sized at the moment.
	double dx = (xmax[0] - xmin[0])/N;
	Vectord<1> x(xmin);
	// Set the index and coordinate values.
	mesh_nodes.resize(N+1);
	node_elements.reserve(N);
	for (int i=1; i < num_vertices; i++)
	{
		x(0) = xmin + dx*i;
		mesh_nodes[i] = x;
		node_elements.push_back({&(mesh_nodes[i-1]), &(mesh_nodes[i])});
	}
	// Set discrete Hodge star operator.
	hodge_epsilon.setIdentity(N);
	hodge_epsilon = hodge_epsilon/dx/dx; // Missin epsilon_0.
	// Construct grad operator here.
}
