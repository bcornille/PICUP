/*!
 * \file
 * \brief Elements header file.
 *
 * Contents:
 *
 */

#ifndef _elements_hpp
#define _elements_hpp

template <int pdim>
class Node
{
	protected:
		Eigen::Matrix<double, pdim, 1> global_coords;

		int global_id
};

template <int pdim>
class Element
{
	protected:
		std::array<&Node<pdim>, 1 << pdim >
};

template <int pdim>
class Vertex : public Node
{
	private:
};

#endif //_elements_hpp
