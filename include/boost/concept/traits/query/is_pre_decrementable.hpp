// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_PRE_DECREMENTABLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_PRE_DECREMENTABLE_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_pre_decrementable
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD(--::boost::concept::traits::declref<T>())
#else
          , decltype(--::boost::concept::traits::declref<T>())
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_pre_decrement_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if !defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/concept/traits/introspection/is_lvalue_reference_of.hpp>
#endif

//[reference__is_pre_decrementable
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_pre_decrementable
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(--_bct_declref_<T>())
          , _mpl_apply1_<
                ResultPlaceholderExpr
              , _decltype_(--_bct_declref_<T>())
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_pre_decrement_operator<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_pre_decrementable<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

