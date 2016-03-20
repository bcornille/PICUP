/*!
 * \file
 * \brief Boundary header file.
 *
 * Contents:
 *  * Boundary class
 *
 */

#include "mesh.hpp"

#ifndef _boundary_hpp
#define _boundary_hpp

//! A template class for the boundary base class.
/*!
 * The boundary class should point to sections of the elements on the
 * boundary. Elements should probably be abstracted better in the code
 * before developing the boundary class.
 */
template <typename PosInd, typename PosVec>
class Boundary
{
	protected:

	public:
}

#endif //_boundary_hpp
