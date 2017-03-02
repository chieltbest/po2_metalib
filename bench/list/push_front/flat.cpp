//
// Created by chiel on 08/09/16.
//

#include "../../../src/lib.hpp"
#include "../../../src/list/list.hpp"

using l = list<<%=
n.times.map{
"int_ci<0>"
}.join(",") %>>;

#ifdef METABENCH
<% env[:listsize].times do |i| %>
using pushed<%= i %> = push<l, int_ci<<%= i %>>>::r;<% end %>
#endif

int main() {
	return 0;
}