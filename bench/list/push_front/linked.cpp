//
// Created by chiel on 08/09/16.
//

#include "../../../src/lib.hpp"
#include "../../../src/list/linkedlist/linked_list.hpp"

using l =
<%= n.times.map{"linked_list::node<int_ci<0>,"}.join() %>
	linked_list::end
<%= n.times.map{">"}.join() %>;

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using pushed<%= i %> = linked_list::push<l, int_ci<<%= i %>>>;<% end %>
#endif

int main() {
	return 0;
}