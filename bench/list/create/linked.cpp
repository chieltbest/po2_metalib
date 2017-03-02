//
// Created by chiel on 08/09/16.
//

#include "../../../src/lib.hpp"
#include "../../../src/list/linkedlist/linked_list.hpp"

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using r<%= i %> = linked_list::create<<%=
n.times.map{
	"int_ci<#{i}>"
}.join(",") %>>;<% end %>
#endif

int main() {
	return 0;
}
