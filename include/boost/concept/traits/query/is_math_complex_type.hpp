// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_COMPLEX_TYPE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_COMPLEX_TYPE_HPP

#include <boost/concept/traits/query/is_lvalue_assignable.hpp>
#include <boost/concept/traits/query/is_addable.hpp>
#include <boost/concept/traits/query/is_subtractable.hpp>
#include <boost/concept/traits/query/is_multipliable.hpp>
#include <boost/concept/traits/query/is_dividable.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename _c_T
      , typename _m_T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _c_V = typename ::boost::add_const<
#else
      , typename _c_V = typename ::std::add_const<
#endif
            typename ::boost::concept::traits::value_type_of<T>::type
        >::type
    >
    struct has_math_complex_type_ops
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_lvalue_assignable<_m_T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_multipliable<T,_c_V>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_subtractable<T,_c_V>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::is_dividable<T,_c_V>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits
                            ::is_multipliable<_c_V,_c_T,_m_T>
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits
                                ::is_subtractable<_c_V,_c_T,_m_T>
                              , ::boost::mpl::eval_if<
                                    ::boost::concept::traits
                                    ::is_dividable<_c_V,_c_T,_m_T>
                                  , ::boost::mpl::if_<
                                        ::boost::concept::traits
                                        ::is_addable<T,_c_V>
                                      , ::boost::concept::traits
                                        ::is_addable<_c_V,_c_T,_m_T>
                                      , ::boost::mpl::false_
                                    >
                                  , ::boost::mpl::false_
                                >
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function/has_real.hpp>
#include <boost/concept/traits/introspection/member_function/has_imag.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _const_T = typename ::boost::add_const<
            typename ::boost::remove_reference<T>::type
        >::type
      , typename _mutable_T = typename ::boost::remove_const<
            typename ::boost::remove_reference<T>::type
        >::type
#else
      , typename _const_T = typename ::std::add_const<
            typename ::std::remove_reference<T>::type
        >::type
      , typename _mutable_T = typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
        >::type
#endif
    >
    struct is_math_complex_type
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_real<_mutable_T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_imag<_mutable_T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_real<_const_T>
                  , ::boost::mpl::if_<
                        ::boost::concept::traits::has_imag<_const_T>
                      , ::boost::concept::traits::_detail::metafunction
                        ::has_math_complex_type_ops<T,_const_T,_mutable_T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_identity_operable.hpp>
#include <boost/concept/traits/query/is_negatable.hpp>
#include <boost/concept/traits/query/is_equality_comparable.hpp>

//[reference__is_math_complex_type
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_math_complex_type
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
          _bct_is_lvalue_assignable_<
            typename _std_remove_const_<
              typename _std_remove_reference_<T>::type
            >::type
          >
        , _mpl_eval_if_<
            _bct_has_real_<
              typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
              >::type
            >
          , _mpl_eval_if_<
              _bct_has_imag_<
                typename _std_remove_const_<
                  typename _std_remove_reference_<T>::type
                >::type
              >
            , _mpl_eval_if_<
                _bct_has_real_<
                  typename _std_add_const_<
                    typename _std_remove_reference_<T>::type
                  >::type
                >
              , _mpl_eval_if_<
                  _bct_has_imag_<
                    typename _std_add_const_<
                      typename _std_remove_reference_<T>::type
                    >::type
                  >
                , _mpl_eval_if_<
                    _bct_is_addable_<
                      typename _std_add_const_<
                        typename _std_remove_reference_<T>::type
                      >::type
                    , typename _std_add_const_<
                        typename _bct_value_type_of_<
                          typename _std_remove_reference_<T>::type
                        >::type
                      >::type
                    >
                  , _mpl_eval_if_<
                      _bct_is_subtractable_<
                        typename _std_add_const_<
                          typename _std_remove_reference_<T>::type
                        >::type
                      , typename _std_add_const_<
                          typename _bct_value_type_of_<
                            typename _std_remove_reference_<T>::type
                          >::type
                        >::type
                      >
                    , _mpl_eval_if_<
                        _bct_is_multipliable_<
                          typename _std_add_const_<
                            typename _std_remove_reference_<T>::type
                          >::type
                        , typename _std_add_const_<
                            typename _bct_value_type_of_<
                              typename _std_remove_reference_<T>::type
                            >::type
                          >::type
                        >
                      , _mpl_eval_if_<
                          _bct_is_dividable_<
                            typename _std_add_const_<
                              typename _std_remove_reference_<T>::type
                            >::type
                          , typename _std_add_const_<
                              typename _bct_value_type_of_<
                                typename _std_remove_reference_<T>::type
                              >::type
                            >::type
                          >
                        , _mpl_eval_if_<
                            _bct_is_addable_<
                              typename _std_add_const_<
                                typename _bct_value_type_of_<
                                  typename _std_remove_reference_<T>::type
                                >::type
                              >::type
                            , typename _std_add_const_<
                                typename _std_remove_reference_<T>::type
                              >::type
                            , typename _std_remove_const_<
                                typename _std_remove_reference_<T>::type
                              >::type
                            >
                          , _mpl_eval_if_<
                              _bct_is_subtractable_<
                                typename _std_add_const_<
                                  typename _bct_value_type_of_<
                                    typename _std_remove_reference_<T>::type
                                  >::type
                                >::type
                              , typename _std_add_const_<
                                  typename _std_remove_reference_<T>::type
                                >::type
                              , typename _std_remove_const_<
                                  typename _std_remove_reference_<T>::type
                                >::type
                              >
                            , _mpl_eval_if_<
                                _bct_is_multipiable_<
                                  typename _std_add_const_<
                                    typename _bct_value_type_of_<
                                      typename _std_remove_reference_<T>::type
                                    >::type
                                  >::type
                                , typename _std_add_const_<
                                    typename _std_remove_reference_<T>::type
                                  >::type
                                , typename _std_remove_const_<
                                    typename _std_remove_reference_<T>::type
                                  >::type
                                >
                              , _mpl_eval_if_<
                                  _bct_is_dividable_<
                                    typename _std_add_const_<
                                      typename _bct_value_type_of_<
                                        typename _std_remove_reference_<
                                          T
                                        >::type
                                      >::type
                                    >::type
                                  , typename _std_add_const_<
                                      typename _std_remove_reference_<T>::type
                                    >::type
                                  , typename _std_remove_const_<
                                      typename _std_remove_reference_<T>::type
                                    >::type
                                  >
                                , _mpl_eval_if_<
                                    _bct_is_equality_comparable_<T>
                                  , _mpl_if_<
                                      _bct_is_identity_operable_<T>
                                    , _bct_is_negatable_<T>
                                    , _mpl_false_
                                    >
                                  , _mpl_false_
                                  >
                                , _mpl_false_
                                >
                              , _mpl_false_
                              >
                            , _mpl_false_
                            >
                          , _mpl_false_
                          >
                        , _mpl_false_
                        >
                      , _mpl_false_
                      >
                    , _mpl_false_
                    >
                  , _mpl_false_
                  >
                , _mpl_false_
                >
              , _mpl_false_
              >
            , _mpl_false_
            >
          , _mpl_false_
          >
        , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_equality_comparable<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_identity_operable<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_negatable<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_math_complex_type<T>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

