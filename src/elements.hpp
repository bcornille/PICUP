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
		//! Default constructor of Node.
		/*!
		 * Creates the node with a new unique ID number.
		 */
		Node();

		//! Virtual destructor.
		/*!
		 * Since Node is a base class the destructor should be virtual.
		 */
		virtual ~Node() = default;
};

//! Class for nodes that are the vertices of the mesh.
/*!
 * The vertices of the mesh require the nodal coordinates in the global
 * space region.
 */
template <int pdim>
class VertexNode : public Node<pdim>
{
	protected:
		/*! Global mesh coordinates of the vertex. */
		const Vectord<pdim> global_coords;

	public:
		//! Main conctructor of the vertex.
		/*!
		 * Places the vertex at position <CODE> x </CODE>.
		 *
		 * \param x
		 */
		VertexNode(Vectord<pdim> x);

		//! Get coordinates.
		/*!
		 */
		Vectord<pdim> getCoords();
};

// Forward declaration
class NodeElement1D;

template <int pdim>
class Edge
{
	protected:
		/*! Array of pointers to the vertices that the line segment is
		 * bound by. */
		std::array<VertexNode<pdim>*, 2> vertex_nodes;

		double edge_length;

	public:
		//! Main constructor for the Element.
		/*!
		 * Constructed using the array of pointers to VertexNode that
		 * will be used in the class.
		 *
		 * \param vertices
		 */
		Edge(std::array<VertexNode<pdim>*, 2> vertices);

		//! Get length.
		/*!
		 */
		double getLength();

		friend class std::conditional<pdim == 1, NodeElement1D, void>::type;
};

/* Currently not using interior nodes.
   template <int pdim>
   class InteriorNode : public Node<pdim>
   {
   protected:
   const Vectord<pdim> local_coords;

   public:
   InteriorNode(Vectord<pdim> lambda);
   };
   */

//! One-dimenstional 1st-order nodal (0-form) element.
/*!
 * This element uses linear (hat) basis functions.
 */
class NodeElement1D
{
	protected:
		//! Reference to the Edge that
		const Edge<1> &edge;

	public:
		//! Main constructor for the Element.
		/*!
		 * Constructed using the array of pointers to VertexNode that
		 * will be used in the class.
		 *
		 * \param vertices
		 */
		NodeElement1D(Edge<1> &edge_ref);
};

//! One-dimensional 1st-order edge (1-form) element.
/*!
 * This element uses a  Whitney 1-form basis function.  In one dimension
 * this is a constant value over the element.
 */

#endif //_elements_hpp
