// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_BOOLEAN_EXPRESSION_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_BOOLEAN_EXPRESSION_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_logically_negatable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__is_boolean_expression
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_boolean_expression
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _std_is_convertible_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
              , bool
            >
          , _mpl_true_
          , _bct_is_logically_negatable_<T>
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_convertible<
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
#else
            ::std::is_convertible<
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
#endif
                >::type
              , bool
            >
          , ::boost::mpl::true_
          , ::boost::concept::traits::is_logically_negatable<T>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

