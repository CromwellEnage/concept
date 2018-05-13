// Copyright (C) 2011-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ADAPTABLE_BINARY_FUNC_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ADAPTABLE_BINARY_FUNC_HPP

#include <boost/concept/traits/trivial_access/result_type_of.hpp>
#include <boost/concept/traits/trivial_access/first_argument_type_of.hpp>
#include <boost/concept/traits/trivial_access/second_argument_type_of.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/is_convertible.hpp>
#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif
#else
#include <boost/mpl/if.hpp>
#include <type_traits>
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_adaptable_binary_function_impl
      : ::boost::mpl::eval_if<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_void<
#else
            ::std::is_void<
#endif
                typename ::boost::concept::traits::result_type_of<T>::type
            >
          , ::boost::mpl::true_
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::is_convertible<
#else
          , ::boost::mpl::if_<
                ::std::is_convertible<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD((
                        ::boost::declval<T>()(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::first_argument_type_of<T>::type
                            >()
                          , ::boost::declval<
                                typename ::boost::concept::traits
                                ::second_argument_type_of<T>::type
                            >()
                        )
                    ))
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                  , typename ::boost::remove_const<
                        typename ::boost::remove_reference<
#else
                  , typename ::std::remove_const<
                        typename ::std::remove_reference<
#endif
                            typename ::boost::concept::traits
                            ::result_type_of<T>::type
                        >::type
                    >::type
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
                    decltype(
                        ::boost::declval<T>()(
                            ::boost::declval<
                                typename ::boost::concept::traits
                                ::first_argument_type_of<T>::type
                            >()
                          , ::boost::declval<
                                typename ::boost::concept::traits
                                ::second_argument_type_of<T>::type
                            >()
                        )
                    )
                  , typename ::boost::concept::traits::result_type_of<T>::type
#endif  // BOOST_NO_CXX11_DECLTYPE
                >
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , ::boost::mpl::true_
              , ::boost::mpl::false_
            >
#endif
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_binary_function.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_adaptable_binary_function
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_binary_function<
                T
              , typename ::boost::concept::traits
                ::first_argument_type_of<T>::type
              , typename ::boost::concept::traits
                ::second_argument_type_of<T>::type
              , ResultPlaceholderExpr
            >
          , ::boost::concept::traits::_detail::metafunction
            ::is_adaptable_binary_function_impl<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_result_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_first_argument_type.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_second_argument_type.hpp>

//[reference__is_adaptable_binary_function
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_adaptable_binary_function
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
          _bct_has_result_type_<T>
        , _mpl_eval_if_<
            _bct_has_first_argument_type_<T>
          , _mpl_eval_if_<
              _bct_has_second_argument_type_<T>
            , _mpl_eval_if_<
                _bct_is_binary_function_<
                  T
                , typename _bct_first_argument_type_of_<T>::type
                , typename _bct_second_argument_type_of_<T>::type
                , ResultPlaceholderExpr
                >
              , _mpl_eval_if_<
                  _std_is_void_<
                    typename _bct_result_type_of_<T>::type
                  >
                , _mpl_true_
                , _mpl_eval_if_<
                    _std_is_convertible_<
                      _decltype_(
                        _declval_<T>()(
                          _declval_<
                            typename _bct_first_argument_type_of_<T>
                            ::type
                          >()
                        , _declval_<
                            typename _bct_second_argument_type_of_<T>
                            ::type
                          >()
                        )
                      )
                    , typename _bct_result_type_of_<T>::type
                    >
                  , _mpl_true_
                  , _mpl_false_
                  >
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
            ::boost::concept::traits::has_result_type<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_first_argument_type<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_second_argument_type<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_adaptable_binary_function<T,ResultPlaceholderExpr>
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

