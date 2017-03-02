//
// Created by chiel on 14/10/16.
//

#include "../../../../src/list/linkedlist/linked_list.hpp"

template<unsigned int n>
struct int_ci {
	constexpr static unsigned int value{n};
};

template<unsigned int n>
struct generate_linked_impl {
	template<typename T>
	using r = typename linked_list::push<
		typename generate_linked_impl<
			n - 1
		>::template r<
			T
		>,
		T
	>;
};
template<>
struct generate_linked_impl<0> {
	template<typename T>
	using r = linked_list::create<>;
};

template<typename FillType, unsigned int n>
using generate_linked = typename generate_linked_impl<n>::template r<FillType>;

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using r<%= i %> = generate_linked<int_ci<<%= i %>>, <%= n %>>;<% end %>
#endif

int main() {
	return 0;
}