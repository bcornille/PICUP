/*!
 * \file
 * \brief Fields header file.
 *
 * Contents:
 *  * Fields class
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
template <typename PosInd, typename PosVec>
class Fields
{
	private:
		/*! Pointer to the mesh that the field exists on. */
		const Mesh<PosInd, PosVec> &field_mesh;

		/*! Value of the electric potential field. */
		Eigen::VectorXd potential;

		/*! Accumulated charge density that creates the electric
		 * potential field. */
		Eigen::VectorXd rho_q;

		/*! Value of the electric field. */
		std::vector<Eigen::Vector3d> e_field;

		/*! Value of the magnetic field. */
		std::vector<Eigen::Vector3d> b_field;

		/*! Accumulated current density that creates the self-consistent
		 * electric and magnetic field. */
		std::vector<Eigen::Vector3d> j_q;

	public:
		//! The main constructor for the electric potential field.
		/*!
		 * The vector arrays necessary for determining all fields on the
		 * provided mesh are constructed. The mesh size determines the
		 * size of all vector arrays.
		 */
		Fields(const Mesh<PosInd, PosVec> &mesh);

		//! Accumulate charge density.
		/*!
		 * Charge accumulation is able to be generalized due to careful
		 * construction of the Mesh class. Especially its member
		 * function Mesh::getVertices. Having the Mesh class handle
		 * calculation of weighting will also be pivotal.
		 *
		 * \param particles class reference
		 */
		template <typename VelVec>
		void accumulateCharge(
				const Species<PosVec, VelVec>& particles);

		//! Solve the poisson equaion using the charge in rho_q array.
		/*!
		 * The SparseLU solver class is used for solving the poisson
		 * equation.
		 */
		void solvePoisson();

		Eigen::VectorXd &getCharge() { return rho_q; }
		Eigen::VectorXd &getPotential() { return potential; }
};

#endif //_fields_hpp
