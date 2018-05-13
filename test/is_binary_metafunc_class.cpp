// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/policy/selector.hpp>
#include <boost/concept/traits/query/is_binary_metafunc_class.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

namespace test {

    struct minimal
    {
        template <typename T1, typename T2>
        struct apply
        {
            typedef char type;
        };
    };

    struct failure0
    {
        template <typename T>
        struct apply
        {
            typedef char type;
        };
    };

    struct failure1
    {
        template <typename T1, typename T2>
        struct apply
        {
        };
    };
}  // namespace test

//[test__is_binary_metafunction_class__minimal
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            test::minimal
          , char
          , char
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            test::failure0
          , char
          , char
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            test::failure1
          , char
          , char
        >
    ));
}
//]

#include <boost/mpl/bool.hpp>
#include <boost/mpl/always.hpp>

//[test__is_binary_metafunction_class__mpl
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::mpl::true_
          , bool
          , bool
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::mpl::true_
          , bool
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::mpl::always<boost::mpl::true_>
          , bool
          , bool
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::mpl::always<boost::mpl::false_>
          , bool
          , bool
        >
    ));
}
//]

#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/concept/traits/query/is_adaptable_unary_func.hpp>
#include <boost/concept/traits/query/is_adaptable_binary_func.hpp>
#include <boost/concept/traits/query/is_allocator.hpp>
#include <boost/concept/traits/query/is_forward_iterator.hpp>
#include <boost/concept/traits/query/is_range.hpp>
#include <boost/concept/traits/query/is_reversible_container.hpp>
#include <boost/concept/traits/query/is_random_access_container.hpp>
#include <boost/concept/traits/query/is_circular_buffer.hpp>
#include <boost/concept/traits/query/is_pair_assoc_container.hpp>
#include <boost/concept/traits/query/is_hashed_assoc_container.hpp>
#include <boost/concept/traits/query/is_sorted_assoc_container.hpp>
#include <boost/concept/traits/query/is_unique_assoc_container.hpp>
#include <boost/concept/traits/query/is_multiple_assoc_container.hpp>
#include <boost/concept/traits/query/is_u_sm_assoc_ptr_container.hpp>
#include <boost/concept/traits/query/is_u_pr_assoc_ptr_container.hpp>
#include <boost/concept/traits/query/is_m_sm_assoc_ptr_container.hpp>
#include <boost/concept/traits/query/is_m_pr_assoc_ptr_container.hpp>
#include <boost/concept/traits/query/is_queue.hpp>
#include <boost/concept/traits/query/is_stack_or_std_heap.hpp>
#include <boost/concept/traits/query/is_heap.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/quote.hpp>

//[test__is_binary_metafunction_class__concept__policy__selector
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::equal_to_selector
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::less_than_selector
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::greater_than_selector
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::equivalence_selector<>
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::binary_predicate_negation_selector<
                boost::concept::policy::equal_to_selector
            >
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::binary_predicate_negation_selector<
                boost::concept::policy::less_than_selector
            >
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::binary_predicate_negation_selector<
                boost::concept::policy::greater_than_selector
            >
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::binary_predicate_negation_selector<
                boost::concept::policy::equivalence_selector<>
            >
          , int
          , int
          , boost::concept::traits::is_adaptable_binary_function<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_boolean_expression
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_hash_selector
          , int
          , int
          , boost::concept::traits::is_adaptable_unary_function<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_allocator_selector
          , int
          , int
          , boost::concept::traits::is_allocator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::new_allocator_selector
          , int
          , int
          , boost::concept::traits::is_allocator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::polymorphic_allocator_selector
          , int
          , int
          , boost::concept::traits::is_allocator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_allocator_selector<>
          , int
          , int
          , boost::concept::traits::is_allocator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_vector_selector<>
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_deque_selector<>
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_list_selector<>
          , int
          , int
          , boost::concept::traits::is_reversible_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_vector_selector<>
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_deque_selector<>
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_slist_selector<>
          , int
          , int
          , boost::concept::traits::is_reversible_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_slist_selector<>
          , int
          , int
          , boost::concept::traits::is_range<
                boost::mpl::_
              , boost::mpl::quote1<
                    boost::concept::traits::is_forward_iterator
                >
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_list_selector<>
          , int
          , int
          , boost::concept::traits::is_reversible_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::circular_buffer_selector<>
          , int
          , int
          , boost::concept::traits::is_circular_buffer<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::circular_buffer_space_optimized_selector<>
          , int
          , int
          , boost::concept::traits::is_circular_buffer<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::ptr_vector_selector<>
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::ptr_deque_selector<>
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::ptr_list_selector<>
          , int
          , int
          , boost::concept::traits::is_reversible_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::ptr_circular_buffer_selector<>
          , int
          , int
          , boost::concept::traits::is_circular_buffer<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_std_container_selector<>
          , int
          , int
          , boost::concept::traits::is_multiple_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_std_container_selector<>
          , int
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_std_container_selector<>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_std_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_unique_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_std_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_std_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_boost_container_selector<>
          , int
          , int
          , boost::concept::traits::is_multiple_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_boost_container_selector<>
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_boost_container_selector<>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_boost_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_unique_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_boost_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_boost_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::flat_associative_container_selector<>
          , int
          , int
          , boost::concept::traits::is_multiple_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::flat_associative_container_selector<>
          , int
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::flat_associative_container_selector<>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::flat_associative_container_selector<
                boost::mpl::true_
            >
          , int
          , int
          , boost::concept::traits::is_unique_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::flat_associative_container_selector<
                boost::mpl::true_
            >
          , int
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::flat_associative_container_selector<
                boost::mpl::true_
            >
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_boost_container_selector<>
          , int
          , int
          , boost::concept::traits::is_multiple_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_boost_container_selector<>
          , int
          , int
          , boost::concept::traits::is_hashed_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_boost_container_selector<>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_boost_container_selector<
                boost::mpl::true_
            >
          , int
          , int
          , boost::concept::traits::is_unique_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_boost_container_selector<
                boost::mpl::true_
            >
          , int
          , int
          , boost::concept::traits::is_hashed_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_boost_container_selector<
                boost::mpl::true_
            >
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_ptr_container_selector<>
          , int
          , int
          , boost::concept::traits
            ::is_multiple_simple_associative_ptr_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_ptr_container_selector<>
          , int
          , int
          , boost::concept::traits
            ::is_multiple_pair_associative_ptr_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_ptr_container_selector<>
          , int
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_ptr_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits
            ::is_unique_simple_associative_ptr_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_ptr_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_unique_pair_associative_ptr_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::ordered_associative_ptr_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_sorted_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_ptr_container_selector<>
          , int
          , int
          , boost::concept::traits
            ::is_multiple_simple_associative_ptr_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_ptr_container_selector<>
          , int
          , int
          , boost::concept::traits
            ::is_multiple_pair_associative_ptr_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_ptr_container_selector<>
          , int
          , int
          , boost::concept::traits::is_hashed_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_ptr_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits
            ::is_unique_simple_associative_ptr_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_ptr_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_unique_pair_associative_ptr_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_ptr_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_hashed_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_queue_selector<>
          , int
          , int
          , boost::concept::traits::is_queue<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_stack_selector<>
          , int
          , int
          , boost::concept::traits::is_stack_or_std_heap<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_priority_queue_selector<>
          , int
          , int
          , boost::concept::traits::is_stack_or_std_heap<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_priority_queue_selector<>
          , int
          , int
          , boost::concept::traits::is_heap<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::d_ary_heap_selector<
                boost::heap::arity<1>
            >
          , int
          , int
          , boost::concept::traits::is_heap<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::binomial_heap_selector<>
          , int
          , int
          , boost::concept::traits::is_heap<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::fibonacci_heap_selector<>
          , int
          , int
          , boost::concept::traits::is_heap<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::pairing_heap_selector<>
          , int
          , int
          , boost::concept::traits::is_heap<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::skew_heap_selector<>
          , int
          , int
          , boost::concept::traits::is_heap<boost::mpl::_>
        >
    ));
}
//]

#include <boost/config.hpp>

#if !defined BOOST_MSVC

#include <boost/mpl/int.hpp>

MPL_TEST_CASE()
{
#if !defined BOOST_NO_CXX11_HDR_ARRAY
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_array_selector<boost::mpl::int_<1> >
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
#endif
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::boost_array_selector<boost::mpl::int_<1> >
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::ptr_array_selector<boost::mpl::int_<1> >
          , int
          , int
          , boost::concept::traits::is_random_access_container<boost::mpl::_>
        >
    ));
}

#endif  // BOOST_MSVC

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy::std_hash_selector
          , int
          , int
          , boost::concept::traits::is_adaptable_unary_function<
                boost::mpl::_
            >
        >
    ));
}

#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET && \
    !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_std_container_selector<>
          , int
          , int
          , boost::concept::traits::is_multiple_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_std_container_selector<>
          , int
          , int
          , boost::concept::traits::is_hashed_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_std_container_selector<>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_std_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_unique_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_std_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_hashed_associative_container<
                boost::mpl::_
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_binary_metafunction_class<
            boost::concept::policy
            ::unordered_associative_std_container_selector<boost::mpl::true_>
          , int
          , int
          , boost::concept::traits::is_pair_associative_container<
                boost::mpl::_
            >
        >
    ));
}

#endif  // BOOST_NO_CXX11_HDR_UNORDERED_SET, BOOST_NO_CXX11_HDR_UNORDERED_MAP

