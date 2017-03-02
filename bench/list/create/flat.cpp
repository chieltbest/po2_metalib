//
// Created by chiel on 08/09/16.
//

#include "../../../src/lib.hpp"
#include "../../../src/list/list.hpp"

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using r<%= i %> = list<<%=
n.times.map{
	"int_ci<#{i}>"
}.join(",") %>>;<% end %>
#endif

int main() {
	return 0;
}