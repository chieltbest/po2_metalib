//
// Created by chiel on 07/09/16.
//

#include "../../../src/list/list.hpp"
#include "../../../src/lib.hpp"

template<bool Big, int N, typename T, typename...Ts>
struct at_impl {
	using r = at_impl<false, N - 1, Ts...>::r;
};

template<int N, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename...Ts>
struct at_impl<true, N, T0, T1, T2, T3, T4, T5, T6, T7, Ts...> {
	at_impl<(N >= 16), N - 8, Ts...>;
};

template<typename T, typename...Ts>
struct at_impl<false, 0,T,Ts...> {
	using type = T;
};

template<int N, typename...Ts>
using at = at_impl<(N >= 8), N, Ts...>;

#ifdef METABENCH
<% 100.times do |i| %>
using r<%= i %> = at<<%= n %>, i<<%= (0..127).to_a.join('>, i<') %>>, i<<%= i %>>>::type;<% end %>
#endif

int main() {
	return 0;
}