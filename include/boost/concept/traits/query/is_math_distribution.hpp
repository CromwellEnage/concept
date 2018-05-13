// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_DISTRIBUTION_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_DISTRIBUTION_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_lvalue_assignable.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/traits/introspection/nested_type/has_policy_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__is_math_distribution
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_math_distribution
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_lvalue_assignable_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_if_<
                _bct_has_value_type_<T>
              , _bct_has_policy_type_<T>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_lvalue_assignable<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_value_type<T>
              , ::boost::concept::traits::has_policy_type<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

