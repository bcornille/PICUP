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
	num_particles(0), charge(q), mass(m), qm_ratio(q/m)
{}

template <int pdim>
void Species<pdim>::generateParticles(int N, Mesh1D &mesh)
{
	std::vector<double> weights(mesh.getWeights());
	std::discrete_distribution<> cell_dist(weights.begin(), weights.end());
	num_particles = N;
	particle_list.resize(num_particles);
	for(int i = 0; i < N; i++)
	{
		particle_list[i].cell = cell_dist(picup_rand::generator);
		particle_list[i].position = mesh.sampleCell(particle_list[i].cell);
	}
}

template class Species<1>;
