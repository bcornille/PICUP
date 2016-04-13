/*!
 * \file
 * \brief Elements header file.
 *
 * Contents:
 *
 */

#ifndef _elements_hpp
#define _elements_hpp

template<int pdim>
using Vectord = Eigen::Matrix<double, pdim, 1>

template <int pdim>
class Node
{
	protected:
		const Vectord<pdim> local_coords;

		const int global_id;

	public:
		Node(Vectord<pdim> lambda, int id);
};

template <int pdim>
class VertexNode : public Node
{
	protected:
		const Vectord<pdim> global_coords;

	public:
		VertexNode(Vectord<pdim> x, Vectord<pdim> lambda, int id);
}

template <int pdim>
class NodeElement
{
	protected:
		std::array<shared_ptr<Node<pdim> >, 1 << pdim > vertex_nodes;

	public:
		NodeElement(std::array<Vector<pdim>, 1 << pdim > x);
};

#endif //_elements_hpp
