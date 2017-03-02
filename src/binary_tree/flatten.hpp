//
// Created by chiel on 14/10/16.
//

#ifndef PO2_METALIB_FLATTEN_HPP
#define PO2_METALIB_FLATTEN_HPP

#include "tree_node.hpp"

namespace bin_tree {

	template<typename tree, typename result>
	struct flatten_impl;
	template<typename top_node, typename left, typename right, typename result>
	struct flatten_impl<node<top_node, left, right>, result> {
		// pushing to the back of a p2l is very inefficient, so pass down the complete list into the right side instead
		using r = typename flatten_impl<
			left,
			typename po2_list::template push<
				flatten_impl<
					right,
					result
				>::r,
				list<top_node>
			>
		>::r;
	};
	template<typename result>
	struct flatten_impl<leaf, result> {
		// a leaf has no elements; return the list that is already completed
		using r = result;
	};

	template<typename tree>
	using flatten = flatten_impl<tree, po2_list::create<>>::r;

}

#endif //PO2_METALIB_FLATTEN_HPP
