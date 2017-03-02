//
// Created by chiel on 14/10/16.
//

#include "../../../../src/list/linkedlist/po2_list.hpp"

template<unsigned int n>
struct generate_p2l_impl {
	template<typename T>
	using r = po2_list::push<
		typename generate_p2l_impl<
			n - 1
		>::template r<
			T
		>,
		T
	>;
};
template<>
struct generate_p2l_impl<0> {
	template<typename T>
	using r = po2_list::empty;
};

template<typename FillType, unsigned int n>
using generate_p2l = typename generate_p2l_impl<n>::template r<FillType>;

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using result<%= i %> = generate_p2l<int_ci<<%= i %>>, <%= n %>>;<% end %>
#endif

int main() {
	return 0;
}