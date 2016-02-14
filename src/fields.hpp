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
class PotentialField
{
	private:
		/*! Pointer to the mesh that the field exists on. */
		const Mesh<PosInd, PosVec> *field_mesh;

		/*! Value of the electric potential field. */
		std::vector<double> potential;

		/*! Accumulated charge density that creates the electric
		 * potential field. */
		std::vector<double> rho_q;

	public:
		//! Default constructor for the electric potential field.
		/*!
		 * The electric field potential is constructed on a given mesh.
		 * The mesh size determines the size of the potential and rho_q
		 * vector arrays.
		 */
		PotentialField(const Mesh<PosInd, PosVec> &mesh);
};

#endif //_fields_hpp
