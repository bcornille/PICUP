/*!
 * \file
 * \brief Mesh header file.
 *
 * Contents:
 *  * Mesh class
 *
 */

#include <vector>
#include "elements.hpp"

#ifndef _mesh_hpp
#define _mesh_hpp

//! Interface class for various types of Mesh in arbitrary dimension.
/*!
 * Most functions will be pure virtual functions.
 */
template <int pdim>
class Mesh
{
	public:
		//! Get the weights for particle generation in each cell.
		virtual std::vector<double> getWeights() const = 0;
		//! Sample the volume of the given cell.
		virtual Vectord<pdim> sampleCell(int cell) = 0;
		//! Get the number of Mesh vertices.
		virtual getNumMeshPoints = 0;
		//! Get the number of Mesh edges.
		virtual getNumMeshEdges = 0;
		//! Get the number of Mesh faces.
		virtual getNumMeshFaces = 0;
};

//! One-dimensional Mesh class.
/*!
 * The one-dimensional mesh will only support electrostatic
 * particle-in-cell algorithm, thus several elements of this class have
 * been designed around that.  The mesh is constructed primarily of
 * NodeElement1D with EdgeElement1D set between them.  A a special
 * property of the Hodge star (epsilon) operator for this mesh is that
 * it is a DiagonalMatrix.  Additionally, we only need to generate the
 * discrete gradient operator matrix on the primal grid, since it can be
 * simply related to the discrete divergence operator on the dual grid.
 */
class Mesh1D : Mesh<1>
{
	private:
		/*! Number of vertices defining the primal mesh. */
		const int num_vertices;
		/*! Number of edges defined on the primal mesh. */
		const int num_edges;

		/*! Vector containing all the mesh nodes. */
		std::vector<std::shared_ptr<Vertex<1> > > vertices;

		/*! Vector containing all the mesh edges.  In one-dimension
		 * these are also considered the cells.*/
		std::vector<Cell1D> cells;

		/*! Vector containing the 1-dimensional Whitney 0-form
		 * elements. These should be identical to 1st order linear
		 * elements in 1-dimension.*/
		std::vector<Element1DZeroForm> zero_forms;

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

		//! Get weights of the mesh elements.
		/*!
		 */
		std::vector<double> getWeights() const;

		//! Randomly sample cell volume.
		/*!
		 */
		Vectord<1> sampleCell(int cell);

		int getNumMeshpoints() const { return num_vertices; };
		int getNumMeshedges() const { return num_edges; }
		int getNumMeshedges() const { return 0; /* No faces in 1D. */ }
};

#endif //_mesh_hpp
