// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_POST_INC_DEREF_NV_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_POST_INC_DEREF_NV_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_void.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_post_increment_dereferenceable_non_void
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_void<
#else
            ::std::is_void<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                BOOST_TYPEOF_KEYWORD(
                    *::boost::concept::traits::declref<T>()++
                )
#else
                decltype(*::boost::concept::traits::declref<T>()++)
#endif
            >
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

