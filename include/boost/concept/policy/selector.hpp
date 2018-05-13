// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_HPP

#include <boost/concept/policy/selector/c_str_equal_to.hpp>
#include <boost/concept/policy/selector/c_str_less_than.hpp>
#include <boost/concept/policy/selector/c_str_greater_than.hpp>
#include <boost/concept/policy/selector/equal_to.hpp>
#include <boost/concept/policy/selector/less_than.hpp>
#include <boost/concept/policy/selector/greater_than.hpp>
#include <boost/concept/policy/selector/equivalence.hpp>
#include <boost/concept/policy/selector/unary_predicate_negation.hpp>
#include <boost/concept/policy/selector/binary_predicate_negation.hpp>
#include <boost/concept/policy/selector/std_hash.hpp>
#include <boost/concept/policy/selector/boost_hash.hpp>
#include <boost/concept/policy/selector/std_allocator.hpp>
#include <boost/concept/policy/selector/new_allocator.hpp>
#include <boost/concept/policy/selector/polymorphic_allocator.hpp>
#include <boost/concept/policy/selector/boost_allocator.hpp>
#include <boost/concept/policy/selector/std_vector.hpp>
#include <boost/concept/policy/selector/std_deque.hpp>
#include <boost/concept/policy/selector/std_forward_list.hpp>
#include <boost/concept/policy/selector/std_list.hpp>
#include <boost/concept/policy/selector/boost_vector.hpp>
#include <boost/concept/policy/selector/boost_deque.hpp>
#include <boost/concept/policy/selector/boost_slist.hpp>
#include <boost/concept/policy/selector/boost_list.hpp>
#include <boost/concept/policy/selector/circular_buffer.hpp>
#include <boost/concept/policy/selector/circular_buffer_space_opt.hpp>
#include <boost/concept/policy/selector/std_set.hpp>
#include <boost/concept/policy/selector/std_map.hpp>
#include <boost/concept/policy/selector/order_assoc_std_container.hpp>
#include <boost/concept/policy/selector/boost_set.hpp>
#include <boost/concept/policy/selector/boost_map.hpp>
#include <boost/concept/policy/selector/order_assoc_boost_container.hpp>
#include <boost/concept/policy/selector/flat_set.hpp>
#include <boost/concept/policy/selector/flat_map.hpp>
#include <boost/concept/policy/selector/flat_associative_container.hpp>
#include <boost/concept/policy/selector/std_unordered_set.hpp>
#include <boost/concept/policy/selector/std_unordered_map.hpp>
#include <boost/concept/policy/selector/unord_assoc_std_container.hpp>
#include <boost/concept/policy/selector/boost_unordered_set.hpp>
#include <boost/concept/policy/selector/boost_unordered_map.hpp>
#include <boost/concept/policy/selector/unord_assoc_boost_container.hpp>
#include <boost/concept/policy/selector/ptr_vector.hpp>
#include <boost/concept/policy/selector/ptr_deque.hpp>
#include <boost/concept/policy/selector/ptr_list.hpp>
#include <boost/concept/policy/selector/ptr_circular_buffer.hpp>
#include <boost/concept/policy/selector/ptr_set.hpp>
#include <boost/concept/policy/selector/ptr_map.hpp>
#include <boost/concept/policy/selector/order_assoc_ptr_container.hpp>
#include <boost/concept/policy/selector/ptr_unordered_set.hpp>
#include <boost/concept/policy/selector/ptr_unordered_map.hpp>
#include <boost/concept/policy/selector/unord_assoc_ptr_container.hpp>
#include <boost/concept/policy/selector/std_stack.hpp>
#include <boost/concept/policy/selector/std_queue.hpp>
#include <boost/concept/policy/selector/std_priority_queue.hpp>
#include <boost/concept/policy/selector/boost_priority_queue.hpp>
#include <boost/concept/policy/selector/d_ary_heap.hpp>
#include <boost/concept/policy/selector/binomial_heap.hpp>
#include <boost/concept/policy/selector/fibonacci_heap.hpp>
#include <boost/concept/policy/selector/pairing_heap.hpp>
#include <boost/concept/policy/selector/skew_heap.hpp>
#include <boost/config.hpp>

#if !defined BOOST_MSVC
#include <boost/concept/policy/selector/std_array.hpp>
#include <boost/concept/policy/selector/boost_array.hpp>
#include <boost/concept/policy/selector/ptr_array.hpp>
#endif

#endif  // include guard

