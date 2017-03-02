//
// Created by chiel on 08/09/16.
//

#include "../../../src/list/linkedlist/po2_list.hpp"

using l = po2_list::create<<%=
n.times.map{
	"int_ci<0>"
}.join(",") %>>;

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using result<%= i %> = po2_list::push<l, int_ci<<%= i %>>>;<% end %>
#endif

int main() {
	return 0;
}
