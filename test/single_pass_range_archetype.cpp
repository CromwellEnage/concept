// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/archetype/single_pass_range.hpp>
#include <boost/concept/traits/query/is_range.hpp>
#include <boost/concept/traits/query/is_forward_iterator.hpp>
#include <boost/concept/traits/query/is_bidirectional_iterator.hpp>
#include <boost/concept/traits/query/is_random_access_iterator.hpp>
#include <boost/concept/traits/query/is_container.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>
#include <boost/mpl/placeholders.hpp>

//[test__single_pass_range_archetype
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_range<
            boost::concept::single_pass_range_archetype<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::concept::single_pass_range_archetype<int>
          , boost::concept::traits::is_forward_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::concept::single_pass_range_archetype<int>
          , boost::concept::traits::is_bidirectional_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_range<
            boost::concept::single_pass_range_archetype<int>
          , boost::concept::traits::is_random_access_iterator<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_container<
            boost::concept::single_pass_range_archetype<int>
        >
    ));
}
//]

