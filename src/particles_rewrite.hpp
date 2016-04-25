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
template <int pdim>
struct ParticleRewrite
{
	Vectord<pdim> position; /*!< Particle postion. */
	Vector3d velocity; /*!< Particle velocity. */
	Vector3d e_field; /*!< Gathered particle electric field. */
	/*! Matrix representing the operator
	 * \f$\mathbf{N}=\mathbf{I}+\left[\mathbf{B}\right]_\times\f$
	 * where \f$\left[\mathbf{B}\right]_\times\f$ represents the
	 * skew-symmetric matrix equivalent to the vector cross product.
	 * \f[
	 * 	\mathbf{N}=\begin{bmatrix}
	 * 		1 & -\frac{a\Delta{t}}{2m}B_z & \frac{a\Delta{t}}{2m}B_y \\
	 * 		\frac{a\Delta{t}}{2m}B_z & 1 & -\frac{a\Delta{t}}{2m}B_x \\
	 * 		-\frac{a\Delta{t}}{2m}B_y & \frac{a\Delta{t}}{2m}B_x & 1
	 * 	\end{bmatrix}
	 * \f] */
	Matrix3d iden_bx;
	int cell; /*!< Cell that the particle occupies. */
};

#endif //_particles_hpp
