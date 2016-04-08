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
		const Vectord global_coords;

		int global_id;

	public:
		Node(Vectord x);
};

template <int pdim>
class NodeElement
{
	protected:
		std::array<shared_ptr<Node<pdim> >, 1 << pdim > vertex_nodes;

	public:
};

#endif //_elements_hpp
