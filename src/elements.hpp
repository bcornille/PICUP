/*!
 * \file
 * \brief Elements header file.
 *
 * Contents:
 *
 */

#include <array>
#include "Eigen/SparseLU"

#ifndef _elements_hpp
#define _elements_hpp

template<int pdim>
using Vectord = Eigen::Matrix<double, pdim, 1>

template <int pdim>
class Node
{
	protected:
		const int global_id;

	public:
		Node(int id);
};

template <int pdim>
class VertexNode : public Node
{
	protected:
		const Vectord<pdim> global_coords;

	public:
		VertexNode(Vectord<pdim> x, int id);
}

template <int pdim>
class InteriorNode : public Node
{
	protected:
		const Vectord<pdim> local_coords;

	public:
		InteriorNode(Vectord<pdim> lambda, int id);
}

class NodeElement1D
{
	protected:
		std::array<std::shared_ptr<Node<1> >, 2> vertex_nodes;

	public:
		NodeElement(std::array<std::shared_ptr<Node<pdim> >, 2> &vertices);
};

#endif //_elements_hpp
