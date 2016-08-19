/*!
 * \file
 * \brief Fields header file.
 *
 * Contents:
 *  * 
 *
 */

#include "particles.hpp"

#ifndef _fields_hpp
#define _fields_hpp

//! A class for all fields.
/*!
 * The template class defines all fields on a mesh. Thus a constant
 * reference to the mesh for the field is set during construction.
 * Vector arrays for the fields are also allocated during construction.
 */
template <int pdim>
class Fields
{
	private:
		/*! Reference to the mesh that the field exists on. */
		const Mesh<pdim> &field_mesh;

		/*! Value of the electric potential field. (0-form) */
		Eigen::VectorXd potential;

		/*! Accumulated charge density that creates the electric
		 *  * potential field. (0-form/twisted 3-form?) */
		Eigen::VectorXd rho_q;

		/*! Electric field degrees of freedom. (1-form) */
		Eigen::VectorXd e_field;

		/*! Magnetic field degrees of freedom. (2-form) */
		Eigen::VectorXd b_field;

		/*! Accumulated current density that creates the self-consistent
		 *  * electric and magnetic field. (twisted 2-form, i.e. uses
		 *  the same degrees of freedom as a 1-form on the primal grid)*/
		Eigen::VectorXd j_q;

	public:
		//! The main constructor for the electric potential field.
		/*!
		 * The vector arrays necessary for determining all fields on the
		 * provided mesh are constructed. The mesh size determines the
		 * size of all vector arrays.
		 */
		Fields(const Mesh<pdim> &mesh);

		//! Accumulate charge density.
		/*!
		 * Charge accumulation is able to be generalized due to careful
		 * construction of the Mesh class.
		 */
		void accumulateCharge(const Species<pdim>& particles);

		//! Solve the poisson equaion using the charge in rho_q array.
		/*!
		 * The SparseLU solver class is used for solving the poisson
		 * equation.
		 */
		void solvePoisson();

		Eigen::VectorXd &getCharge() { return rho_q; }
		Eigen::VectorXd &getPotential() { return potential; }
}

#endif //_fields_hpp
