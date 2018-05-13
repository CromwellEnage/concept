// Copyright (C) 2014-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept/archetype/value_distribution_w_param.hpp>
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
#include <boost/mpl/aux_/has_type.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

//[test__value_distribution_archetype_with_param
MPL_TEST_CASE()
{
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_value_generator<
            boost::concept::value_distribution_archetype_with_param<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution<
            boost::concept::value_distribution_archetype_with_param<double>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_value_distribution_with_param<
            boost::concept::value_distribution_archetype_with_param<double>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::concept::value_distribution_archetype_with_param<double>()
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        boost::concept::traits::is_callable<
            boost::concept::value_distribution_archetype_with_param<double>()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::concept::value_distribution_archetype_with_param<double>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::concept::value_distribution_archetype_with_param<double>(
                boost::concept::value_generator_archetype<unsigned int>&
            )
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::concept::value_distribution_archetype_with_param<double>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::concept::value_distribution_archetype_with_param<
                    double
                >::param_type const&
            )
        >
    ));
    BOOST_MPL_ASSERT((
        boost::concept::traits::is_callable<
            boost::concept::value_distribution_archetype_with_param<double>(
                boost::concept::value_generator_archetype<unsigned int>&
              , boost::concept::value_distribution_archetype_with_param<
                    double
                >::param_type const&
            )
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
                &boost::concept::value_distribution_archetype_with_param<
                    double
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
                &boost::concept::value_distribution_archetype_with_param<
                    double
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
                &boost::concept::value_distribution_archetype_with_param<
                    double
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
                &boost::concept::value_distribution_archetype_with_param<
                    double
                >::max
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
                &boost::concept::value_distribution_archetype_with_param<
                    double
                >::reset
            )()
        >
    ));
    BOOST_MPL_ASSERT_NOT((
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
                &boost::concept::value_distribution_archetype_with_param<
                    double
                >::reset
            )()
          , boost::concept::traits::is_boolean_expression<boost::mpl::_>
        >
    ));
    BOOST_MPL_ASSERT_NOT((
        typename boost::mpl::aux::has_type<
            boost::cxx14_result_of<
                boost::concept::value_distribution_archetype_with_param<
                    double
                >()
            >
        >::type
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            typename boost::cxx14_result_of<
                boost::concept::value_distribution_archetype_with_param<
                    double
                >(boost::concept::value_generator_archetype<unsigned int>&)
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_same<
            typename boost::cxx14_result_of<
                boost::concept::value_distribution_archetype_with_param<
                    double
                >(
                    boost::concept::value_generator_archetype<unsigned int>&
                  , boost::concept::value_distribution_archetype_with_param<
                        double
                    >::param_type const&
                )
            >::type
          , double
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
                    &boost::concept::value_distribution_archetype_with_param<
                        double
                    >::min
                )()
            >::type
          , double
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
                    &boost::concept::value_distribution_archetype_with_param<
                        double
                    >::max
                )()
            >::type
          , double
        >
    ));
    BOOST_MPL_ASSERT((
        boost::is_void<
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
                    &boost::concept::value_distribution_archetype_with_param<
                        double
                    >::reset
                )()
            >::type
        >
    ));
}
//]

