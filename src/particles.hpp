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
		int num_particles;	/*!< Number of particles.		*/
		double charge;		/*!< Charge of particle type.	*/
		double mass;		/*!< Mass of particle type.		*/
		/*! Charge to mass ratio of particle type. */
		double qm_ratio;

		/*! Positions of the particles. */
		std::vector<PosVec, Eigen::aligned_allocator<PosVec> >
			positions;

		/*! Velocities of the particles. */
		std::vector<VelVec, Eigen::aligned_allocator<VelVec> >
			velocities;

	public:
		//! Particles main constructor.
		/*!
		 * \param N Integer setting the number of particles.
		 */
		Particles(int N, double q, double m);

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
