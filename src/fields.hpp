/*!
 * \file
 * \brief Fields header file.
 *
 * Contents:
 *  * ScalarField class
 *  * VectorField class
 */

#include "mesh.hpp"

#ifndef _fields_hpp
#define _fields_hpp

//! A class for scalar fields.
/*!
 * The template class defines a scalar field on a mesh.
 * Thus the scalar field class is derived from Mesh.
 */
template <typename PosInd, typename PosVec>
class ScalarField : public Mesh<PosInd, PosVec>
{
	private:
		/*! Value of the scalar field. */
		std::vector<double> value;
}

#endif //_fields_hpp
