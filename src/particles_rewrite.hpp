/*!
 * \file
 * \brief Particle/Species header file.
 *
 * Contents:
 *  * Particle struct
 *  * Species class
 *
 */

#include "mesh_rewrite.hpp"

#ifndef _particles_hpp
#define _particles_hpp

//! A template structure for a single particle.
/*!
 * Particle properties include position and velocity.  Also included in
 * the particle data structure are the gathered representations of
 * electric and magnetic fields at the particle position. (Where the
 * magnetic field is in an operator including the sum of the identity
 * matrix and a cross-product with magnetic field equivalent matirx.)
 * The current cell ID that the particle occupies is also saved here.
 * The rational behind gathering all this data in a single structure is
 * that for the particle position and velocity updates, having good data
 * localization of these data should lead to better performance of the
 * code. (Up to 100% better performance versus separately stored fields.
 * \cite Verboncoeur2005)
 */
template <int pdim>
struct Particle
{
	Vectord<pdim> position; /*!< Particle postion. */
	Eigen::Vector3d velocity; /*!< Particle velocity. */
	Eigen::Vector3d e_field; /*!< Gathered particle electric field. */
	/*! Matrix representing the operator
	 * \f$\mathbf{N}=\mathbf{I}+\left[\mathbf{B}\right]_\times\f$
	 * where \f$\left[\mathbf{B}\right]_\times\f$ represents the
	 * skew-symmetric matrix equivalent to the vector cross product.
	 * \cite Moon2015
	 * \f[
	 * 	\mathbf{N}=\begin{bmatrix}
	 * 		1 & -\frac{a\Delta{t}}{2m}B_z & \frac{a\Delta{t}}{2m}B_y \\
	 * 		\frac{a\Delta{t}}{2m}B_z & 1 & -\frac{a\Delta{t}}{2m}B_x \\
	 * 		-\frac{a\Delta{t}}{2m}B_y & \frac{a\Delta{t}}{2m}B_x & 1
	 * 	\end{bmatrix}
	 * \f] */
	Eigen::Matrix3d iden_bx;
	int cell; /*!< Cell that the particle occupies. */
};

//! Operator for sorting particles by cell.
/*!
 * This operator allows particles to be sorted by the index of the cell
 * that they occupy. Sorting particles by cell every 10-100 time steps
 * is said to give a considerable performance boost by reusing field
 * values that have been stored in cache. \cite Verboncoeur2015
 */
template <int pdim>
bool operator< (const Particle<pdim> &part_a,
		const Particle<pdim> &part_b);

template <int pdim>
class Species
{
	private:
		int num_particles;   /*!< Number of particles.     */
		const double charge; /*!< Charge of particle type. */
		const double mass;   /*!< Mass of particle type.   */
		/*! Charge to mass ratio of particle type. */
		const double qm_ratio;

		//! Vector containing all the particles of this species.
		/*!
		 * Storing the various information about each particle in a
		 * structure and keeping them as a list helps to reduce cache
		 * thrashing and can provide significantly improved performance.
		 * \cite Verboncoeur2005
		 */
		std::vector<Particle<pdim> > particle_list;

	public:
		//! Particles main constructor.
		/*!
		 * \param q Charge of the particle species.
		 * \param m Mass of the particle species.
		 */
		Species(double q, double m = 1.0);

};

#endif //_particles_hpp
