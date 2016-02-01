/*!
 * \file
 * \brief Particles header file.
 *
 * Contents:
 *  * Particles class
 */

#include <vector>
#include "Eigen/Core"

#ifndef _particles_hpp
#define _particles_hpp

//! A template class for the particles.
/*!
 * The template class allows for using 1D, 2D, or 3D vectors for
 * particle positions and velocities.
 */
template <typename PosVec, typename VelVec>
class Particles
{
	private:
		int num_particles;	/*!< Number of particles. */
		/*! Positions of the particles. */
		std::vector<PosVec, Eigen::aligned_allocator<PosVec> >
			positions;
		/*! Velocities of the particles. */
		std::vector<VelVec, Eigen::aligned_allocator<VelVec> >
			velocities;

	public:
		//! Particles default constructor.
		/*!
		 * The default constructor creates no particles, i.e. the
		 * number of particles is set to zero and the position and
		 * velocity pointers are set to null.
		 */
		/*
		Particles();
		*/

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

		//! Public facing method to get num_particles.
		/*!
		 * \return num_particles
		 */
		int getNumParticles();
};

#endif //_particles_hpp
