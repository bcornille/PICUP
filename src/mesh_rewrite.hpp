/*!
 * \file
 * \brief Mesh header file.
 *
 * Contents:
 *  * Mesh class
 *
 */

#include <vector>
#include <random>
#include "Eigen/SparseLU"

#ifndef _mesh_hpp
#define _mesh_hpp

template <int pdim>
class Mesh
{
	private:
		int num_nodes;
		int num_elements;

		std::vector<Node<pdim> > nodes;

		std::vector<Element<pdim> > elements;
};

#endif //_mesh_hpp
