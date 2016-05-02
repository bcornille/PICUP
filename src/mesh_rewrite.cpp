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

Mesh1D::Mesh1D(int N, Vectord<1> xmin, Vectord<1> xmax) :
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
	if (xmin[0] >= xmax[0])
	{
		throw std::invalid_argument(
				"xmin >= xmax in Mesh<int, double>::generateMesh" );
	}
	// Cells are only evenly sized at the moment.
	double dx = (xmax[0] - xmin[0])/num_edges;
	Vectord<1> x(xmin);
	// Set the index and coordinate values.
	node_elements.reserve(N);
	vertices.push_back(VertexNode<1>(x));
	for (int i=1; i < num_vertices; i++)
	{
		x(0) = xmin[0] + dx*i;
		vertices.push_back(VertexNode<1>(x));
		edges.push_back(Edge<1>({&vertices[i-1], &vertices[i]}));
		node_elements.push_back(NodeElement1D(edges[i]));
	}
	// Set discrete Hodge star operator.
	// (In future may want to assemble this separately.)
	hodge_epsilon.setIdentity(N);
	hodge_epsilon = hodge_epsilon*(1.0/dx); // Missin epsilon_0.
	// Construct grad operator here.
	grad.resize(num_edges, num_vertices);
	grad.reserve(2*num_edges);
	for (int i=0; i < num_edges; i++)
	{
		grad.insert(i, i) = -1.0;
		grad.insert(i, i+1) = 1.0;
	}
	grad.makeCompressed();
}

std::vector<double> Mesh1D::getWeights() const
{
	std::vector<double> weights(num_edges);
	// The weights of one-dimensional cells are the lengths.
	for (int i = 0; i < num_edges; i++)
	{
		weights[i] = edges[i].getLength();
	}

	return weights;
}
