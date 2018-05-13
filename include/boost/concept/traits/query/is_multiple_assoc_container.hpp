// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MULTIPLE_ASSOC_CONTAINER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MULTIPLE_ASSOC_CONTAINER_HPP

#include <boost/concept/traits/introspection/member_function/has_insert.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_multiple_associative_container_impl
      : ::boost::concept::traits::has_insert<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<T>::type
          , typename ::boost::add_const<
#else
            typename ::std::remove_const<T>::type
          , typename ::std::add_const<
#endif
                typename ::boost::concept::traits::value_type_of<T>::type
            >::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_associative_container.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_multiple_associative_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_multiple_associative_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _bct_is_associative_container_<T>
          , _bct_has_insert_<
                typename _std_remove_const_<T>::type
              , typename _std_add_const_<
                    typename _bct_value_type_of_<T>::type
                >::type
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_associative_container<T>
          , ::boost::concept::traits::_detail::metafunction
            ::is_multiple_associative_container_impl<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

