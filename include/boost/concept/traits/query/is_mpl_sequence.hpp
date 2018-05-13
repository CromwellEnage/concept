// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_SEQUENCE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_SEQUENCE_HPP

#include <boost/mpl/apply.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename PlaceholderExpr, typename T>
    struct is_mpl_sequence
      : ::boost::mpl::apply1<
            PlaceholderExpr
          , typename ::boost::mpl::begin<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >::type
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_mpl_forward_iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/is_sequence.hpp>

//[reference__is_mpl_sequence
namespace boost { namespace concept { namespace traits {

    template <typename T, typename PlaceholderExpr>
    struct is_mpl_sequence
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _mpl_is_sequence_<typename _std_remove_const_<T>::type>
          , _mpl_apply1_<
                PlaceholderExpr
              , typename _mpl_begin_<
                    typename _std_remove_const_<T>::type
                >::type
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::if_<
            ::boost::mpl::is_sequence<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_mpl_sequence<PlaceholderExpr,T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

