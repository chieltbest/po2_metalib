//
// Created by chiel on 02/09/16.
//

#ifndef PO2_METALIB_LIB_HPP
#define PO2_METALIB_LIB_HPP

constexpr int floor_log2(const unsigned int i) {
	return i < 1 ? 0 : i < 2 ? 1 : i < 4 ? 2 : i < 8 ? 3 : i < 16 ? 4 : i < 32 ? 5 : i < 64 ? 6 : i < 128 ? 7 : i < 256 ? 8 : 9;
}

constexpr int floor_log2_16(const unsigned int i) {
	return i < 1 ? 0 : i < 2 ? 1 : i < 4 ? 2 : i < 8 ? 3 : i < 16 ? 4 : 5;
}

template<typename T, T N>
struct const_int {
	using type = T;

	constexpr static T value = N;
};

template<int n>
using int_ci = const_int<int, n>;
template<unsigned int n>
using uint_ci = const_int<unsigned int, n>;

template<unsigned int n>
struct i_ : const_int<unsigned int, n> {};

/// conditional, checks \p val, and return either the first type if true, or second type if false
template<bool val>
struct cond;
template<>
struct cond<true> {
	template<typename A, typename B>
	using r = A;
}; template<>
struct cond<false> {
	template<typename A, typename B>
	using r = B;
};

/// a simple wrapper that returns the wrapped element, useful in cond and such
template<typename T>
struct wrap {
	using r = T;
};

#ifndef TEMPLATE_PRINTER_DISABLE
/// creates an instantiation-time warning that prints the type(s) given
#endif

#endif //PO2_METALIB_LIB_HPP
