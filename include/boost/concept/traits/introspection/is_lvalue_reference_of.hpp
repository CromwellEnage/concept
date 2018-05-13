// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_IS_LVALUE_REFERENCE_OF_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_IS_LVALUE_REFERENCE_OF_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_lvalue_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2, typename BinaryPlaceholderExpr>
    struct is_lvalue_reference_of_impl
      : ::boost::mpl::if_<
            typename ::boost::mpl::apply2<
                BinaryPlaceholderExpr
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , typename ::boost::add_lvalue_reference<T2>::type
#else
              , typename ::std::add_lvalue_reference<T2>::type
#endif
              , T1
            >::type
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2, typename BinaryPlaceholderExpr>
    struct is_lvalue_const_reference_of_impl
      : ::boost::mpl::if_<
            typename ::boost::mpl::apply2<
                BinaryPlaceholderExpr
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , typename ::boost::add_lvalue_reference<
                    typename ::boost::add_const<
                        typename ::boost::remove_reference<T2>::type
#else
              , typename ::std::add_lvalue_reference<
                    typename ::std::add_const<
                        typename ::std::remove_reference<T2>::type
#endif
                    >::type
                >::type
              , T1
            >::type
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection_fwd.hpp>
#include <boost/config/workaround.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || ( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1700) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1800) \
    )
#include <boost/type_traits/is_const.hpp>
#endif

//[reference__is_lvalue_reference_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2, typename BinaryPlaceholderExpr>
    struct is_lvalue_reference_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _std_is_const_<
                typename _std_remove_reference_<T1>::type
            >
          , _mpl_if_<
                typename _mpl_apply2_<
                    BinaryPlaceholderExpr
                  , typename _std_add_lvalue_reference_<
                        typename _std_add_const_<
                            typename _std_remove_reference_<T2>::type
                        >::type
                    >::type
                  , T1
                >::type
              , _mpl_true_
              , _mpl_false_
            >
          , _mpl_if_<
                typename _mpl_apply2_<
                    BinaryPlaceholderExpr
                  , typename _std_add_lvalue_reference_<T2>::type
                  , T1
                >::type
              , _mpl_true_
              , _mpl_false_
            >
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS) || ( \
        BOOST_WORKAROUND(BOOST_MSVC, >= 1700) && \
        BOOST_WORKAROUND(BOOST_MSVC, < 1800) \
    )
            ::boost::is_const<
#else
            ::std::is_const<
#endif
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_reference<T1>::type
#else
                typename ::std::remove_reference<T1>::type
#endif
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_lvalue_const_reference_of_impl<T1,T2,BinaryPlaceholderExpr>
          , ::boost::concept::traits::_detail::metafunction
            ::is_lvalue_reference_of_impl<T1,T2,BinaryPlaceholderExpr>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

