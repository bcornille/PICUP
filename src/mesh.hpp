/*!
 * \file
 * \brief Mesh header file.
 *
 * Contents:
 *  * Mesh class
 *
 */

#include <vector>
#include "Eigen/Core"

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

		/*! Number of logical indices in each direction. */
		PosInd num_indices;

		/*! Coordinates of the meshpoints. */
		std::vector<PosVec, Eigen::aligned_allocator<PosVec> >
			coordinates;

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
		 * \sa Mesh<int, double>::getVertices(int cell)
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
		 * \sa getWeight(double x, int vert)
		 */
		double getWeight(PosVec x, int vert) const;
};

#endif //_mesh_hpp
