// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_DATA_FWD_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_DATA_FWD_HPP

#include <boost/concept/policy/use_default.hpp>

//[reference__has_left__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_left;
}}}  // namespace boost::concept::traits
//]

//[reference__has_right__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_right;
}}}  // namespace boost::concept::traits
//]

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__has_first__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_first_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_first_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_first;
}}}  // namespace boost::concept::traits
//]

//[reference__has_second__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_second_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_second_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_second;
}}}  // namespace boost::concept::traits
//]

//[reference__has_max_size_static_const__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_max_size_static_const;
}}}  // namespace boost::concept::traits
//]

//[reference__has_dimensionality_static_const__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        _bct_is_size_type_of_<_mpl_placeholder_,T>
//<-
#else
        ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
#endif
//->
    >
    struct has_dimensionality_static_const;
}}}  // namespace boost::concept::traits
//]

#if !defined(BOOST_RATIO_EXTENSIONS)
#include <boost/cstdint.hpp>
#include <boost/config.hpp>
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#else
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <type_traits>
#endif
#endif

//[reference__has_num__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
#if defined(BOOST_RATIO_EXTENSIONS)
        _bct_is_num_type_of_<_mpl_placeholder_,T>
#else
        _mpl_if_<
            _std_is_convertible_<_mpl_placeholder_,boost::intmax_t>
          , _mpl_true_
          , _mpl_false_
        >
#endif
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
#if defined(BOOST_RATIO_EXTENSIONS)
        ::boost::concept::traits::is_num_type_of< ::boost::mpl::_,T>
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        ::boost::is_convertible< ::boost::mpl::_,::boost::intmax_t>
#else
        ::boost::mpl::if_<
            ::std::is_convertible< ::boost::mpl::_,::boost::intmax_t>
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >
#endif
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_num;
}}}  // namespace boost::concept::traits
//]

//[reference__has_den__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename PlaceholderExpr =
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
#if defined(BOOST_RATIO_EXTENSIONS)
        _bct_is_den_type_of_<_mpl_placeholder_,T>
#else
        _mpl_if_<
            _std_is_convertible_<_mpl_placeholder_,boost::intmax_t>
          , _mpl_true_
          , _mpl_false_
        >
#endif
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
#if defined(BOOST_RATIO_EXTENSIONS)
        ::boost::concept::traits::is_den_type_of< ::boost::mpl::_,T>
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        ::boost::is_convertible< ::boost::mpl::_,::boost::intmax_t>
#else
        ::boost::mpl::if_<
            ::std::is_convertible< ::boost::mpl::_,::boost::intmax_t>
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >
#endif
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    >
    struct has_den;
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

