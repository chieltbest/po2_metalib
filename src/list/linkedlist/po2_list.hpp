//
// Created by chiel on 05/09/16.
//

#ifndef PO2_METALIB_TRACKED_LINKED_LIST_HPP
#define PO2_METALIB_TRACKED_LINKED_LIST_HPP

#include <algorithm>
#include "../split.hpp"

namespace po2_list {

	/// the maximum power of 2 that is currently supported in min_po2
	constexpr static unsigned int MAX_PO2{256};

	/// calculates the smallest power of two (the lowest bit) in n
	/// returning 16 if there are only higher powers than that
	/// \param n the number to calculate on
	/// \return the smallest power of two in n, up to 16
	/// \complexity O(1)
	constexpr unsigned int min_po2(unsigned int n) {
		return (n & (-n)) > MAX_PO2 ? MAX_PO2 : (n & (-n));
	}

	constexpr bool is_po2(unsigned int n) {
		return ((n - 1) & n) == 0;
	}

	// DATATYPES -------------------------------------------------------------------------------------------------------

	/// the final node in a power of two list, contains no data
	struct empty {
		using rest = empty;
		using data = list<>;

		/// \see section::force_instantiate
		///
		/// since the end node has no parameters, this function just returns end
		using force_instantiate = empty;
	};
	/// section in a power of two list
	/// \tparam elems a list with the data for this section of the list
	/// \tparam r the next section over in the power of two list
	template<typename next, typename elems>
	struct section {
		using rest = next;
		using data = elems;

		/// use this to recursively instantiate all lazy functions within this node
		///
		/// in practice this function should not be used, except for benchmarking purposes
		using force_instantiate = section<typename rest::force_instantiate, elems>;
	};

	// SPLIT_PO2 -------------------------------------------------------------------------------------------------------

	/// split the given list at the indicated power of two
	/// if the given number is not a power of two it will give a hard error
	/// \tparam n the power of two to split at
	/// \complexity O(n)
	template<unsigned int n>
	struct split_po2;
	template<>
	struct split_po2<256> {
		template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
			typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
			typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23,
			typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31,
			typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39,
			typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47,
			typename T48, typename T49, typename T50, typename T51, typename T52, typename T53, typename T54, typename T55,
			typename T56, typename T57, typename T58, typename T59, typename T60, typename T61, typename T62, typename T63,
			typename T64, typename T65, typename T66, typename T67, typename T68, typename T69, typename T70, typename T71,
			typename T72, typename T73, typename T74, typename T75, typename T76, typename T77, typename T78, typename T79,
			typename T80, typename T81, typename T82, typename T83, typename T84, typename T85, typename T86, typename T87,
			typename T88, typename T89, typename T90, typename T91, typename T92, typename T93, typename T94, typename T95,
			typename T96, typename T97, typename T98, typename T99, typename T100, typename T101, typename T102, typename T103,
			typename T104, typename T105, typename T106, typename T107, typename T108, typename T109, typename T110, typename T111,
			typename T112, typename T113, typename T114, typename T115, typename T116, typename T117, typename T118, typename T119,
			typename T120, typename T121, typename T122, typename T123, typename T124, typename T125, typename T126, typename T127,
			typename T128, typename T129, typename T130, typename T131, typename T132, typename T133, typename T134, typename T135,
			typename T136, typename T137, typename T138, typename T139, typename T140, typename T141, typename T142, typename T143,
			typename T144, typename T145, typename T146, typename T147, typename T148, typename T149, typename T150, typename T151,
			typename T152, typename T153, typename T154, typename T155, typename T156, typename T157, typename T158, typename T159,
			typename T160, typename T161, typename T162, typename T163, typename T164, typename T165, typename T166, typename T167,
			typename T168, typename T169, typename T170, typename T171, typename T172, typename T173, typename T174, typename T175,
			typename T176, typename T177, typename T178, typename T179, typename T180, typename T181, typename T182, typename T183,
			typename T184, typename T185, typename T186, typename T187, typename T188, typename T189, typename T190, typename T191,
			typename T192, typename T193, typename T194, typename T195, typename T196, typename T197, typename T198, typename T199,
			typename T200, typename T201, typename T202, typename T203, typename T204, typename T205, typename T206, typename T207,
			typename T208, typename T209, typename T210, typename T211, typename T212, typename T213, typename T214, typename T215,
			typename T216, typename T217, typename T218, typename T219, typename T220, typename T221, typename T222, typename T223,
			typename T224, typename T225, typename T226, typename T227, typename T228, typename T229, typename T230, typename T231,
			typename T232, typename T233, typename T234, typename T235, typename T236, typename T237, typename T238, typename T239,
			typename T240, typename T241, typename T242, typename T243, typename T244, typename T245, typename T246, typename T247,
			typename T248, typename T249, typename T250, typename T251, typename T252, typename T253, typename T254, typename T255,
			typename ...Ts>
		using r = pair<list<
			T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18,
			T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35,
			T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49, T50, T51, T52,
			T53, T54, T55, T56, T57, T58, T59, T60, T61, T62, T63, T64, T65, T66, T67, T68, T69,
			T70, T71, T72, T73, T74, T75, T76, T77, T78, T79, T80, T81, T82, T83, T84, T85, T86,
			T87, T88, T89, T90, T91, T92, T93, T94, T95, T96, T97, T98, T99, T100, T101, T102,
			T103, T104, T105, T106, T107, T108, T109, T110, T111, T112, T113, T114, T115, T116,
			T117, T118, T119, T120, T121, T122, T123, T124, T125, T126, T127, T128, T129, T130,
			T131, T132, T133, T134, T135, T136, T137, T138, T139, T140, T141, T142, T143, T144,
			T145, T146, T147, T148, T149, T150, T151, T152, T153, T154, T155, T156, T157, T158,
			T159, T160, T161, T162, T163, T164, T165, T166, T167, T168, T169, T170, T171, T172,
			T173, T174, T175, T176, T177, T178, T179, T180, T181, T182, T183, T184, T185, T186,
			T187, T188, T189, T190, T191, T192, T193, T194, T195, T196, T197, T198, T199, T200,
			T201, T202, T203, T204, T205, T206, T207, T208, T209, T210, T211, T212, T213, T214,
			T215, T216, T217, T218, T219, T220, T221, T222, T223, T224, T225, T226, T227, T228,
			T229, T230, T231, T232, T233, T234, T235, T236, T237, T238, T239, T240, T241, T242,
			T243, T244, T245, T246, T247, T248, T249, T250, T251, T252, T253, T254, T255>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<128> {
		template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
			typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
			typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23,
			typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31,
			typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39,
			typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47,
			typename T48, typename T49, typename T50, typename T51, typename T52, typename T53, typename T54, typename T55,
			typename T56, typename T57, typename T58, typename T59, typename T60, typename T61, typename T62, typename T63,
			typename T64, typename T65, typename T66, typename T67, typename T68, typename T69, typename T70, typename T71,
			typename T72, typename T73, typename T74, typename T75, typename T76, typename T77, typename T78, typename T79,
			typename T80, typename T81, typename T82, typename T83, typename T84, typename T85, typename T86, typename T87,
			typename T88, typename T89, typename T90, typename T91, typename T92, typename T93, typename T94, typename T95,
			typename T96, typename T97, typename T98, typename T99, typename T100, typename T101, typename T102, typename T103,
			typename T104, typename T105, typename T106, typename T107, typename T108, typename T109, typename T110, typename T111,
			typename T112, typename T113, typename T114, typename T115, typename T116, typename T117, typename T118, typename T119,
			typename T120, typename T121, typename T122, typename T123, typename T124, typename T125, typename T126, typename T127,
			typename ...Ts>
		using r = pair<list<
			T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18,
			T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35,
			T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49, T50, T51, T52,
			T53, T54, T55, T56, T57, T58, T59, T60, T61, T62, T63, T64, T65, T66, T67, T68, T69,
			T70, T71, T72, T73, T74, T75, T76, T77, T78, T79, T80, T81, T82, T83, T84, T85, T86,
			T87, T88, T89, T90, T91, T92, T93, T94, T95, T96, T97, T98, T99, T100, T101, T102,
			T103, T104, T105, T106, T107, T108, T109, T110, T111, T112, T113, T114, T115, T116,
			T117, T118, T119, T120, T121, T122, T123, T124, T125, T126, T127>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<64> {
		template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
			typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
			typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23,
			typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31,
			typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39,
			typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47,
			typename T48, typename T49, typename T50, typename T51, typename T52, typename T53, typename T54, typename T55,
			typename T56, typename T57, typename T58, typename T59, typename T60, typename T61, typename T62, typename T63,
			typename ...Ts>
		using r = pair<list<
			T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18,
			T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35,
			T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49, T50, T51, T52,
			T53, T54, T55, T56, T57, T58, T59, T60, T61, T62, T63>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<32> {
		template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
			typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
			typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23,
			typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31,
			typename ...Ts>
		using r = pair<list<
			T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18,
			T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<16> {
		template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
			typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15,
			typename ...Ts>
		using r = pair<list<
			T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<8> {
		template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7,
			typename ...Ts>
		using r = pair<list<T0, T1, T2, T3, T4, T5, T6, T7>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<4> {
		template<typename T0, typename T1, typename T2, typename T3,
			typename ...Ts>
		using r = pair<list<T0, T1, T2, T3>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<2> {
		template<typename T0, typename T1,
			typename ...Ts>
		using r = pair<list<T0, T1>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<1> {
		template<typename T0, typename ...Ts>
		using r = pair<list<T0>,
			list<Ts...>>;
	};
	template<>
	struct split_po2<0> {
		template<typename ...Ts>
		using r = pair<list<>,
			list<Ts...>>;
	};
	
	/// split the list Ts at the minimum power of 2 for the size of the list
	/// \tparam l the list to split
	/// \complexity O(n)
	template<typename l>
	struct split_mpo2;
	template<typename ...l>
	struct split_mpo2<list<l...>>
		: split_po2<min_po2(sizeof...(l))>::template r<l...> {};

	// JOIN ------------------------------------------------------------------------------------------------------------

	enum join_n_states {
		JOIN_JOIN,
		JOIN_END
	};

	constexpr join_n_states join_n_generator(unsigned int p2l_size, unsigned int add_size) {
		return min_po2(add_size) < p2l_size
		       || p2l_size == 0
		       || p2l_size == MAX_PO2
		       ? JOIN_END
		       : JOIN_JOIN;
	}

	template<join_n_states state>
	struct join_n_impl;
	template<>
	struct join_n_impl<JOIN_JOIN> {
		template<typename p2l, typename add>
		struct r;
		template<typename rest, typename ...elems, typename ...add>
		struct r<section<rest, list<elems...>>, list<add...>>
			: join_n_impl<join_n_generator(
				rest::data::size,
				sizeof...(add) + sizeof...(elems)
			)>::template r<
				rest,
				list<add..., elems...>
			> {};
	};
	template<>
	struct join_n_impl<JOIN_END> {
		template<typename p2l, typename add>
		using r = pair<p2l, add>;
	};

	// PUSH ------------------------------------------------------------------------------------------------------------

	enum push_front_states {
		PUSH_END,
		PUSH_SPLIT
	};

	/// gets the correct state that the push_front algorithm should go into
	/// \param p2l_size the size of the first section of the power of two list (p2l::data::size)
	/// \param add_size the size of the list of elements to be added
	/// \return the correct state that the algorithm should go into next
	constexpr push_front_states push_front_generator(unsigned int p2l_size, unsigned int add_size) {
		return add_size == 0
		       ? PUSH_END
		       : PUSH_SPLIT;
	}

	/// push the elements in \p add into the power of two list \p p2l
	///
	/// this is the actual implementation of the push_front generator/state machine
	/// push_impl is implemented as a state machine: (in plantuml)
	/// @startuml
	/// state create {
	///     state test_0 <<choice>>
	///     note right of test_0 : test for 0 length list\n(generator)
	///     [*] --> test_0
	///     test_0 --> Create : [sizeof...(Ts) > 0]
	///     test_0 --> end : [else]
	///     state Create : return section(split_mpo2(add...)::first,\n\
	///                      create(p2l, split_mpo2(add...)::second))
	///     Create --> test_0
	///     state end : return p2l
	///     end --> [*]
	/// }
	/// state push_front {
	///     state split_join <<choice>>
	///     note right of split_join
	///         check the minimum power of 2 of add to
	///         the size of the current p2l::data::size
	///     end note
	///
	///     state Join : join the front of the p2 list with add
	///
	///     state Split : split add at the minimum power of 2
	///
	///     split_join --> test_0 : [sizeof...(add) > p2l::data::size\n|| p2l::data::size == 0]
	///     split_join --> Join : [min_po2(sizeof...(add))\n>= p2l::data::size]
	///     Join --> split_join
	///     split_join --> Split : [else]
	///     Split --> split_join
	///
	///     [*] --> split_join : push_front
	/// }
	/// @enduml
	/// \complexity approx. O(n log(n))
	template<push_front_states state>
	struct push_impl;
	/// end, return the base (create 0)
	/// \complexity O(1)
	template<>
	struct push_impl<PUSH_END> {
		template<typename p2l, typename add>
		using r = p2l;
	};

	template<typename p2l, typename add>
	struct push_splitter {
		using joined = typename join_n_impl<join_n_generator(
			p2l::data::size,
			add::size)
		>::template r<
			p2l,
			add
		>;
		using split = split_mpo2<
			typename joined::second
		>;
		using r = section<
			// every iteration of the algorithm is characterised by zero or more
			// joins from the p2l, followed by a split
			typename push_impl<push_front_generator(
				joined::first::data::size,
				split::second::size)
			>::template r<
				typename joined::first,
				typename split::second
			>,
			typename split::first
		>;
	};
	/// split
	template<>
	struct push_impl<PUSH_SPLIT> {
		template<typename p2l, typename add>
		using r = typename push_splitter<p2l, add>::r;
	};

	/// push the elements in \p add into the power of two list \p p2l
	/// \tparam p2l the power of two list to push into
	/// \tparam add the elements to add to the power of two list
	template<typename p2l, typename ...add>
	using push = typename push_impl<push_front_generator(
		p2l::data::size,
		sizeof...(add)
	)>::template r<
		p2l,
		list<add...>
	>;

	// TODO make a push with two p2l's
	// TODO make efficient single element push

	/// create a power of two list from the elements specified by \p L
	///
	/// \tparam L the elements to create the list from
	template<typename ...L>
	using create = typename push_impl<push_front_generator(
		0,
		sizeof...(L)
	)>::template r<
		empty,
		list<L...>
	>;

	// TAKE ------------------------------------------------------------------------------------------------------------

	/*template<typename data, typename p2l>
	struct take_one_impl; // fail if there are no elements to be taken
	template<typename p2l, typename T, typename ...Ts>
	struct take_one_impl<list<T, Ts...>, p2l> {
		using r = pair<T, push<p2l, Ts...>>;
	};

	template<typename p2l>
	using take_one = take_one_impl<typename p2l::rest, typename p2l::data>*/

}

#endif //PO2_METALIB_TRACKED_LINKED_LIST_HPP
