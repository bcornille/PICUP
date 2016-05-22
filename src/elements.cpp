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
	global_id(s_id++) {}

template <int pdim>
Vertex<pdim>::Vertex(Vectord<pdim> x) :
	global_coords(x), Node<pdim>() {}

template <int pdim>
Vectord<pdim> Vertex<pdim>::getCoords() { return global_coords; }

template <int pdim>
Edge<pdim>::
Edge(std::array<std::shared_ptr<Vertex<pdim> >, 2> vertices) :
	endpoints(vertices),
	edge_length((endpoints[1]->getCoords()
				- endpoints[0]->getCoords()).norm())
{}

template <int pdim>
double Edge<pdim>::getLength() const { return edge_length; }

/*
template <int pdim>
InteriorNode<pdim>::InteriorNode(Vectord<pdim> lambda) :
	local_coords(lambda), Node<pdim>() {};
*/

NodeElement1D::
NodeElement1D(Edge<1> &edge_ref) : edge(edge_ref) {}

template class Vertex<1>;
template class Edge<1>;
