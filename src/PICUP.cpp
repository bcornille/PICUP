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

#include "fields.hpp"
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
	Mesh<int, double> mesh_test;
	Species<double, double> parts_e(-1.0, 1.0);
	Species<double, double> parts_p(1.0, 1.0);
	try
	{
		// Throws invalid argument exception because N not positive.
		// mesh_test.generateMesh(-1, 1.0, 0.0);
		// Throws invalid argument exception because xmin >= xmax.
		// mesh_test.generateMesh(1, 1.0, 0.0);
		mesh_test.generateMesh(100, 0.0, 1.0);
		mesh_test.generateLaplace();
		parts_e.generateParticles(100, mesh_test);
		parts_p.generateParticles(100, mesh_test);
		parts_e.sortParticles();
		parts_p.sortParticles();
		Fields<int, double> fields_test(mesh_test);
		fields_test.accumulateCharge<double>(parts_e);
		fields_test.accumulateCharge<double>(parts_p);
		fields_test.solvePoisson();
		//std::cout << fields_test.getCharge() << std::endl;
		//std::cout << fields_test.getPotential() << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (int info)
	{
		std::cerr << "Bad Laplace operator generation: " << info <<
			std::endl;
	}

	return 0;
}
