/*!
 * \file
 * \brief Elements header file.
 *
 * Contents:
 *
 */

#include <array>
#include <atomic>
#include <memory>
#include "Eigen/SparseLU"
#include "random.hpp"

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
class Vertex : public Node<pdim>
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
		Vertex(Vectord<pdim> x);

		//! Get coordinates.
		/*!
		*/
		Vectord<pdim> getCoords();
};

// Forward declaration
//class Element1DZeroForm;

//! Class describing edges.
/*!
 * Points to two VertexNode describing a line segement. Is also
 * conditionally a friend of NodeElement1D when the class is Edge<1>.
 * This is to allows NodeElement1D to read the variables in Edge
 * directly. (This is not necessary, but I think it will be convenient.)
 */
template <int pdim>
class Edge
{
	protected:
		/*! Static counter of ID number. */
		static std::atomic<int> s_id;
		const int global_id; /*!< Global ID of the edge. */

		/*! Array of pointers to the vertices that the line segment is
		 * bound by. */
		std::array<std::shared_ptr<Vertex<pdim> >, 2> endpoints;

		/*! Length of the edge in the mesh space. */
		double edge_length;

	public:
		//! Main constructor for Edge.
		/*!
		 * Constructed using the array of pointers to VertexNode that
		 * will be used in the class.
		 *
		 * \param vertices
		 */
		Edge(std::array<std::shared_ptr<Vertex<pdim> >, 2> vertices);

		//! Get length.
		/*!
		 * \returns <CODE> edge_length </CODE>
		 */
		double getLength() const;

		//friend clas s std::conditional<pdim == 1, NodeElement1D, void>::type;
};

//! Class describing a 1D cell.
/*!
 * A cell in one dimension is an Edge.
 */
class Cell1D : public Edge<1>
{
	protected:
		std::uniform_real_distribution<double> distribution;

	public:
		//! Main constructor for Cell1D
		/*!
		 * Constructs the Edge.
		 *
		 * \param vertices
		 */
		Cell1D(std::array<std::shared_ptr<Vertex<1> >, 2> vertices);

		//! Get cell size.
		/*!
		*/
		double getSize() const { return getLength(); };

		Vectord<1> sampleCell();
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

//! One-dimenstional 1st-order 0-form element.
/*!
 * This element uses linear (hat) basis functions.
 */
class Element1DZeroForm
{
	protected:
		//! Reference to the Cell that the element exists on.
		const Cell1D &cell;

	public:
		//! Main constructor for the Element.
		/*!
		 * Constructed with a reference to the cell of the element.
		 *
		 * \param cell_ref
		 */
		Element1DZeroForm(Cell1D &cell_ref);
};

//! One-dimensional 1st-order edge (1-form) element.
/*!
 * This element uses a  Whitney 1-form basis function.  In one dimension
 * this is a constant value over the element.
 */
class Element1DOneForm
{
	protected:
		//! Reference to the Cell that the element exists on.
		const Cell1D &cell;

	public:
		//! Main constructor for the Element.
		/*!
		 * Constructed with a reference to the cell of the element.
		 *
		 * \param cell_ref
		 */
		Element1DOneForm(Cell1D &cell_ref);

};

#endif //_elements_hpp
