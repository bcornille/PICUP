/*******************************************************************//*!
 * \file
 * \brief This file will contain all functions for the Mesh template
 * class.
 *
 * Contents:
 *  * Mesh(PosInd N) implementation; where PosInd can be:
 *    * int
 *    * Vector2i
 *    * Vector3i
 *
 **********************************************************************/
#include "mesh.hpp"

template <typename PosInd, typename PosVec>
Mesh<PosInd, PosVec>::Mesh() : num_meshpoints(0)
{
}
