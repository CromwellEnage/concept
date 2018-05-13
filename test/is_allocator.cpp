// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_allocator.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/container/allocator.hpp>
#include <boost/container/node_allocator.hpp>
#include <boost/container/adaptive_pool.hpp>
#include <boost/container/scoped_allocator.hpp>
#include <boost/ptr_container/clone_allocator.hpp>
#include <boost/concept/archetype/clone_allocator.hpp>
#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_ALLOCATOR
#include <memory>
#endif

//[test__is_allocator
MPL_TEST_CASE()
{
//<-
#if !defined BOOST_NO_CXX11_ALLOCATOR
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_allocator<std::allocator<int> >
    ));
//<-
#endif
//->
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_allocator<
            boost::container::allocator<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_allocator<
            boost::container::node_allocator<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_allocator<
            boost::container::adaptive_pool<int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_allocator<
            boost::container::scoped_allocator_adaptor<
                boost::container::allocator<int>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_allocator<
            boost::concept::clone_allocator_archetype
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_allocator<boost::heap_clone_allocator>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_allocator<boost::view_clone_allocator>
    ));
}
//]

