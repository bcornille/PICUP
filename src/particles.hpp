/*!
 * \file
 * \brief Particle/Species header file.
 *
 * Contents:
 *  * Particle struct
 *  * Species class
 *
 */

#include "mesh.hpp"

#ifndef _particles_hpp
#define _particles_hpp

//! A template structure for an individual particle.
/*!
 * The purpose of this structure is for better data locality during
 * particle position updates and other calls to particle phase
 * information. Including the cell number also allows for simple
 * sorting of the particles by cell.
 */
template <typename PosVec, typename VelVec>
struct Particle
{
	PosVec position; //!< Particle postion.
	VelVec velocity; //!< Particle velocity.
	int cell; //!< Cell that the particle occupies.
};

//! Operator for sorting particles by cell.
/*!
 * This operator allows particles to be sorted by the index of the cell
 * that they occupy. Sorting particles by cell every 10-100 time steps
 * is said to give a considerable performance boost by reusing field
 * values that have been stored in cache. \cite Verboncoeur2015
 */
template <typename PosVec, typename VelVec>
bool operator< (const Particle<PosVec, VelVec> &part_a,
		const Particle<PosVec, VelVec> &part_b)
{
	return part_a.cell < part_b.cell;
}

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
		std::vector<Particle<PosVec, VelVec> > particle_list;

	public:
		//! Particles main constructor.
		/*!
		 * \param q Charge of the particle species.
		 * \param m Mass of the particle species.
		 */
		Species(double q, double m);

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
		 *
		 * \return reference to <CODE> positions </CODE>
		 */
		const std::vector<Particle<PosVec, VelVec> >&
			getParticles() const;

		//! Creates particles distributed across a given mesh.
		/*!
		 * Currently the Mesh reference cannot be passed as const since
		 * the random number generator is a member of Mesh and its state
		 * is changed by sampling the Mesh volume. This is possibly a
		 * poor design choice and a global random number generator may
		 * be more suitable.
		 *
		 * \param N
		 * \param mesh
		 */
		template <typename PosInd>
		void generateParticles(int N, Mesh<PosInd, PosVec> &mesh);
};

#endif //_particles_hpp
