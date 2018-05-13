// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Include all necessary Boost.Heap header files
// before including any header file that uses Boost.MPL
// to avoid ambiguity errors between size_t and boost::mpl::size_t.
#include <boost/heap/priority_queue.hpp>
#include <boost/heap/binomial_heap.hpp>
#include <boost/heap/d_ary_heap.hpp>
#include <boost/heap/fibonacci_heap.hpp>
#include <boost/heap/pairing_heap.hpp>
#include <boost/heap/skew_heap.hpp>

#include <boost/concept/traits/query/is_mutable_heap.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__is_mutable_heap__boost_heaps
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::priority_queue<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::priority_queue<int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::binomial_heap<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::binomial_heap<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::d_ary_heap<int,boost::heap::arity<1> > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            >
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::d_ary_heap<
                int
              , boost::heap::mutable_<true>
              , boost::heap::arity<1>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::fibonacci_heap<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::fibonacci_heap<int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::pairing_heap<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::pairing_heap<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::skew_heap<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_mutable_heap<
            boost::heap::skew_heap<int> const
        >
    ));
}
//]

