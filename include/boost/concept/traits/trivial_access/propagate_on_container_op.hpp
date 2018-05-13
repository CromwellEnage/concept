// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_PROPAGATE_ON_CONTAINER_OP_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_PROPAGATE_ON_CONTAINER_OP_HPP

#include <boost/mpl/has_xxx.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        propagate_on_container_copy_assignment_void_or_not
      , propagate_on_container_copy_assignment
      , false
    )

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        propagate_on_container_move_assignment_void_or_not
      , propagate_on_container_move_assignment
      , false
    )

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        propagate_on_container_swap_void_or_not
      , propagate_on_container_swap
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
    struct propagate_on_container_copy_assignment_non_void
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_void
#else
            ::std::is_void
#endif
            <typename T::propagate_on_container_copy_assignment>
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct propagate_on_container_copy_assignment
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::propagate_on_container_copy_assignment_void_or_not<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::propagate_on_container_copy_assignment_non_void<T>
          , ::boost::mpl::false_
        >::type
    {
    };

    template <typename T>
    struct propagate_on_container_move_assignment_non_void
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_void
#else
            ::std::is_void
#endif
            <typename T::propagate_on_container_move_assignment>
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct propagate_on_container_move_assignment
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::propagate_on_container_move_assignment_void_or_not<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::propagate_on_container_move_assignment_non_void<T>
          , ::boost::mpl::false_
        >::type
    {
    };

    template <typename T>
    struct propagate_on_container_swap_non_void
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_void<typename T::propagate_on_container_swap>
#else
            ::std::is_void<typename T::propagate_on_container_swap>
#endif
          , ::boost::mpl::false_
          , ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct propagate_on_container_swap
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::propagate_on_container_swap_void_or_not<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::propagate_on_container_swap_non_void<T>
          , ::boost::mpl::false_
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

//[reference__propagate_on_container_copy_assignment
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct propagate_on_container_copy_assignment
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _std_allocator_traits_<
            typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
            >::type
        >::propagate_on_container_copy_assignment
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction
        ::propagate_on_container_copy_assignment<
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

//[reference__propagate_on_container_move_assignment
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct propagate_on_container_move_assignment
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _std_allocator_traits_<
            typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
            >::type
        >::propagate_on_container_move_assignment
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction
        ::propagate_on_container_move_assignment<
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

//[reference__propagate_on_container_swap
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct propagate_on_container_swap
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _std_allocator_traits_<
            typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
            >::type
        >::propagate_on_container_swap
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction
        ::propagate_on_container_swap<
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

