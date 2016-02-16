/*!
 * \file
 * \brief Fields header file.
 *
 * Contents:
 *  * Fields class
 *
 */

#include "mesh.hpp"

#ifndef _fields_hpp
#define _fields_hpp

//! A class for all fields.
/*!
 * The template class defines all fields on a mesh. Thus a constant
 * reference to the mesh for the field is set during construction.
 * Vector arrays for the fields are also allocated during construction.
 */
template <typename PosInd, typename PosVec>
class Fields
{
	private:
		/*! Pointer to the mesh that the field exists on. */
		const Mesh<PosInd, PosVec> &field_mesh;

		/*! Value of the electric potential field. */
		std::vector<double> potential;

		/*! Accumulated charge density that creates the electric
		 * potential field. */
		std::vector<double> rho_q;

		/*! Value of the electric field. */
		std::vector<Eigen::Vector3d,
			Eigen::aligned_allocator<Eigen::Vector3d> > e_field;

		/*! Value of the magnetic field. */
		std::vector<Eigen::Vector3d,
			Eigen::aligned_allocator<Eigen::Vector3d> > b_field;

		/*! Accumulated current density that creates the self-consistent
		 * electric and magnetic field. */
		std::vector<Eigen::Vector3d,
			Eigen::aligned_allocator<Eigen::Vector3d> > j_q;

	public:
		//! The main constructor for the electric potential field.
		/*!
		 * The vector arrays necessary for determining all fields on the
		 * provided mesh are constructed. The mesh size determines the
		 * size of all vector arrays.
		 */
		Fields(const Mesh<PosInd, PosVec> &mesh);
};

#endif //_fields_hpp
