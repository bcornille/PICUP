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
std::atomic<int> Edge<pdim>::s_id(0);

template <int pdim>
Edge<pdim>::
Edge(std::array<std::shared_ptr<Vertex<pdim> >, 2> vertices) :
	global_id(s_id++),
	endpoints(vertices),
	edge_length((endpoints[1]->getCoords()
				- endpoints[0]->getCoords()).norm())
{}

template <int pdim>
double Edge<pdim>::getLength() const { return edge_length; }

Cell1D::
Cell1D(std::array<std::shared_ptr<Vertex<1> >, 2> vertices) :
	distribution(vertices[0]->getCoords()[0],
			vertices[1]->getCoords()[0]),
	Edge<1>(vertices)
{}

Vectord<1> Cell1D::sampleCell()
{
	Vectord<1> point;
	point[0] = distribution(picup_rand::generator);
	return point;
}

/*
template <int pdim>
InteriorNode<pdim>::InteriorNode(Vectord<pdim> lambda) :
	local_coords(lambda), Node<pdim>() {};
*/

Element1DZeroForm::
Element1DZeroForm(Cell1D &cell_ref) : cell(cell_ref) {}

Element1DOneForm::
Element1DOneForm(Cell1D &cell_ref) : cell(cell_ref) {}

template class Vertex<1>;
template class Edge<1>;
