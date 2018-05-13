// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_CAPACITY_TYPE_OF_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_CAPACITY_TYPE_OF_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_capacity_type_of_impl
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_convertible<
            typename ::boost::remove_const<T2>::type::capacity_type
          , typename ::boost::add_lvalue_reference<
                typename ::boost::add_const<T1>::type
            >::type
        >
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
                typename ::std::remove_const<T2>::type::capacity_type
              , typename ::std::add_lvalue_reference<
                    typename ::std::add_const<T1>::type
                >::type
            >
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_capacity_type.hpp>

//[reference__is_capacity_type_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_capacity_type_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _bct_has_capacity_type_<T2>
          , _std_is_convertible_<
                typename _std_remove_const_<T2>::type::capacity_type
              , typename _std_add_lvalue_reference_<
                    typename _std_add_const_<T1>::type
                >::type
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_capacity_type<T2>
          , ::boost::concept::traits::_detail::metafunction
            ::is_capacity_type_of_impl<T1,T2>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

