/*!
 * \file
 * \brief Setup random number generator.
 *
 * Contents:
 *  * 
 *
 */

#include <chrono>
#include <random>

#ifndef _random_hpp
#define _random_hpp

namespace picup_rand {
	extern unsigned seed;
	extern std::default_random_engine generator;
}

#endif //_random_hpp
