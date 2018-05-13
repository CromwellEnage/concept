// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_IS_ALWAYS_EQUAL_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_IS_ALWAYS_EQUAL_HPP

#include <boost/mpl/has_xxx.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        is_always_equal_void_or_not
      , is_always_equal
      , false
    )
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_void.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_always_equal_non_void
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_void<typename T::is_always_equal>
#else
            ::std::is_void<typename T::is_always_equal>
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_empty.hpp>
#else
#include <boost/mpl/eval_if.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_always_equal
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::mpl::if_<
#else
      : ::boost::mpl::eval_if<
#endif
            typename ::boost::concept::traits::_detail::metafunction
            ::is_always_equal_void_or_not<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_always_equal_non_void<T>
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::is_empty<T>
#else
          , ::boost::mpl::if_<
                ::std::is_empty<T>
              , ::boost::mpl::true_
              , ::boost::mpl::false_
            >
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access_fwd.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__is_always_equal
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_always_equal
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _std_allocator_traits_<
            typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
            >::type
        >::is_always_equal
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::is_always_equal<
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
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

