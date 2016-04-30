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
std::atomic<int> Node<pdim>::s_id(0);

template <int pdim>
Node<pdim>::Node() :
	global_id(s_id++) {};

template <int pdim>
VertexNode<pdim>::VertexNode(Vectord<pdim> x) :
	global_coords(x), Node<pdim>() {};

template <int pdim>
Edge<pdim>::Edge(std::array<VertexNode<pdim>*, 2> vertices) :
	vertex_nodes(vertices) {};

/*
template <int pdim>
InteriorNode<pdim>::InteriorNode(Vectord<pdim> lambda) :
	local_coords(lambda), Node<pdim>() {};
*/

NodeElement1D::
NodeElement1D(Edge<1> &edge_ref) : edge(edge_ref) {};

template class VertexNode<1>;
template class Edge<1>;
