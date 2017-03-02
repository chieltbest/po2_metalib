cmake_minimum_required(VERSION 3.0)
project(po2_metalib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-depth=2048 -std=c++11")

add_executable(main src/main.cpp)

add_custom_target(metashell
		COMMAND bash run_metashell.sh
#		COMMAND bash run_metashell.sh | grep Template
		WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/src
		USES_TERMINAL)

add_custom_command(OUTPUT doc/build/latex/refman.pdf
		COMMAND doxygen
		COMMAND make -C build/latex/
		WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/doc
		DEPENDS src/*)
add_custom_target(documentation DEPENDS doc/build/latex/refman.pdf)



if(METABENCH_PRECOMPILE)
	message("Using ${METABENCH_PRECOMPILE}")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/bench/metabench")
include(metabench)

add_subdirectory(bench/metabench)

macro(set_repetitions n)
	set(repetitions ${n})
	set(REPEAT ENV "{listsize:${n}}" SCALE "1.0/(${n})")
endmacro(set_repetitions)

set(FLAT_NAME NAME "flat" COLOR "rgb(0, 0, 255)")
set(LINKED_NAME NAME "linked" COLOR "rgb(255, 0, 0)")
set(PO2_NAME NAME "po2" COLOR "rgb(0, 200, 0)")

set_repetitions(100)
metabench_add_dataset(flat_list_create
		bench/list/create/flat.cpp			"(0..128).to_a + (136..512).step(8).to_a"	${REPEAT} ${FLAT_NAME})
metabench_add_dataset(linked_list_create
		bench/list/create/linked.cpp		"(0..128).step(4)"							${REPEAT} ${LINKED_NAME})
metabench_add_dataset(po2_list_create
		bench/list/create/po2.cpp			"(0..128).to_a + (136..512).step(8).to_a"	${REPEAT} ${PO2_NAME})
metabench_add_chart(list_create_bench
		TITLE "creating a list of n elements"
		SUBTITLE "(smaller is better)"
		DATASETS flat_list_create linked_list_create po2_list_create)

set_repetitions(10001)
metabench_add_dataset(flat_list_push_front
		bench/list/push_front/flat.cpp		"(0..512)"									${REPEAT} ${FLAT_NAME})
metabench_add_dataset(linked_list_push_front
		bench/list/push_front/linked.cpp	"(0..256)"									${REPEAT} ${LINKED_NAME})
metabench_add_dataset(po2_push_front
		bench/list/push_front/po2.cpp		"(0..512)"									${REPEAT} ${PO2_NAME})
metabench_add_chart(push_front_bench
		TITLE "pushing 1 element to the front of an array of n elements"
		SUBTITLE "(smaller is better)"
		DATASETS flat_list_push_front linked_list_push_front po2_push_front)

set_repetitions(10)
metabench_add_dataset(flat_list_push_n_front
		bench/list/push_front/n_times_1/flat.cpp			"(0..512).step(8)"			${REPEAT} ${FLAT_NAME})
metabench_add_dataset(linked_list_push_n_front
		bench/list/push_front/n_times_1/linked.cpp			"(0..252).step(8)"			${REPEAT} ${LINKED_NAME})
metabench_add_dataset(eager_linked_list_push_n_front
		bench/list/push_front/n_times_1/linked_eager.cpp	"(0..256).step(8)"			${REPEAT} NAME "linked (eager)" COLOR "hsl(100%, 50%, 0)")
metabench_add_dataset(po2_push_n_front
		bench/list/push_front/n_times_1/po2.cpp				"(0..512)"					${REPEAT} ${PO2_NAME})
metabench_add_chart(push_n_front_bench
		TITLE "pushing 1 element n times to the front of an array"
		SUBTITLE "(smaller is better)"
		DATASETS flat_list_push_n_front linked_list_push_n_front eager_linked_list_push_n_front po2_push_n_front)

#[[metabench_add_dataset(flat_list_take bench/list/take/flat.cpp "(0..128).step(4)" NAME "flat")
metabench_add_dataset(linked_list_take bench/list/take/linked.cpp "(0..128).step(4)" NAME "linked")
metabench_add_dataset(po2_take bench/list/take/po2.cpp "(0..128)" NAME "po2")
metabench_add_chart(push_front_bench
		TITLE "taking n elements off the front of an array of 128 elements"
		SUBTITLE "(smaller is better)"
		DATASETS flat_list_push_front linked_list_push_front po2_push_front INTERPOLATE)]]

add_custom_target(list_benches DEPENDS list_create_bench push_front_bench push_n_front_bench)
