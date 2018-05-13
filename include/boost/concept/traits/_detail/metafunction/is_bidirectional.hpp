// Copyright (C) 2012-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_BIDIRECTIONAL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_BIDIRECTIONAL_HPP

#include <boost/concept/traits/introspection/is_convertible_to_cref_of.hpp>
#include <boost/concept/traits/declref.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_post_dec_conv_to_cref_of
      : ::boost::concept::traits::is_convertible_to_cref_of<
#if defined(BOOST_NO_CXX11_DECLTYPE)
            BOOST_TYPEOF_KEYWORD(::boost::concept::traits::declref<T>()--)
#else
            decltype(::boost::concept::traits::declref<T>()--)
#endif
          , T
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_pre_decrementable.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_post_decrement_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_bidirectional
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_post_decrement_operator<T>::type
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_pre_decrementable<T>
              , ::boost::mpl::if_<
              , ::boost::concept::traits::_detail::metafunction
                ::is_post_dec_conv_to_cref_of<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

