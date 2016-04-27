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
