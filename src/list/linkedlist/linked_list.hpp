//
// Created by chiel on 08/09/16.
//

#ifndef PO2_METALIB_LINKED_LIST_HPP
#define PO2_METALIB_LINKED_LIST_HPP

namespace linked_list {

	struct end;

	template<typename d, typename n>
	struct node {
		using data = d;
		using next = n;
	};

	template<typename l, typename ...Ts>
	struct push_impl;
	template<typename l, typename T, typename ...Ts>
	struct push_impl<l, T, Ts...> {
		using r = node<T, typename push_impl<l, Ts...>::r>;
	};
	template<typename l>
	struct push_impl<l> {
		using r = l;
	};

	template<typename l, typename ...Ts>
	using push = typename push_impl<l, Ts...>::r;

	template<typename ...Ts>
	using create = typename push_impl<end, Ts...>::r;

}

#endif //PO2_METALIB_LINKED_LIST_HPP
