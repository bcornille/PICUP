/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Species
 * template class.
 *
 * Contents:
 *  * bool operator< (const Particle<pdim> &part_a,
 *  		const Particle<pdim> &part_b)
 *
 **********************************************************************/

#include "particles_rewrite.hpp"

template <int pdim>
bool operator< (const Particle<pdim> &part_a,
		const Particle<pdim> &part_b)
{
	return part_a.cell < part_b.cell;
}

template <int pdim>
Species<pdim>::Species(double q, double m) :
	num_particles(0), charge(q), mass(m), qm_ratio(q/m) {}
