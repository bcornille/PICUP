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
Node::Node(int id) :
	global_id(id) {};

template <int pdim>
VertexNode::VertexNode(Vectord<pdim> x, int id) :
	global_coords(x), Node(id) {};

template <int pdim>
InteriorNode::InteriorNode(Vectord<pdim> lambda, int id) :
	local_coords(lambda), Node(id) {};

NodeElement1D::
NodeElement1D(std::array<std::shared_ptr<Node<pdim> >, 2> vertices) :
	vertex_nodes(vertices) {};
