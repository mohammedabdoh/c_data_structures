cmake_minimum_required(VERSION 3.20)
project(new C)

set(CMAKE_C_STANDARD 11)

add_executable(c_data_structures array_of_structs.c)
add_executable(c_data_structures2 arrays_as_parameters.c)
add_executable(c_data_structures3 functions.c)
add_executable(c_data_structures4 functions_parameters_passing.c)
add_executable(c_data_structures5 pointer_to_structure.c)
add_executable(c_data_structures6 pointers.c)
add_executable(c_data_structures7 struct_and_functions.c)

# recursion
add_executable(c_data_structures8 recursion/sum.c)
add_executable(c_data_structures9 recursion/combination_formula.c)
add_executable(c_data_structures10 recursion/factorial.c)
add_executable(c_data_structures11 recursion/fibonacci.c)
add_executable(c_data_structures12 recursion/power.c)
add_executable(c_data_structures13 recursion/taylor.c)
add_executable(c_data_structures14 recursion/taylor_horner_role.c)

# arrays
add_executable(c_data_structures15 arrays/2d_arrays.c)
add_executable(c_data_structures16 arrays/declaration.c)
add_executable(c_data_structures17 arrays/resizing_an_array.c)

# strings
add_executable(c_data_structures18 strings/compare_strings.c)
add_executable(c_data_structures19 strings/count_number_of_words.c)
add_executable(c_data_structures20 strings/find_duplicates_using_hash_table.c)
add_executable(c_data_structures21 strings/reverse_string.c)