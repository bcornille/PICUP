/*!
 * \file
 * \brief Elements header file.
 *
 * Contents:
 *
 */

#include <array>
#include <atomic>
#include "Eigen/SparseLU"

#ifndef _elements_hpp
#define _elements_hpp

//! Templated typedef for an Eigen-type vector of doubles.
template<int pdim>
using Vectord = Eigen::Matrix<double, pdim, 1>;

//! A template class definition of a Node.
/*!
 * Node is largely just a base class. It is responsilbe for generating
 * sequential list of uniquely defined nodes.
 */
template <int pdim>
class Node
{
	protected:
		/*! Static counter of ID number. */
		static std::atomic<int> s_id;
		const int global_id; /*!< Global ID of the node. */

	public:
		Node();
		virtual ~Node() = default;
};

template <int pdim>
class VertexNode : public Node<pdim>
{
	protected:
		const Vectord<pdim> global_coords;

	public:
		VertexNode(Vectord<pdim> x);
};

template <int pdim>
class InteriorNode : public Node<pdim>
{
	protected:
		const Vectord<pdim> local_coords;

	public:
		InteriorNode(Vectord<pdim> lambda);
};

class NodeElement1D
{
	protected:
		std::array<VertexNode<1>*, 2> vertex_nodes;

	public:
		NodeElement1D(std::array<VertexNode<1>*, 2> vertices);
};

#endif //_elements_hpp
