/*******************************************************************//*!
 * \file
 * \brief This file will define the finite element implementation.
 *
 * Contents:
 *  * 
 *
 **********************************************************************/

#include "elements.hpp"

template <int pdim>
Node<pdim>::Node(int id) :
	global_id(id) {};

template <int pdim>
VertexNode<pdim>::VertexNode(Vectord<pdim> x, int id) :
	global_coords(x), Node<pdim>(id) {};

template <int pdim>
InteriorNode<pdim>::InteriorNode(Vectord<pdim> lambda, int id) :
	local_coords(lambda), Node<pdim>(id) {};

NodeElement1D::
NodeElement1D(std::array<Node<1>*, 2> vertices) :
	vertex_nodes(vertices) {};
