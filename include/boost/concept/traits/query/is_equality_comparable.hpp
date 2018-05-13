// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_EQUALITY_COMPARABLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_EQUALITY_COMPARABLE_HPP

#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    struct is_equality_comparable_impl
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_boolean_expression<
#if defined(BOOST_NO_CXX11_DECLTYPE)
                BOOST_TYPEOF_KEYWORD(
                    ::boost::declval<T>() == ::boost::declval<U>()
                )
#else
                decltype(::boost::declval<T>() == ::boost::declval<U>())
#endif
            >
          , ::boost::concept::traits::is_boolean_expression<
#if defined(BOOST_NO_CXX11_DECLTYPE)
                BOOST_TYPEOF_KEYWORD(
                    ::boost::declval<T>() != ::boost::declval<U>()
                )
#else
                decltype(::boost::declval<T>() != ::boost::declval<U>())
#endif
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    class has_equality_comparable_operators
    {
        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check_eq(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::declval<L>() == ::boost::declval<R>()
                    )
#else
                    decltype(::boost::declval<L>() == ::boost::declval<R>())
#endif
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check_eq(...);

        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check_neq(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::declval<L>() != ::boost::declval<R>()
                    )
#else
                    decltype(::boost::declval<L>() != ::boost::declval<R>())
#endif
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check_neq(...);

     public:
        typedef typename ::boost::mpl::if_c<
            (
                sizeof(
                    ::boost::concept::traits::_detail::metafunction
                    ::has_equality_comparable_operators<T,U>
                    ::BOOST_NESTED_TEMPLATE
                    _check_eq<T,U>(BOOST_TTI_DETAIL_NULLPTR)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::boost::concept::traits::_detail::metafunction
                    ::has_equality_comparable_operators<T,U>
                    ::BOOST_NESTED_TEMPLATE
                    _check_neq<T,U>(BOOST_TTI_DETAIL_NULLPTR)
                ) == sizeof(::boost::type_traits::yes_type)
            )
          , ::boost::concept::traits::_detail::metafunction
            ::is_equality_comparable_impl<T,U>
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_equality_comparable
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U>
    struct is_equality_comparable
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _mpl_and_<
                _is_valid_expression_(_declval_<T>() == _declval_<U>())
              , _is_valid_expression_(_declval_<T>() != _declval_<U>())
              , _is_valid_expression_(_declval_<U>() == _declval_<T>())
              , _is_valid_expression_(_declval_<U>() != _declval_<T>())
            >
          , _mpl_and_<
                _bct_is_boolean_expression_<
                    _decltype_(_declval_<T>() == _declval_<U>())
                >
              , _bct_is_boolean_expression_<
                    _decltype_(_declval_<T>() != _declval_<U>())
                >
              , _bct_is_boolean_expression_<
                    _decltype_(_declval_<U>() == _declval_<T>())
                >
              , _bct_is_boolean_expression_<
                    _decltype_(_declval_<U>() != _declval_<T>())
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_equality_comparable_operators<T,U>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_equality_comparable_operators<U,T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };

    template <typename T>
    struct is_equality_comparable<T,::boost::concept::policy::use_default>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _mpl_and_<
                _is_valid_expression_(_declval_<T>() == _declval_<T>())
              , _is_valid_expression_(_declval_<T>() != _declval_<T>())
            >
          , _mpl_and_<
                _bct_is_boolean_expression_<
                    _decltype_(_declval_<T>() == _declval_<T>())
                >
              , _bct_is_boolean_expression_<
                    _decltype_(_declval_<T>() != _declval_<T>())
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::concept::traits::_detail::metafunction
        ::has_equality_comparable_operators<T,T>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

