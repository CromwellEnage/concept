// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/traits/query/is_read_write_property_map.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/property_map/property_map.hpp>
#include <boost/property_map/function_property_map.hpp>
#include <boost/property_map/shared_array_property_map.hpp>
#include <boost/property_map/vector_property_map.hpp>
#include <boost/property_map/transform_value_property_map.hpp>
#include <boost/property_map/compose_property_map.hpp>

#include <boost/function.hpp>
#include <deque>
#include <map>

//[test__is_read_write_property_map
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<double*>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<double* const>
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<int const*>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<int const* const>
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::typed_identity_property_map<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::typed_identity_property_map<int> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::function_property_map<
                boost::function1<double,double>
              , double
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::function_property_map<
                boost::function1<double,double>
              , double
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::function_property_map<
                boost::function1<std::deque<int>&,int const&>
              , int
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::function_property_map<
                boost::function1<std::deque<int>&,int const&>
              , int
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::iterator_property_map<
                std::deque<int>::iterator
              , boost::typed_identity_property_map<int>
              , int
              , int&
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::iterator_property_map<
                std::deque<int>::iterator
              , boost::typed_identity_property_map<int>
              , int
              , int&
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::shared_array_property_map<
                std::size_t
              , boost::typed_identity_property_map<std::size_t>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::shared_array_property_map<
                std::size_t
              , boost::typed_identity_property_map<std::size_t>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::associative_property_map<std::map<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::associative_property_map<std::map<int,int> > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::const_associative_property_map<std::map<int,int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::const_associative_property_map<std::map<int,int> > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::vector_property_map<std::deque<int> >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::vector_property_map<std::deque<int> > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::ref_property_map<std::deque<int>,int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::ref_property_map<std::deque<int>,int> const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::ref_property_map<std::deque<int>,int const>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::ref_property_map<std::deque<int>,int const> const
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::static_property_map<std::size_t>
          , char
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::static_property_map<std::size_t> const
          , char
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::transform_value_property_map<
                boost::function1<std::deque<int>&,std::size_t>
              , boost::typed_identity_property_map<std::size_t>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::transform_value_property_map<
                boost::function1<std::deque<int>&,std::size_t>
              , boost::typed_identity_property_map<std::size_t>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::transform_value_property_map<
                boost::function1<std::deque<int> const&,std::size_t>
              , boost::typed_identity_property_map<std::size_t>
            >
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::transform_value_property_map<
                boost::function1<std::deque<int> const&,std::size_t>
              , boost::typed_identity_property_map<std::size_t>
            > const
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_read_write_property_map<
            boost::compose_property_map<double*,int const*>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_read_write_property_map<
            boost::compose_property_map<double*,int const*> const
        >
    ));
}
//]

