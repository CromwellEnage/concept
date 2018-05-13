// Copyright (C) 2016-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_simple_node_handle.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/container/set.hpp>
#include <boost/container/map.hpp>

//[test__is_simple_node_handle__boost_container_node_type
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            boost::container::set<int>::node_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            boost::container::multiset<int>::node_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            boost::container::map<int,int>::node_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            boost::container::multimap<int,int>::node_type
        >
    ));
}
//]

#if 0
#include <set>
#include <map>

//[test__is_simple_node_handle__std_container_node_type
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            std::set<int>::node_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            std::multiset<int>::node_type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_simple_node_handle<
            std::map<int,int>::node_type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_simple_node_handle<
            std::multimap<int,int>::node_type
        >
    ));
}
//]

#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET
#include <unordered_set>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            std::unordered_set<int>::node_type
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_simple_node_handle<
            std::unordered_multiset<int>::node_type
        >
    ));
}
#endif

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP
#include <unordered_map>

MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_simple_node_handle<
            std::unordered_map<int,int>::node_type
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_simple_node_handle<
            std::unordered_multimap<int,int>::node_type
        >
    ));
}
#endif
#endif

