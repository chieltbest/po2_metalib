//
// Created by chiel on 07/09/16.
//

#include "../../../src/list/list.hpp"
#include "../../../src/lib.hpp"

constexpr int selector(const int i) {
	return i < 1 ? 0 : i < 2 ? 1 : 8;
}

template<int I>
struct at_generator;
template<>
struct at_generator<8> {
	template<int I, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename...Ts>
	using f = typename at_generator<selector(I - 8)>::template f<I - 8, Ts...>;
};

template<>
struct at_generator<1> {
	template<int I, typename T, typename...Ts>
	using f = typename at_generator<selector(I - 1)>::template f<I - 1, Ts...>;
};

template<>
struct at_generator<0> {
	template<int I, typename T, typename...Ts>
	using f = T;
};

template<int I, typename...Ts>
using at = typename at_generator<selector(I)>::template f<I, Ts...>;

#ifdef METABENCH
<% 100.times do |i| %>
using r<%= i %> = at<<%= n %>, i<<%= (0..127).to_a.join('>, i<') %>>, i<<%= i %>>>::type;<% end %>
#endif

int main() {
	return 0;
}