#define TEMPLATE_PRINTER_DISABLE
#include "list/linkedlist/po2_list.hpp"
template<unsigned int n> struct generate_p2l_impl { template<typename T> using r = typename po2_list::push<typename generate_p2l_impl<n - 1>::template r<T>, T >; };
template<> struct generate_p2l_impl<0> { template<typename T> using r = po2_list::empty; };
template<typename FillType, unsigned int n> using generate_p2l = typename generate_p2l_impl<n>::template r<FillType>;

//using l = generate_p2l<i_<0>, 4>;
using l = po2_list::create<i_<0>, i_<0>, i_<0>, i_<0>>::force_instantiate;
l

#msh mdb generate_p2l<i_<0>, 4>
ft

e po2_list::push<l, i_<0>>
ft
