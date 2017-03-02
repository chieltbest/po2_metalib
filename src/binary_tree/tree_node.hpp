//
// Created by chiel on 14/10/16.
//

#ifndef PO2_METALIB_TREE_NODE_HPP
#define PO2_METALIB_TREE_NODE_HPP

namespace bin_tree {

	/// basic node of the binary search tree
	/// \tparam d data of this node
	/// \tparam l left child of this node
	/// \tparam r right child of this node
	template<typename d, typename l, typename r>
	struct node {
		using r = node<d, l, r>;
		using data = d;
		using left = l;
		using right = r;
	};

	/// acts as a nullptr for a tree leaf,
	/// used when there is no value for the child
	struct leaf;

}

#endif //PO2_METALIB_TREE_NODE_HPP
