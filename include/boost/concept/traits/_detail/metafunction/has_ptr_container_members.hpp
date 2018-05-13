// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_PTR_CONTAINER_MEMBERS_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_PTR_CONTAINER_MEMBERS_HPP

#include <boost/concept/traits/query/is_container.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#if !defined BOOST_NO_CXX11_DECLTYPE
#include <boost/type_traits/remove_reference.hpp>
#endif
#else
#include <type_traits>
#endif

#if !defined BOOST_NO_CXX11_DECLTYPE

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_ptr_container_result_expr
      : ::boost::concept::traits::is_container<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_reference<T>::type
#else
            typename ::std::remove_reference<T>::type
#endif
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // BOOST_NO_CXX11_DECLTYPE

#include <boost/concept/traits/introspection/nested_type/has_auto_type.hpp>
#include <boost/concept/traits/introspection/member_function/has_base.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_ptr_container_members
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_base<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
              , ::boost::concept::traits::is_container< ::boost::mpl::_>
#else
              , ::boost::concept::traits::_detail::metafunction
                ::is_ptr_container_result_expr< ::boost::mpl::_>
#endif
              , ::boost::mpl::false_
            >
          , ::boost::concept::traits::has_auto_type<T>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

