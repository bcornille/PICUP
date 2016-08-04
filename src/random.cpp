#include "random.hpp"

namespace picup_rand
{
#ifdef NDEBUG
	unsigned seed =
		std::chrono::system_clock::now().time_since_epoch().count();
#else
	unsigned seed = 123456789;
#endif // NDEBUG

	std::default_random_engine generator(seed);
} // picup_rand
