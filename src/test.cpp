/***************************************************************************//*!
 * \file
 * \brief Test class access functions.
 *
 *
 ******************************************************************************/

#include "test.hpp"

//! Test constructor.
Test::Test(double x, double y, double z)
{
	SetTest(x, y, z);
}

void Test::SetTest(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}
