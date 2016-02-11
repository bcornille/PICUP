/*!
 * \file
 * \brief Mesh header file.
 *
 * Contents:
 *  * Mesh class
 */

#include <vector>
#include "Eigen/Core"

#ifndef _mesh_hpp
#define _mesh_hpp

//! A template class for the mesh
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
		PosInd num_meshpoints; /*! Number of meshpoints. */

		/*! Logical indices of the meshpoints. */
		std::vector<PosInd, Eigen::aligned_allocator<PosInd> >
			indices;

		/*! Coordinates of the meshpoints. */
		std::vector<PosVec, Eigen::aligned_allocator<PosVec> >
			coordinates;

	public:
		//! Mesh main constructor.
		/*!
		 * Sets the number of meshpoints to zero in the appropriate
		 * dimensionality.
		 */
		Mesh();
}

#endif //_mesh_hpp
