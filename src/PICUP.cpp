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
#include <new>
#include <stdexcept>

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
	try
	{
		mesh_test.generateMesh(1, 1.0, 0.0);
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Bad allocation: " << e.what() << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}

	return 0;
}
