// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_MINIMAL_OR_MUTABLE_DS_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_MINIMAL_OR_MUTABLE_DS_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename ItrPredPlaceholderExpr
      , typename MinPredPlaceholderExpr
      , typename MutPredPlaceholderExpr
    >
    struct is_minimal_or_mutable_ds
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::apply2<
                MinPredPlaceholderExpr
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::remove_const<T>::type
#else
              , typename ::std::remove_const<T>::type
#endif
              , ItrPredPlaceholderExpr
            >::type
          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_const<T>
#else
                ::std::is_const<T>
#endif
              , ::boost::mpl::true_
              , ::boost::mpl::apply1<MutPredPlaceholderExpr,T>
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

