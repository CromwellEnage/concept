// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_FWD_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_FWD_HPP

//[reference__c_str_equal_to_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct c_str_equal_to_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__c_str_less_than_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct c_str_less_than_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__c_str_greater_than_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct c_str_greater_than_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__equal_to_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct equal_to_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__less_than_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct less_than_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__greater_than_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct greater_than_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__equivalence_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename Selector = ::boost::concept::policy::less_than_selector
    >
    struct equivalence_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__unary_predicate_negation_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <typename Selector>
    struct unary_predicate_negation_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__binary_predicate_negation_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <typename Selector>
    struct binary_predicate_negation_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_hash_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct boost_hash_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_allocator_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct std_allocator_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__new_allocator_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct new_allocator_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__polymorphic_allocator_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct polymorphic_allocator_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__circular_buffer_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::std_allocator_selector
    >
    struct circular_buffer_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__circular_buffer_space_optimized_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::std_allocator_selector
    >
    struct circular_buffer_space_optimized_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_array_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <typename ConstantSize>
    struct boost_array_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_vector_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::std_allocator_selector
    >
    struct std_vector_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_vector_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::new_allocator_selector
    >
    struct boost_vector_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__stable_vector_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::new_allocator_selector
    >
    struct stable_vector_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__small_vector_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::new_allocator_selector
    >
    struct small_vector_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_deque_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::std_allocator_selector
    >
    struct std_deque_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_deque_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::new_allocator_selector
    >
    struct boost_deque_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_slist_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::new_allocator_selector
    >
    struct boost_slist_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_list_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::std_allocator_selector
    >
    struct std_list_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_list_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::new_allocator_selector
    >
    struct boost_list_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_stack_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename SequenceSelector =
        ::boost::concept::policy::std_vector_selector<>
    >
    struct std_stack_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_queue_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename SequenceSelector =
        ::boost::concept::policy::std_deque_selector<>
    >
    struct std_queue_selector;
}}}  // namespace boost::concept::policy
//]

#include <boost/mpl/integral_c_fwd.hpp>

//[reference__boost_allocator_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename Version = ::boost::mpl::integral_c<unsigned,2>
      , typename AllocationDisableMask = ::boost::mpl::integral_c<unsigned int,0>
    >
    struct boost_allocator_selector;
}}}  // namespace boost::concept::policy
//]

#include <boost/mpl/size_t_fwd.hpp>

//[reference__node_allocator_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename NodesPerBlock = ::boost::mpl::size_t<256u>
      , typename Version = ::boost::mpl::size_t<2>
    >
    struct node_allocator_selector;
}}}  // namespace boost::concept::policy
//]

#include <boost/parameter/aux_/void.hpp>

//[reference__ptr_array_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
    >
    struct ptr_array_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_vector_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
    >
    struct ptr_vector_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_deque_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
    >
    struct ptr_deque_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_circular_buffer_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
    >
    struct ptr_circular_buffer_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_list_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
    >
    struct ptr_list_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_set_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct std_set_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_map_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct std_map_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ordered_associative_std_container_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct ordered_associative_std_container_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_set_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct boost_set_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_map_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct boost_map_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ordered_associative_boost_container_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct ordered_associative_boost_container_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__flat_set_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct flat_set_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__flat_map_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct flat_map_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__flat_associative_container_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
    >
    struct flat_associative_container_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_set_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct ptr_set_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_map_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct ptr_map_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ordered_associative_ptr_container_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct ordered_associative_ptr_container_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_unordered_set_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct boost_unordered_set_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_unordered_map_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct boost_unordered_map_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__unordered_associative_boost_container_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct unordered_associative_boost_container_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_unordered_set_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
      , typename P4 = ::boost::parameter::void_
    >
    struct ptr_unordered_set_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_unordered_map_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
      , typename P4 = ::boost::parameter::void_
    >
    struct ptr_unordered_map_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__unordered_associative_ptr_container_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
      , typename P4 = ::boost::parameter::void_
    >
    struct unordered_associative_ptr_container_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__std_priority_queue_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
    >
    struct std_priority_queue_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__boost_priority_queue_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct boost_priority_queue_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__d_ary_heap_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
      , typename P4 = ::boost::parameter::void_
      , typename P5 = ::boost::parameter::void_
    >
    struct d_ary_heap_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__binomial_heap_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct binomial_heap_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__fibonacci_heap_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
      , typename P4 = ::boost::parameter::void_
    >
    struct fibonacci_heap_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__pairing_heap_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
      , typename P4 = ::boost::parameter::void_
    >
    struct pairing_heap_selector;
}}}  // namespace boost::concept::policy
//]

//[reference__skew_heap_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
      , typename P4 = ::boost::parameter::void_
      , typename P5 = ::boost::parameter::void_
      , typename P6 = ::boost::parameter::void_
    >
    struct skew_heap_selector;
}}}  // namespace boost::concept::policy
//]

#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL

//[reference__std_hash_selector__fwd
namespace boost { namespace concept { namespace policy {

    struct std_hash_selector;
}}}  // namespace boost::concept::policy
//]

#endif

#if !defined BOOST_NO_CXX11_HDR_ARRAY

//[reference__std_array_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <typename ConstantSize>
    struct std_array_selector;
}}}  // namespace boost::concept::policy
//]

#endif

#if !defined BOOST_NO_CXX11_HDR_FORWARD_LIST

//[reference__std_forward_list_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename AllocatorSelector =
        ::boost::concept::policy::std_allocator_selector
    >
    struct std_forward_list_selector;
}}}  // namespace boost::concept::policy
//]

#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET

//[reference__std_unordered_set_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct std_unordered_set_selector;
}}}  // namespace boost::concept::policy
//]

#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

//[reference__std_unordered_map_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct std_unordered_map_selector;
}}}  // namespace boost::concept::policy
//]

#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET && \
    !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

//[reference__unordered_associative_std_container_selector__fwd
namespace boost { namespace concept { namespace policy {

    template <
        typename P0 = ::boost::parameter::void_
      , typename P1 = ::boost::parameter::void_
      , typename P2 = ::boost::parameter::void_
      , typename P3 = ::boost::parameter::void_
    >
    struct unordered_associative_std_container_selector;
}}}  // namespace boost::concept::policy
//]

#endif

#endif  // include guard

