// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_PAIR_ASSOC_CONT_IMPL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_PAIR_ASSOC_CONT_IMPL_HPP

#include <boost/concept/traits/trivial_access/first_type_of.hpp>
#include <boost/concept/traits/trivial_access/second_type_of.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/concept/traits/trivial_access/key_type_of.hpp>
#include <boost/concept/traits/trivial_access/mapped_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_pair_associative_container_members
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::mpl::if_<
            ::boost::is_same<
                typename ::boost::add_const<
#else
      : ::boost::mpl::eval_if<
            ::std::is_same<
                typename ::std::add_const<
#endif
                    typename ::boost::concept::traits::key_type_of<T>::type
                >::type
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::add_const<
#else
              , typename ::std::add_const<
#endif
                    typename ::boost::concept::traits::first_type_of<
                        typename ::boost::concept::traits
                        ::value_type_of<T>::type
                    >::type
                >::type
            >
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_same<
#else
          , ::boost::mpl::if_<
                ::std::is_same<
#endif
                    typename ::boost::concept::traits::second_type_of<
                        typename ::boost::concept::traits
                        ::value_type_of<T>::type
                    >::type
                  , typename ::boost::concept::traits::mapped_type_of<T>::type
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                >
              , ::boost::mpl::true_
              , ::boost::mpl::false_
#endif
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_runtime_pair.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_pair_associative_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_runtime_pair<
                typename ::boost::concept::traits::value_type_of<T>::type
            >
          , ::boost::concept::traits::_detail::metafunction
            ::has_pair_associative_container_members<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

