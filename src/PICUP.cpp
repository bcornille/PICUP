/***************************************************************************//*!
 * \file
 * \brief This is the main program file for the Particle-In-Cell Utility for
 * 			Practice (PICUP).
 *
 * Longer description will go here.
 ******************************************************************************/

#include <iostream>
#include "test.hpp"

int main(int argc, char *argv[])
{
	Test testTest(1.0, -1.0, 0.5);
	std::cout << "(" << testTest.GetX() << ", " << testTest.GetY() << ", " <<
		testTest.GetZ() << ")" << std::endl;

	testTest.SetTest(2.0, 3.0, -6.5);
	std::cout << "(" << testTest.GetX() << ", " << testTest.GetY() << ", " <<
		testTest.GetZ() << ")" << std::endl;

	return 0;
}
