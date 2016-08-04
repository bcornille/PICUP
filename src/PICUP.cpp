/*******************************************************************//*!
 * \file
 * \brief This is the main program file for the Particle-In-Cell Utility
 *  for Practice (PICUP).
 *
 * The PICUP program will be split into 3 main kernels.
 *
 *  1. PICIN - will read the input file(s) and initialize the
 *   calculation.
 *
 *  2. PICPUSH - the particle-in-cell physics solver.
 *
 *  3. PICOUT - will generate output files with physics data.
 **********************************************************************/

#include "particles_rewrite.hpp"
#include <iostream>

//! Currently used for testing functions manually.
/*!
 * The main driver code. Eventually will consist of only calls to each
 * of the PICUP kernels. For now it is being used for small manual
 * test. E.g. Testing the output of exceptions.
 */
int main(int argc, char *argv[])
{
	/* This tests outputs of exception stuff.
	 * Look it's cool.
	 */
	try
	{
		// Invalid arguments
		// Mesh1D mesh_fail1(-1);
		// Mesh1D mesh_fail2(100, Vectord<1>::Ones(), Vectord<1>::Zero());
		Mesh1D mesh_test(100);
		Species<1> protons(1.0);
		protons.generateParticles(100, mesh_test);
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}

	return 0;
}
