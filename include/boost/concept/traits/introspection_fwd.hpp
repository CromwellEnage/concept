// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_FWD_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_FWD_HPP

//[reference__has_stable_iterators__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_stable_iterators;
}}}  // namespace boost::concept::traits
//]

//[reference__is_convertible_to_cref_of__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_convertible_to_cref_of;
}}}  // namespace boost::concept::traits
//]

//[reference__is_result_of__fwd
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_result_of;
}}}  // namespace boost::concept::traits
//]

#include <boost/mpl/quote.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

//[reference__is_lvalue_reference_of__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T1
      , typename T2
      , typename BinaryPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _mpl_quote2_<_std_is_same_>
//<-
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        ::boost::mpl::quote2< ::boost::is_same>
#else
        ::boost::mpl::quote2< ::std::is_same>
#endif
//->
    >
    struct is_lvalue_reference_of;
}}}  // namespace boost::concept::traits
//]

//[reference__is_raw_pointer_of__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T1
      , typename T2
      , typename BinaryPlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _mpl_quote2_<_std_is_same_>
//<-
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        ::boost::mpl::quote2< ::boost::is_same>
#else
        ::boost::mpl::quote2< ::std::is_same>
#endif
//->
    >
    struct is_raw_pointer_of;
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

