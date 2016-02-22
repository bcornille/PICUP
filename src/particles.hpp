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

		/*! Mesh cell index for each particle. */
		std::vector<int> cell_index;

	public:
		//! Particles main constructor.
		/*!
		 * \param q Charge of the particle species.
		 * \param m Mass of the particle species.
		 */
		Particles(double q, double m);

		//! Public facing method to get num_particles.
		/*!
		 * \return <CODE> num_particles </CODE>
		 */
		int getNumParticles() const;

		//! Public facing method to get charge;
		/*!
		 * \return <CODE> charge </CODE>
		 */
		double getCharge() const;

		//! Return a constant reference to particle positions.
		/*!
		 * The main utility of this function is to allow accumulation of
		 * charge density efficiently.
		 */
		const std::vector<PosVec, Eigen::aligned_allocator<PosVec> >&
			getPositions() const;

		//! Return a constant reference to the cells of particles.
		/*!
		 * The main utility of this function is to allow accumulation of
		 * charge density efficiently.
		 */
		const std::vector<int>& getCells() const;
};

#endif //_particles_hpp
