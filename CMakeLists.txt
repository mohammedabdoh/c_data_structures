cmake_minimum_required(VERSION 3.20)
project(new C CXX)

add_executable(array_of_structs array_of_structs.c)
add_executable(arrays_as_parameters arrays_as_parameters.c)
add_executable(functions functions.c)
add_executable(functions_parameters_passing functions_parameters_passing.c)
add_executable(pointer_to_structure pointer_to_structure.c)
add_executable(pointers pointers.c)
add_executable(struct_and_functions struct_and_functions.c)
add_executable(bitwise_operations bitwise_operations.c)
add_executable(pass_by_reference pass_by_reference.cpp)
add_executable(rectangle rectangle.cpp)
add_executable(rectangle_template rectangle_template.cpp)

# recursion
add_executable(sum recursion/sum.c)
add_executable(combination_formula recursion/combination_formula.c)
add_executable(factorial recursion/factorial.c)
add_executable(fibonacci recursion/fibonacci.c)
add_executable(power recursion/power.c)
add_executable(taylor recursion/taylor.c)
add_executable(taylor_horner_role recursion/taylor_horner_role.c)

# arrays
add_executable(2d_arrays arrays/2d_arrays.c)
add_executable(declaration arrays/declaration.c)
add_executable(resizing_an_array arrays/resizing_an_array.c)

# strings
add_executable(compare_strings strings/compare_strings.c)
add_executable(count_number_of_words strings/count_number_of_words.c)
add_executable(find_duplicates_using_hash_table strings/find_duplicates_using_hash_table.c)
add_executable(reverse_string strings/reverse_string.c)
add_executable(find_duplicates_using_bitwise strings/find_duplicates_using_bitwise.c)
add_executable(string_is_anagram_using_hash_table strings/string_is_anagram_using_hash_table.c)
add_executable(string_is_anagram_using_bitwise strings/string_is_anagram_using_bitwise.c)

# linked list
add_executable(linked_list linked-list/linked_list.c)
add_executable(linked_list_cpp linked-list/linked_list.cpp)
add_executable(doubly_linked_list linked-list/doubly_linked_list.c)
add_executable(doubly_linked_list_cpp linked-list/doubly_linked_list.cpp)
add_executable(doubly_linked_list_with_tail linked-list/doubly_linked_list_with_tail.c)
add_executable(doubly_linked_list_with_tail_cpp linked-list/doubly_linked_list_with_tail.cpp)

# stack
add_executable(stack_using_list stack/stack.c)
add_executable(stack_using_list_cpp stack/stack.cpp)
add_executable(stack_using_array stack/stack_using_array.c)
add_executable(stack_using_array_cpp stack/stack_using_array.cpp)

# queue
add_executable(queue_using_array queue/queue_using_array.c)
add_executable(queue_using_list queue/queue_using_list.c)
add_executable(queue_using_array_cpp queue/queue_using_array.cpp)