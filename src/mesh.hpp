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
#include "Eigen/SparseLU"

#ifndef _mesh_hpp
#define _mesh_hpp

//! A template class for the mesh.
/*!
 * The template class allows for using 1D, 2D, or 3D strucutres for mesh
 * logical indices and coordinates independently.
 *
 * Since all available dimensional types of this class must be
 * instantiated, the one that is to be used will need to have its member
 * vector arrays resized explicitly during runtime.
 */
template <typename PosInd, typename PosVec>
class Mesh
{
	private:
		int num_meshpoints; /*!< Total number of meshpoints. */
		int num_cells;      /*!< Total number of cells.      */
		/*! Random number generator, currently with default seed. */
		std::default_random_engine generator;
		/*! Uniform distribution sampler using the default range
		 * 0.0 to 1.0 */
		std::uniform_real_distribution<double> uniform_dist;

		/*! Number of logical indices in each direction. */
		PosInd num_indices;

		/*! Coordinates of the meshpoints. */
		std::vector<PosVec>
			coordinates;

		/*! Laplace sparse matrix for mesh. */
		Eigen::SparseMatrix<double> laplace;

	public:
		//! Mesh main constructor.
		/*!
		 * Sets the total number of meshpoints to zero.
		 */
		Mesh();

		//! Public facing method to query num_meshpoints.
		/*!
		 * \return <CODE> num_meshpoints </CODE>
		 */
		int getNumMeshpoints() const;

		//! Template routine to setup a mesh.
		/*!
		 * Generalized mesh setup is not possible, so specializations
		 * are required for each possible mesh type.
		 *
		 * \param N number of mesh vertices in each logical direction
		 * \param xmin vector of minimum value of each coordinate
		 * \param xmax vector of maximum value of each coordinate
		 *
		 * \sa generateMesh(int N, double xmin, double xmax)
		 */
		void generateMesh(PosInd N, PosVec xmin, PosVec xmax);

		//! Template routine to query list of vertices for a given cell.
		/*!
		 * A generalized form of this routine is not possible.
		 *
		 * \param cell index
		 *
		 * \returns index of vertices in a std::vector
		 *
		 * \sa Mesh<int, double>::getVertices(int cell) const
		 */
		std::vector<int> getVertices(int cell) const;

		//! Template routine to get particle weighting.
		/*!
		 * A generalized form of this routine is not possible.
		 *
		 * \param x position of the particle
		 * \param vert overall index of the vertex
		 *
		 * \returns <CODE> weight </CODE>
		 *
		 * \sa getWeight(double x, int vert) const
		 */
		double getWeight(PosVec x, int vert) const;

		//! Generates the laplace matrix based on the mesh.
		/*!
		 * A generalized generation is not most efficient for simple
		 * problems even if possible.
		 */
		void generateLaplace();

		//! Solver to be used with the laplace matrix.
		/*!
		 * SparseLU was chosen as the solver type because it will allow
		 * for general matrix form solutions in the future and to use
		 * only the MPL2 liscensed parts of the Eigen library
		 */
		Eigen::SparseLU<Eigen::SparseMatrix<double> > laplace_solver;

		//! Randomly sample the mesh space for a position.
		/*!
		 * A generalized sampling of the mesh volume is either not
		 * possible or not advised.
		 *
		 * Currently this only returns a position sampled uniformly from
		 * the total volume area. In order to circumvent the costly
		 * function of finding the cell of a particle after sampling
		 * it may be advisable to sample the cells as a discrete
		 * distrubution weighted by volume, then uniformly sample the
		 * cell volume afterward. Both values can then be given
		 * simultaneously.
		 *
		 * \return <CODE> position </CODE> of a sampled mesh volume
		 */
		PosVec sampleMesh();

		int getCell(PosVec x) const;
};

#endif //_mesh_hpp
