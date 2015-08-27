/***************************************************************************//*!
 * \file
 * \brief Test class.
 *
 *
 ******************************************************************************/

#ifndef TEST_HPP
#define TEST_HPP

class Test {
private:
	double m_x;
	double m_y;
	double m_z;

	Test() { } //< Private default constructor.

public:
	Test(double x, double y, double z);

	void SetTest(double x, double y, double z);

	double GetX() { return m_x; }
	double GetY() { return m_y; }
	double GetZ() { return m_z; }
};

#endif // TEST_HPP
