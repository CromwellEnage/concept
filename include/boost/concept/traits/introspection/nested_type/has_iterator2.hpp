// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_ITERATOR2_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_ITERATOR2_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        has_iterator2_void_or_not
      , iterator2
      , false
    )

    template <typename T>
    struct has_iterator2_non_void
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_void<typename T::iterator2>
#else
            ::std::is_void<typename T::iterator2>
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct has_iterator2_impl
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_iterator2_void_or_not<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_iterator2_non_void<T>
          , ::boost::mpl::false_
        >::type
    {
    };

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        has_const_iterator2_void_or_not
      , const_iterator2
      , false
    )

    template <typename T>
    struct has_const_iterator2_non_void
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_void<
                typename ::boost::remove_const<T>::type::const_iterator2
            >
#else
            ::std::is_void<
                typename ::std::remove_const<T>::type::const_iterator2
            >
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct has_const_iterator2_impl
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_const_iterator2_void_or_not<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_const_iterator2_non_void<T>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#endif

//[reference__has_iterator2
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_iterator2
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _std_is_const_<T>
          , _mpl_eval_if_<
                typename _mpl_has_trait_named_(const_iterator2)<
                    typename _std_remove_const_<T>::type
                >::type
              , _mpl_if_<
                    _std_is_void_<
                        typename _std_remove_const_<T>::type::const_iterator2
                    >
                  , _mpl_false_
                  , _mpl_true_
                >
              , _mpl_false_
            >
          , _mpl_eval_if_<
                typename _mpl_has_trait_named_(iterator2)<T>::type
              , _mpl_if_<
                    _std_is_void_<typename T::iterator2>
                  , _mpl_false_
                  , _mpl_true_
                >
              , _mpl_false_
            >
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_const<T>
#else
            ::std::is_const<T>
#endif
          , ::boost::concept::traits::_detail::metafunction
            ::has_const_iterator2_impl<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_iterator2_impl<T>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

