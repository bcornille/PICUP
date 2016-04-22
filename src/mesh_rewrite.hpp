/*!
 * \file
 * \brief Mesh header file.
 *
 * Contents:
 *  * Mesh class
 *
 */

#include <vector>
#include <random>
#include "elements.hpp"

#ifndef _mesh_hpp
#define _mesh_hpp

class Mesh1D
{
	private:
		/*! Number of vertices defining the primal mesh. */
		const int num_vertices;
		/*! Number of edges defined on the primal mesh. */
		const int num_edges;

		/*! Vector containing all the mesh nodes. */
		std::vector<VertexNode<1> > mesh_nodes;

		/*! Vector containing the 1-dimensional Whitney 0-form
		 * elements. These should be identical to 1st order linear
		 * elements in 1-dimension.*/
		std::vector<NodeElement1D> node_elements;

		/*! Matrix representing the discrete Hodge star operator
		 * including the local permitivity information. */
		Eigen::DiagonalMatrix<double, Eigen::Dynamic> hodge_epsilon;

		/*! Matrix representation of the discrete gradient operator.
		 * This includes no metric information and contains purely
		 * topological information. It should be noted that
		 * \f$\mathbf{G} = -\tilde{\mathbf{S}}\f$, where \f$\mathbf{G}\f$
		 * is the discrete gradient operator on the primal grid and
		 * \f$\tilde{\mathbf{S}}\f$ is the discrete divergence operator
		 * on the dual grid. */
		Eigen::SparseMatrix<double> grad;

	public:
		//! Mesh main constructor.
		/*!
		 * Constructs an evenly spaced mesh with N vertices including
		 * endpoints.
		 *
		 * \param N number of mesh vertices
		 * \param xmin minimum coordinate value
		 * \param xmax maximum coordinate value
		 */
		Mesh1D(int N, Vectord<1> xmin = Vectord<1>::Zero(),
				Vectord<1> xmax = Vectord<1>::Ones());
};

#endif //_mesh_hpp
