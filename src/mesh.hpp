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
		 * \param N Type PosInd to set the number of meshpoints in each
		 *   logical direction.
		 */
		Mesh(PosInd N);

		//! Mesh destructor.
		/*!
		 * Sets the number of meshpoints to zero.
		 */
		~Mesh();
}

#endif //_mesh_hpp
