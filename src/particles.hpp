/*!
 * \file
 * \brief Particles header file.
 *
 * Contents:
 *  * Particles class
 *
 */

#include <vector>
#include "Eigen/Core"

#ifndef _particles_hpp
#define _particles_hpp

//! A template class for the particles.
/*!
 * The template class allows for using 1D, 2D, or 3D vectors for
 * particle positions and velocities.
 *
 * Since all available dimensional types of this class must be
 * instantiated, the one that is to be used will need to have its member
 * vector arrays resized explicitly during runtime.
 *
 */
template <typename PosVec, typename VelVec>
class Particles
{
	private:
		int num_particles;   /*!< Number of particles.     */
		const double charge; /*!< Charge of particle type. */
		const double mass;   /*!< Mass of particle type.   */
		/*! Charge to mass ratio of particle type. */
		const double qm_ratio;

		/*! Positions of the particles. */
		std::vector<PosVec, Eigen::aligned_allocator<PosVec> >
			positions;

		/*! Velocities of the particles. */
		std::vector<VelVec, Eigen::aligned_allocator<VelVec> >
			velocities;

	public:
		//! Particles main constructor.
		/*!
		 * \param q Charge of the particle species.
		 * \param m Mass of the particle species.
		 */
		Particles(double q, double m);

		//! Public facing method to get num_particles.
		/*!
		 * \return num_particles
		 */
		int getNumParticles();
};

#endif //_particles_hpp
