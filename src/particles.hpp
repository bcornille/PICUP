/*!
 * \file
 * \brief Particles header file.
 */

#include <Eigen/Core>

#ifndef _particles_hpp
#define _particles_hpp

//! A template class for the particles.
/*!
 * The template class allows for using 1D, 2D, or 3D vectors for
 * particle positions and velocities.
 */
template <typename Vector>
class Particles
{
	private:
		int num_particles;	/*!< Number of particles.			*/
		Vector *positions; 	/*!< Positions of the particles.	*/
		Vector *velocities;	/*!< Velocieites of the particles.	*/

	public:
		//! Particles default constructor.
		/*!
		 * The default constructor creates no particles, i.e. the
		 * number of particles is set to zero and the position and
		 * velocity pointers are set to null.
		 */
		Particles();

		//! Particles main constructor.
		/*!
		 * \param N Integer setting the number of particles.
		 */
		Particles(int N);

		//! Particles destructor.
		/*!
		 * Deletes the position and velocity pointers and sets the
		 * number of particles to zero.
		 */
		~Particles();
}

#endif //_particles_hpp
