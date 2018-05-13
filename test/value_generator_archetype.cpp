// Copyright (C) 2014-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/archetype/value_generator.hpp>
#include <boost/concept/traits/query/is_value_generator.hpp>
#include <boost/concept/traits/query/is_value_distribution.hpp>
#include <boost/concept/traits/query/is_value_distribution_w_prm.hpp>
#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include <boost/concept/traits/query/is_callable.hpp>
#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/utility/cxx14_result_of.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/test.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__value_generator_archetype
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_generator<
            boost::concept::value_generator_archetype<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution<
            boost::concept::value_generator_archetype<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::concept::value_generator_archetype<int>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_equality_comparable<
            boost::concept::value_generator_archetype<unsigned int>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::concept::value_generator_archetype<unsigned int>()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::concept::value_generator_archetype<unsigned int>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
//->
            decltype
//<-
#endif
//->
            (
                &boost::concept::value_generator_archetype<
                    unsigned int
                >::min
            )()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
//->
            decltype
//<-
#endif
//->
            (
                &boost::concept::value_generator_archetype<
                    unsigned int
                >::min
            )()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
//->
            decltype
//<-
#endif
//->
            (
                &boost::concept::value_generator_archetype<
                    unsigned int
                >::max
            )()
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF
#else
//->
            decltype
//<-
#endif
//->
            (
                &boost::concept::value_generator_archetype<
                    unsigned int
                >::max
            )()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            typename boost::cxx14_result_of<
                boost::concept::value_generator_archetype<unsigned int>()
            >::type
          , unsigned int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            typename boost::cxx14_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
//->
                decltype
//<-
#endif
//->
                (
                    &boost::concept::value_generator_archetype<
                        unsigned int
                    >::min
                )()
            >::type
          , unsigned int
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            typename boost::cxx14_result_of<
//<-
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF
#else
//->
                decltype
//<-
#endif
//->
                (
                    &boost::concept::value_generator_archetype<
                        unsigned int
                    >::max
                )()
            >::type
          , unsigned int
        >
    ));
}
//]

