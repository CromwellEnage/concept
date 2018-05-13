// Copyright (C) 2012-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_ITERATOR_CATEGORY_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_ITERATOR_CATEGORY_HPP

#include <boost/mpl/has_xxx.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        has_iterator_category_void_or_not
      , iterator_category
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
    struct has_iterator_category_non_void
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_void<typename T::iterator_category>
#else
            ::std::is_void<typename T::iterator_category>
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct has_iterator_category
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_iterator_category_void_or_not<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_iterator_category_non_void<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
#include <iterator>
#endif

//[reference__has_iterator_category
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_iterator_category
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_has_trait_named_(iterator_category)<
            _std_iterator_traits_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction
        ::has_iterator_category<
#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
            ::std::iterator_traits<
#endif
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
            >
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

