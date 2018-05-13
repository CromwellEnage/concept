// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_HPP
#define BOOST_CONCEPT_TRAITS_HPP

#include <boost/concept/traits/introspection/nested_type/has_result_type.hpp>
#include <boost/concept/traits/trivial_access/result_type_of.hpp>
#include <boost/concept/traits/query/is_accumulator.hpp>
#include <boost/concept/traits/introspection/is_convertible_to_cref_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_assign.hpp>
#include <boost/concept/traits/query/is_lvalue_assignable.hpp>
#include <boost/concept/traits/query/is_rvalue_assignable.hpp>
#include <boost/concept/traits/introspection/is_raw_reference_of.hpp>
#include <boost/concept/traits/query/is_pre_incrementable.hpp>
#include <boost/concept/traits/query/is_incrementable.hpp>
#include <boost/concept/traits/query/is_pre_decrementable.hpp>
#include <boost/concept/traits/query/is_decrementable.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_plus_assign.hpp>
#include <boost/concept/traits/query/is_addition_assignable.hpp>
#include <boost/concept/traits/query/is_addable.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_minus_assign.hpp>
#include <boost/concept/traits/query/is_subtraction_assignable.hpp>
#include <boost/concept/traits/query/is_subtractable.hpp>
#include <boost/concept/traits/query/is_additive.hpp>
#include <boost/concept/traits/query/is_multiply_assignable.hpp>
#include <boost/concept/traits/query/is_multipliable.hpp>
#include <boost/concept/traits/query/is_division_assignable.hpp>
#include <boost/concept/traits/query/is_dividable.hpp>
#include <boost/concept/traits/query/is_modulo_assignable.hpp>
#include <boost/concept/traits/query/is_modulo_operable.hpp>
#include <boost/concept/traits/query/is_multiplicative.hpp>
#include <boost/concept/traits/query/is_identity_operable.hpp>
#include <boost/concept/traits/query/is_negatable.hpp>
#include <boost/concept/traits/query/is_logically_negatable.hpp>
#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include <boost/concept/traits/query/is_less_than_comparable.hpp>
#include <boost/concept/traits/query/is_comparable.hpp>
#include <boost/concept/traits/query/is_math_real_type.hpp>
#include <boost/concept/traits/introspection/nested_type/has_int_type.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_numerator.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_denominator.hpp>
#include <boost/concept/traits/query/is_math_rational_type.hpp>
#include <boost/concept/traits/introspection/nested_type/has_reference.hpp>
#include <boost/concept/traits/trivial_access/reference_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_reference_of.hpp>
#include <boost/concept/traits/query/is_subscriptable.hpp>
#include <boost/concept/traits/query/is_unary_function.hpp>
#include <boost/concept/traits/query/is_binary_function.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_argument_type.hpp>
#include <boost/concept/traits/trivial_access/argument_type_of.hpp>
#include <boost/concept/traits/query/is_adaptable_unary_func.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_first_argument_type.hpp>
#include <boost/concept/traits/trivial_access/first_argument_type_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_second_argument_type.hpp>
#include <boost/concept/traits/trivial_access/second_argument_type_of.hpp>
#include <boost/concept/traits/query/is_adaptable_binary_func.hpp>
#include <boost/concept/traits/query/is_callable.hpp>
#include <boost/concept/traits/introspection/is_result_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_result_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_min.hpp>
#include <boost/concept/traits/introspection/member_function/has_max.hpp>
#include <boost/concept/traits/query/is_value_generator.hpp>
#include <boost/concept/traits/introspection/member_function/has_reset.hpp>
#include <boost/concept/traits/query/is_value_distribution.hpp>
#include <boost/concept/traits/introspection/nested_type/has_param_type.hpp>
#include <boost/concept/traits/trivial_access/param_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_param.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_distribution_type.hpp>
#include <boost/concept/traits/trivial_access/distribution_type_of.hpp>
#include <boost/concept/traits/query/is_value_distribution_w_prm.hpp>
#include <boost/concept/traits/introspection/nested_type/has_first_type.hpp>
#include <boost/concept/traits/trivial_access/first_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_first_type_of.hpp>
#include <boost/concept/traits/introspection/member_data/has_first.hpp>
#include <boost/concept/traits/introspection/nested_type/has_second_type.hpp>
#include <boost/concept/traits/trivial_access/second_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_second_type_of.hpp>
#include <boost/concept/traits/introspection/member_data/has_second.hpp>
#include <boost/concept/traits/query/is_half_runtime_pair.hpp>
#include <boost/concept/traits/query/is_runtime_pair.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/traits/introspection/member_function/has_real.hpp>
#include <boost/concept/traits/introspection/member_function/has_imag.hpp>
#include <boost/concept/traits/query/is_math_complex_type.hpp>
#include <boost/concept/traits/introspection/nested_type/has_policy_type.hpp>
#include <boost/concept/traits/trivial_access/policy_type_of.hpp>
#include <boost/concept/traits/query/is_math_distribution.hpp>
#include <boost/concept/traits/introspection/nested_type/has_element_type.hpp>
#include <boost/concept/traits/trivial_access/element_type_of.hpp>
#include <boost/concept/traits/query/is_optional_pointee.hpp>
#include <boost/concept/traits/query/is_nullable_pointer.hpp>
#include <boost/concept/traits/query/is_iterator.hpp>
#include <boost/concept/traits/query/is_readable_iterator.hpp>
#include <boost/concept/traits/query/is_lvalue_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_iterator_category.hpp>
#include <boost/concept/traits/trivial_access/iterator_category_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_traversal_of.hpp>
#include <boost/concept/traits/query/is_incrementable_iterator.hpp>
#include <boost/concept/traits/query/is_single_pass_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_category_of.hpp>
#include <boost/concept/traits/query/is_input_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_difference_type.hpp>
#include <boost/concept/traits/trivial_access/difference_type_of.hpp>
#include <boost/concept/traits/query/is_forward_iterator.hpp>
#include <boost/concept/traits/query/is_bidirectional_iterator.hpp>
#include <boost/concept/traits/query/is_indexable_iterator.hpp>
#include <boost/concept/traits/query/is_random_access_iterator.hpp>
#include <boost/concept/traits/query/is_ptr_map_iterator.hpp>
#include <boost/concept/traits/introspection/nested_type/has_char_type.hpp>
#include <boost/concept/traits/trivial_access/char_type_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_container_type.hpp>
#include <boost/concept/traits/trivial_access/container_type_of.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/concept/traits/query/is_writable_iterator.hpp>
#include <boost/concept/traits/query/is_output_iterator.hpp>
#include <boost/concept/traits/trivial_access/iterator_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_iterator_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_begin.hpp>
#include <boost/concept/traits/introspection/member_function/has_end.hpp>
#include <boost/concept/traits/query/is_range.hpp>
#include <boost/concept/traits/introspection/nested_type/is_value_type_of.hpp>
#include <boost/concept/traits/query/is_std_integral_constant.hpp>
#include <boost/concept/traits/query/is_std_boolean_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/concept/traits/trivial_access/type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/has_tag.hpp>
#include <boost/concept/traits/trivial_access/tag_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_tag_of.hpp>
#include <boost/concept/traits/query/is_mpl_static_constant.hpp>
#include <boost/concept/traits/query/is_mpl_boolean_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/has_next.hpp>
#include <boost/concept/traits/trivial_access/next_to.hpp>
#include <boost/concept/traits/introspection/nested_type/has_prior.hpp>
#include <boost/concept/traits/trivial_access/prior_to.hpp>
#include <boost/concept/traits/query/is_mpl_integral_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/has_num_type.hpp>
#include <boost/concept/traits/trivial_access/num_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_num_type_of.hpp>
#include <boost/concept/traits/introspection/member_data/has_num.hpp>
#include <boost/concept/traits/introspection/nested_type/has_den_type.hpp>
#include <boost/concept/traits/trivial_access/den_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_den_type_of.hpp>
#include <boost/concept/traits/introspection/member_data/has_den.hpp>
#include <boost/concept/traits/query/is_rational_constant.hpp>
#include <boost/concept/traits/introspection/is_raw_pointer_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_allocate_clone.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_deallocate_clone.hpp>
#include <boost/concept/traits/query/is_clone_allocator.hpp>
#include <boost/concept/traits/introspection/nested_template/has_rebind.hpp>
#include <boost/concept/traits/introspection/nested_type/has_other.hpp>
#include <boost/concept/traits/trivial_access/other_of.hpp>
#include <boost/concept/traits/introspection/nested_type/has_void_pointer.hpp>
#include <boost/concept/traits/trivial_access/void_pointer_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_propagate_on_container.hpp>
#include <boost/concept/traits/trivial_access/propagate_on_container_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_is_always_equal.hpp>
#include <boost/concept/traits/trivial_access/is_always_equal_of.hpp>
#include <boost/concept/traits/introspection/nested_type/has_pointer.hpp>
#include <boost/concept/traits/introspection/member_function/has_allocate.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_deallocate.hpp>
#include <boost/concept/traits/query/is_allocator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_allocator_type.hpp>
#include <boost/concept/traits/trivial_access/allocator_type_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_get_allocator.hpp>
#include <boost/concept/traits/introspection/member_function/has_value.hpp>
#include <boost/concept/traits/query/is_simple_node_handle.hpp>
#include <boost/concept/traits/introspection/nested_type/has_key_type.hpp>
#include <boost/concept/traits/trivial_access/key_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_key.hpp>
#include <boost/concept/traits/introspection/nested_type/has_mapped_type.hpp>
#include <boost/concept/traits/trivial_access/mapped_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_mapped.hpp>
#include <boost/concept/traits/query/is_key_mapped_node_handle.hpp>
#include <boost/concept/traits/introspection/nested_type/has_iterator.hpp>
#include <boost/concept/traits/query/is_container.hpp>
#include <boost/concept/traits/introspection/member_function/has_cbegin.hpp>
#include <boost/concept/traits/introspection/member_function/has_cend.hpp>
#include <boost/concept/traits/query/is_cxx11_container.hpp>
#include <boost/concept/traits/introspection/nested_type/has_auto_type.hpp>
#include <boost/concept/traits/trivial_access/auto_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_base.hpp>
#include <boost/concept/traits/query/is_ptr_container.hpp>
#include <boost/concept/traits/introspection/member_function/has_clear.hpp>
#include <boost/concept/traits/introspection/member_function/has_empty.hpp>
#include <boost/concept/traits/introspection/member_function/has_find.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_equal_range.hpp>
#include <boost/concept/traits/introspection/member_function/has_erase.hpp>
#include <boost/concept/traits/introspection/nested_type/has_size_type.hpp>
#include <boost/concept/traits/trivial_access/size_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_size_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_max_size.hpp>
#include <boost/concept/traits/introspection/member_function/has_size.hpp>
#include <boost/concept/traits/introspection/member_function/has_count.hpp>
#include <boost/concept/traits/query/is_associative_container.hpp>
#include <boost/concept/traits/query/is_pair_assoc_container.hpp>
#include <boost/concept/traits/query/is_pair_assoc_ptr_container.hpp>
#include <boost/concept/traits/introspection/nested_type/has_hasher.hpp>
#include <boost/concept/traits/trivial_access/hasher_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_hash_function.hpp>
#include <boost/concept/traits/introspection/nested_type/has_key_equal.hpp>
#include <boost/concept/traits/trivial_access/key_equal_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_key_eq.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_bucket_count.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_max_bucket_count.hpp>
#include <boost/concept/traits/query/is_hashed_assoc_container.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_local_iterator.hpp>
#include <boost/concept/traits/trivial_access/local_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_local_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_begin_bucket.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_end_bucket.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_cbegin_bucket.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_cend_bucket.hpp>
#include <boost/concept/traits/introspection/member_function/has_rehash.hpp>
#include <boost/concept/traits/introspection/member_function/has_reserve.hpp>
#include <boost/concept/traits/query/is_unordered_assoc_container.hpp>
#include <boost/concept/traits/introspection/nested_type/has_key_compare.hpp>
#include <boost/concept/traits/trivial_access/key_compare_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_key_comp.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_value_compare.hpp>
#include <boost/concept/traits/trivial_access/value_compare_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_value_comp.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_lower_bound.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_upper_bound.hpp>
#include <boost/concept/traits/query/is_flat_assoc_container.hpp>
#include <boost/concept/traits/query/is_sorted_assoc_container.hpp>
#include <boost/concept/traits/trivial_access/iterator_bool_pair_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_bool_pair_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_insert.hpp>
#include <boost/concept/traits/query/is_unique_assoc_container.hpp>
#include <boost/concept/traits/query/is_u_sm_assoc_ptr_container.hpp>
#include <boost/concept/traits/query/is_u_pr_assoc_ptr_container.hpp>
#include <boost/concept/traits/query/is_multiple_assoc_container.hpp>
#include <boost/concept/traits/query/is_m_sm_assoc_ptr_container.hpp>
#include <boost/concept/traits/query/is_m_pr_assoc_ptr_container.hpp>
#include <boost/concept/traits/introspection/nested_type/has_node_type.hpp>
#include <boost/concept/traits/trivial_access/node_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_extract.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_reverse_iterator.hpp>
#include <boost/concept/traits/trivial_access/reverse_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_reverse_iterator_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_rbegin.hpp>
#include <boost/concept/traits/introspection/member_function/has_rend.hpp>
#include <boost/concept/traits/query/is_reversible.hpp>
#include <boost/concept/traits/query/is_reversible_container.hpp>
#include <boost/concept/traits/introspection/member_function/has_crbegin.hpp>
#include <boost/concept/traits/introspection/member_function/has_crend.hpp>
#include <boost/concept/traits/query/is_cxx11_reversible_container.hpp>
#include <boost/concept/traits/query/is_indexable_container.hpp>
#include <boost/concept/traits/query/is_random_access_container.hpp>
#include <boost/concept/traits/introspection/has_stable_iterators.hpp>
#include <boost/concept/traits/introspection/nested_type/has_index.hpp>
#include <boost/concept/traits/trivial_access/index_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_index_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_start.hpp>
#include <boost/concept/traits/introspection/member_function/has_finish.hpp>
#include <boost/concept/traits/introspection/member_function/has_stride.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_get_start.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_get_finish.hpp>
#include <boost/concept/traits/query/is_multi_array_index_range.hpp>
#include \
<boost/concept/traits/introspection/member_data/has_dimensionality_st_const.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_num_dimensions.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_num_elements.hpp>
#include <boost/concept/traits/introspection/member_function/has_shape.hpp>
#include <boost/concept/traits/introspection/member_function/has_strides.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_index_bases.hpp>
#include <boost/concept/traits/introspection/nested_type/has_element.hpp>
#include <boost/concept/traits/trivial_access/element_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_origin.hpp>
#include <boost/concept/traits/introspection/nested_type/has_index_gen.hpp>
#include <boost/concept/traits/trivial_access/index_gen_of.hpp>
#include <boost/concept/traits/introspection/nested_type/has_index_range.hpp>
#include <boost/concept/traits/trivial_access/index_range_of.hpp>
#include <boost/concept/traits/query/is_multi_array.hpp>
#include <boost/concept/traits/introspection/nested_type/has_left_map.hpp>
#include <boost/concept/traits/trivial_access/left_map_of.hpp>
#include <boost/concept/traits/introspection/member_data/has_left.hpp>
#include <boost/concept/traits/introspection/nested_type/has_right_map.hpp>
#include <boost/concept/traits/trivial_access/right_map_of.hpp>
#include <boost/concept/traits/introspection/member_data/has_right.hpp>
#include <boost/concept/traits/query/is_bimap.hpp>
#include <boost/concept/traits/trivial_access/pointer_of.hpp>
#include <boost/concept/traits/introspection/is_pointer_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_data.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_expression_type.hpp>
#include <boost/concept/traits/trivial_access/expression_type_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_expression_type_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_type_category.hpp>
#include <boost/concept/traits/trivial_access/type_category_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_type_category_of.hpp>
#include <boost/concept/traits/query/is_ublas_vector_expression.hpp>
#include <boost/concept/traits/introspection/member_function/has_swap.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_insert_element.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_erase_element.hpp>
#include <boost/concept/traits/introspection/member_function/has_resize.hpp>
#include <boost/concept/traits/query/is_ublas_vector.hpp>
#include \
<boost/concept/traits/introspection/member_data/has_max_size_static_const.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_insert_after.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_erase_after.hpp>
#include <boost/concept/traits/query/is_sequence.hpp>
#include <boost/concept/traits/introspection/member_function/has_back.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_push_back.hpp>
#include <boost/concept/traits/introspection/member_function/has_pop_back.hpp>
#include <boost/concept/traits/query/is_back_insertion_sequence.hpp>
#include <boost/concept/traits/introspection/member_function/has_front.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_push_front.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_pop_front.hpp>
#include <boost/concept/traits/query/is_front_insertion_sequence.hpp>
#include <boost/concept/traits/introspection/nested_type/has_array_range.hpp>
#include <boost/concept/traits/trivial_access/array_range_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_capacity_type.hpp>
#include <boost/concept/traits/trivial_access/capacity_type_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_capacity_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_capacity.hpp>
#include <boost/concept/traits/introspection/member_function/has_full.hpp>
#include <boost/concept/traits/query/is_circular_buffer.hpp>
#include <boost/concept/traits/introspection/member_function/has_push.hpp>
#include <boost/concept/traits/introspection/member_function/has_pop.hpp>
#include <boost/concept/traits/query/is_queue.hpp>
#include <boost/concept/traits/introspection/member_function/has_top.hpp>
#include <boost/concept/traits/query/is_stack_or_std_heap.hpp>
#include <boost/concept/traits/query/is_heap.hpp>
#include <boost/concept/traits/query/is_iteratable_heap.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_ordered_iterator.hpp>
#include <boost/concept/traits/trivial_access/ordered_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_ordered_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_ordered_begin.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_ordered_end.hpp>
#include <boost/concept/traits/query/is_order_iteratable_heap.hpp>
#include <boost/concept/traits/introspection/member_function/has_merge.hpp>
#include <boost/concept/traits/query/is_mergeable_heap.hpp>
#include <boost/concept/traits/introspection/nested_type/has_handle_type.hpp>
#include <boost/concept/traits/trivial_access/handle_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_update.hpp>
#include <boost/concept/traits/introspection/member_function/has_increase.hpp>
#include <boost/concept/traits/introspection/member_function/has_decrease.hpp>
#include <boost/concept/traits/query/is_mutable_heap.hpp>
#include <boost/concept/traits/introspection/member_function/has_size1.hpp>
#include <boost/concept/traits/introspection/member_function/has_size2.hpp>
#include <boost/concept/traits/introspection/nested_type/has_iterator1.hpp>
#include <boost/concept/traits/trivial_access/iterator1_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_iterator1_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_begin1.hpp>
#include <boost/concept/traits/introspection/member_function/has_end1.hpp>
#include <boost/concept/traits/introspection/nested_type/has_iterator2.hpp>
#include <boost/concept/traits/trivial_access/iterator2_of.hpp>
#include <boost/concept/traits/introspection/nested_type/is_iterator2_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_begin2.hpp>
#include <boost/concept/traits/introspection/member_function/has_end2.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_reverse_iterator1.hpp>
#include <boost/concept/traits/trivial_access/reverse_iterator1_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_reverse_iterator1_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_rbegin1.hpp>
#include <boost/concept/traits/introspection/member_function/has_rend1.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_reverse_iterator2.hpp>
#include <boost/concept/traits/trivial_access/reverse_iterator2_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_reverse_iterator2_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_rbegin2.hpp>
#include <boost/concept/traits/introspection/member_function/has_rend2.hpp>
#include <boost/concept/traits/query/is_ublas_matrix_expression.hpp>
#include <boost/concept/traits/query/is_ublas_matrix.hpp>
#include <boost/concept/traits/introspection/member_function/has_emplace.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_emplace_front.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_emplace_back.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_emplace_after.hpp>
#include <boost/concept/traits/query/is_fusion_fwd_iterator.hpp>
#include <boost/concept/traits/query/is_fusion_bidir_iterator.hpp>
#include <boost/concept/traits/query/is_fusion_ra_iterator.hpp>
#include <boost/concept/traits/query/is_fusion_assoc_iterator.hpp>
#include <boost/concept/traits/introspection/nested_type/has_is_view.hpp>
#include <boost/concept/traits/query/is_fusion_fwd_sequence.hpp>
#include <boost/concept/traits/query/is_fusion_bidir_sequence.hpp>
#include <boost/concept/traits/query/is_fusion_ra_sequence.hpp>
#include <boost/concept/traits/query/is_fusion_assoc_sequence.hpp>
#include <boost/concept/traits/introspection/nested_type/has_category.hpp>
#include <boost/concept/traits/trivial_access/category_of.hpp>
#include <boost/concept/traits/query/is_mpl_forward_iterator.hpp>
#include <boost/concept/traits/query/is_mpl_bidir_iterator.hpp>
#include <boost/concept/traits/query/is_mpl_ra_iterator.hpp>
#include <boost/concept/traits/query/is_mpl_sequence.hpp>
#include <boost/concept/traits/query/is_mpl_assoc_sequence.hpp>
#include <boost/concept/traits/query/is_mpl_extensible_sequence.hpp>
#include <boost/concept/traits/query/is_mpl_front_ext_sequence.hpp>
#include <boost/concept/traits/query/is_mpl_back_ext_sequence.hpp>
#include <boost/concept/traits/query/is_readable_property_map.hpp>
#include <boost/concept/traits/query/is_writable_property_map.hpp>
#include <boost/concept/traits/query/is_read_write_property_map.hpp>
#include <boost/concept/traits/query/is_lvalue_property_map.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_vertex_descriptor.hpp>
#include <boost/concept/traits/trivial_access/vertex_descriptor_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_vertex_descriptor_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_descriptor.hpp>
#include <boost/concept/traits/trivial_access/edge_descriptor_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_edge_descriptor_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_directed_category.hpp>
#include <boost/concept/traits/trivial_access/directed_category_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_parallel_category.hpp>
#include <boost/concept/traits/trivial_access/edge_parallel_category_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_traversal_category.hpp>
#include <boost/concept/traits/trivial_access/traversal_category_of.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_null_vertex.hpp>
#include <boost/concept/traits/query/is_graph.hpp>
#include <boost/concept/traits/query/is_vertex_mutable_graph.hpp>
#include <boost/concept/traits/query/is_edge_mutable_graph.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_vertex_iterator.hpp>
#include <boost/concept/traits/trivial_access/vertex_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_vertices_size_type.hpp>
#include <boost/concept/traits/trivial_access/vertices_size_type_of.hpp>
#include <boost/concept/traits/query/is_vertex_list_graph.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_iterator.hpp>
#include <boost/concept/traits/trivial_access/edge_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edges_size_type.hpp>
#include <boost/concept/traits/trivial_access/edges_size_type_of.hpp>
#include <boost/concept/traits/introspection/free_function/has_source.hpp>
#include <boost/concept/traits/introspection/free_function/has_target.hpp>
#include <boost/concept/traits/query/is_edge_list_graph.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_out_edge_iterator.hpp>
#include <boost/concept/traits/trivial_access/out_edge_iterator_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_degree_size_type.hpp>
#include <boost/concept/traits/trivial_access/degree_size_type_of.hpp>
#include <boost/concept/traits/query/is_incidence_graph.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_adjacency_iterator.hpp>
#include <boost/concept/traits/trivial_access/adjacency_iterator_of.hpp>
#include <boost/concept/traits/query/is_adjacency_graph.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_in_edge_iterator.hpp>
#include <boost/concept/traits/trivial_access/in_edge_iterator_of.hpp>
#include <boost/concept/traits/query/is_bidirectional_graph.hpp>
#include <boost/concept/traits/introspection/nested_type/has_const_type.hpp>
#include <boost/concept/traits/trivial_access/const_type_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_vertex_property_type.hpp>
#include <boost/concept/traits/trivial_access/vertex_property_type_of.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_edge_property_type.hpp>
#include <boost/concept/traits/trivial_access/edge_property_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/has_event_filter.hpp>
#include <boost/concept/traits/trivial_access/event_filter_of.hpp>
#include <boost/concept/traits/introspection/nested_template/has_apply.hpp>
#include <boost/concept/traits/query/is_unary_metafunc_class.hpp>
#include <boost/concept/traits/query/is_binary_metafunc_class.hpp>

#endif  // include guard

