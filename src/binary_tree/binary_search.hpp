//
// Created by chiel on 14/10/16.
//

#ifndef PO2_METALIB_BINARY_SEARCH_HPP
#define PO2_METALIB_BINARY_SEARCH_HPP

#include "../lib.hpp"
#include "tree_node.hpp"

namespace bin_tree {

	/// this separate implementation struct for the insert is to delay instantiation of the insert call
	/// that means we can traverse the tree using aliases while only expanding one path
	/// \tparam side the side that the comparator resolved to
	template<bool side>
	struct insert_impl;
	template<>
	struct insert_impl<true> { // left
		template<typename node_elem, typename left, typename right, typename elem,
			template<typename lhs, typename rhs> class compare>
		using r = node<node_elem, insert<left, elem, compare>::r, right>;
	};
	template<>
	struct insert_impl<false> { // right
		template<typename node_elem, typename left, typename right, typename elem,
			template<typename lhs, typename rhs> class compare>
		using r = node<node_elem, left, insert<right, elem, compare>::r>;
	};

	/// insert an element into a binary search tree
	/// the search tree implementation is not balanced
	/// \tparam tree the tree to insert into, it is assumed the tree is balanced
	/// \tparam elem the element to insert into the tree, must be comparable with \p comparator
	/// \tparam compare the function to compare the inserted element and the elements in the tree with.
	///                 checks whether the lhs of the comparator is greater than the rhs.
	///                 compare should implement the r member to return a bool.
	template<typename tree, typename elem,
		template<typename lhs, typename rhs> class compare>
	struct insert;

	template<typename node_elem, typename left, typename right, typename elem,
		template<typename lhs, typename rhs> class compare>
	struct insert<node<node_elem, left, right>, elem, compare> {
		using r = typename insert_impl<
			compare<node_elem, elem>::r
		>::template r< // delayed instantiation because of the separate function
			node_elem, left, right, elem, compare
		>;
	};

	/// when a leaf is found, insert the actual element as the leaf
	template<typename elem, typename compare>
	struct insert<leaf, elem, compare> {
		using r = node<elem, leaf, leaf>;
	};

	template<typename l, typename compare>
	struct insert<> {
		// TODO use p2l's fold to mass insert
	};

}

#endif //PO2_METALIB_BINARY_SEARCH_HPP
