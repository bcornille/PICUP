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

template <typename PosVec>
Mesh<int, PosVec>::Mesh() : num_meshpoints(0)
{
}

template <typename PosVec>
Mesh<Vector2i, PosVec>::Mesh() : num_meshpoints(Eigen::Vector2i::Zero())
{
}

template <typename PosVec>
Mesh<Vector3i, PosVec>::Mesh() : num_meshpoints(Eigen::Vector3i::Zero())
{
}
