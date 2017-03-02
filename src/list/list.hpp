//
// Created by chiel on 06/09/16.
//

#ifndef PO2_METALIB_LIST_HPP
#define PO2_METALIB_LIST_HPP

template<typename ...Ts>
struct list {
	/// return self; used for force evaluating lazy functions
	using force_instantiate = list<Ts...>;

	template<template<typename ...> class F>
	struct unpack {
		template<typename ...params>
		using r = F<params..., Ts...>;
	};

	constexpr static unsigned int size{sizeof...(Ts)};
};

template<typename l, typename ...elems>
struct push;
template<typename ...l, typename ...elems>
struct push<list<l...>, elems...> {
	using r = list<elems..., l...>;
};

template<typename l, typename ...elems>
struct push_back;
template<typename ...l, typename ...elems>
struct push_back<list<l...>, elems...> {
	using r = list<l..., elems...>;
};

template<typename l1, typename l2>
using join = typename l1::template unpack<push>::template r<l2>::r;

namespace lfunc {
	template<unsigned int n>
	struct generate_impl {
		template<typename T>
		using r = typename push<typename generate_impl<n - 1>::template r<T>, T>::r;
	};
	template<>
	struct generate_impl<0> {
		template<typename T>
		using r = list<>;
	};

	template<typename FillType, unsigned int n>
	using generate = typename generate_impl<n>::template r<FillType>;
}

#endif //PO2_METALIB_LIST_HPP
