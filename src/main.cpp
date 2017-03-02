//
// Created by chiel on 12/10/16.
//

#include "list/linkedlist/po2_list.hpp"
template<unsigned int n> struct generate_p2l_impl { template<typename T> using r = typename po2_list::push<typename generate_p2l_impl<n - 1>::template r<T>, T >; };
template<> struct generate_p2l_impl<0> { template<typename T> using r = po2_list::empty; };
template<typename FillType, unsigned int n> using generate_p2l = typename generate_p2l_impl<n>::template r<FillType>;

int main() {
	return 0;
}