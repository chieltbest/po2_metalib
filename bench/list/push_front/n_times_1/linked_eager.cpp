//
// Created by chiel on 14/10/16.
//

template<unsigned int n>
struct int_ci {
	constexpr static unsigned int value{n};
};

namespace linked_list {

	struct end {
		using last = void;
	};

	template<typename d, typename n>
	struct node : n {
		using next = n;
		using data = d;
	};

	template<typename l, typename ...Ts>
	struct push_impl : l {};
	template<typename l, typename T, typename ...Ts>
	struct push_impl<l, T, Ts...>
		: node<T, push_impl<l, Ts...>> {};

	template<typename l, typename ...Ts>
	using push = push_impl<l, Ts...>;

	template<typename l, typename T>
	using push_one = node<T, l>;

	template<typename ...Ts>
	using create = push_impl<end, Ts...>;

}

template<unsigned int n, typename T>
struct generate_linked_impl
	: linked_list::push_one<
		generate_linked_impl<
			n - 1,
			T>,
		T> {};
template<typename T>
struct generate_linked_impl<0, T>
	: linked_list::create<> {};

template<typename FillType, unsigned int n>
using generate_linked = generate_linked_impl<n, FillType>;

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using r<%= i %> = generate_linked<int_ci<<%= i %>>, <%= n %>>::last;<% end %>
#endif

int main() {
	return 0;
}