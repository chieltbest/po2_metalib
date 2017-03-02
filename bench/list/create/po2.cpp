//
// Created by chiel on 08/09/16.
//

#include "../../../src/list/linkedlist/po2_list.hpp"

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using r<%= i %> = po2_list::create<<%=
n.times.map{
	"i_<#{i}>"
}.join(",") %>>::force_instantiate;<% end %>
#endif

int main() {
	return 0;
}
