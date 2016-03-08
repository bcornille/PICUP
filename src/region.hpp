/*!
 * \file
 * \brief Region header file.
 *
 * Contents:
 *  * Region class
 *
 */

#include "fields.hpp"

#ifndef _region_hpp
#define _region_hpp

template <typename PosInd, typename PosVec, typename VelVec>
class Region
{
	private:
		const Mesh<PosInd, PosVec> &region_mesh;
		const Fields<PosInd, PosVec> &region_fields;
		std::vector<Species> species_list;

	public:
}

#endif //_region_hpp
