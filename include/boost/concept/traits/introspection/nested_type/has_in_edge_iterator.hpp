// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_IN_EDGE_ITERATOR_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_IN_EDGE_ITERATOR_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_void.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        has_in_edge_iterator_void_or_not
      , in_edge_iterator
      , false
    )

    template <typename T>
    struct has_in_edge_iterator_non_void
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_void<typename T::in_edge_iterator>
#else
            ::std::is_void<typename T::in_edge_iterator>
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct has_in_edge_iterator_impl
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_in_edge_iterator_void_or_not<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_in_edge_iterator_non_void<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#endif

//[reference__has_in_edge_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_in_edge_iterator
//<-
#if defined BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_has_trait_named_(in_edge_iterator)<
                typename _std_remove_const_<T>::type
            >::type
          , _mpl_if_<
                _std_is_void_<
                    typename _std_remove_const_<T>::type::in_edge_iterator
                >
              , _mpl_false_
              , _mpl_true_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::has_in_edge_iterator_impl<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<T>::type
#else
            typename ::std::remove_const<T>::type
#endif
        >::type
#endif  // BOOST_CONCEPT_TRAITS_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

