// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/archetype/mutable_indexable_iterator.hpp>
#include <boost/concept/traits/query/is_iterator.hpp>
#include <boost/concept/traits/query/is_readable_iterator.hpp>
#include <boost/concept/traits/query/is_lvalue_iterator.hpp>
#include <boost/concept/traits/query/is_single_pass_iterator.hpp>
#include <boost/concept/traits/query/is_incrementable_iterator.hpp>
#include <boost/concept/traits/query/is_input_iterator.hpp>
#include <boost/concept/traits/query/is_forward_iterator.hpp>
#include <boost/concept/traits/query/is_bidirectional_iterator.hpp>
#include <boost/concept/traits/query/is_indexable_iterator.hpp>
#include <boost/concept/traits/query/is_random_access_iterator.hpp>
#include <boost/concept/traits/query/is_writable_iterator.hpp>
#include <boost/concept/traits/query/is_output_iterator.hpp>
#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include <boost/concept/traits/query/is_less_than_comparable.hpp>
#include <boost/concept/traits/query/is_comparable.hpp>
#include <boost/concept/traits/query/is_callable.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

//[test__mutable_indexable_iterator_archetype
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_readable_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_lvalue_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_single_pass_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_incrementable_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_input_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_forward_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_bidirectional_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_indexable_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_random_access_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_writable_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_output_iterator<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_equality_comparable<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_less_than_comparable<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_comparable<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::concept::mutable_indexable_iterator_archetype<char>
        >
    ));
}
//]

