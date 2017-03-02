//
// Created by chiel on 07/09/16.
//

#include "../../../src/list/list.hpp"
#include "../../../src/lib.hpp"

template<int N, typename T, typename...Ts>
struct at {
	using r = at<N-1,Ts...>::r;
};
template<typename T, typename...Ts>
struct at<0,T,Ts...> {
	using type = T;
};

#ifdef METABENCH
<% 100.times do |i| %>
using r<%= i %> = at<<%= n %>, i<<%= (0..127).to_a.join('>, i<') %>>, i<<%= i %>>>::type;<% end %>
#endif

int main() {
	return 0;
}