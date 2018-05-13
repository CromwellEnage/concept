// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_half_runtime_pair.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/support/pair.hpp>
#include <boost/tuple/tuple.hpp>
#include <utility>

//[test__is_half_runtime_pair__pairs
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_half_runtime_pair<
            std::pair<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_half_runtime_pair<
            std::pair<int&,int const&> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_half_runtime_pair<
            boost::tuples::tuple<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_half_runtime_pair<
            boost::tuples::tuple<int&,int const&> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_half_runtime_pair<
            boost::fusion::pair<int,int const>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_half_runtime_pair<
            boost::fusion::pair<int,int const> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_half_runtime_pair<
            boost::fusion::pair<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_half_runtime_pair<
            boost::fusion::pair<int&,int const&> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_half_runtime_pair<
            boost::fusion::vector<int&,int const&>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_half_runtime_pair<
            boost::fusion::vector<int&,int const&> const
        >
    ));
}
//]

