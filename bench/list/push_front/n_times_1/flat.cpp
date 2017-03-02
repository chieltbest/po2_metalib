//
// Created by chiel on 14/10/16.
//

#include "../../../../src/list/list.hpp"

template<unsigned int n>
struct int_ci {
	constexpr static unsigned int value{n};
};

template<unsigned int n>
struct generate_impl {
	template<typename T>
	using r = typename push<
		typename generate_impl<
			n - 1
		>::template r<
			T
		>,
		T
	>::r;
};
template<>
struct generate_impl<0> {
	template<typename T>
	using r = list<>;
};

template<typename FillType, unsigned int n>
using generate = typename generate_impl<n>::template r<FillType>;

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using r<%= i %> = generate<int_ci<<%= i %>>, <%= n %>>;<% end %>
#endif

int main() {
	return 0;
}