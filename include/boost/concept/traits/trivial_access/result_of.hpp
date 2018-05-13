// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_RESULT_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_RESULT_OF_HPP

#include <boost/move/utility_core.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost/concept/policy/use_default.hpp>
#include <boost/concept/traits/_detail/preprocessor/config.hpp>
#include <boost/concept/traits/_detail/preprocessor/has_function_def.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)

#define BOOST_CONCEPT_TRAITS_RESULT_OF_EXPR(z, n, P) \
    template <typename F BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, typename P)> \
    struct result_of_expr<true, F BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, P)> \
    { \
        typedef BOOST_TYPEOF_KEYWORD(( \
            BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_CALL_Z( \
                z, n, (::boost::forward<F>(::boost::declval<F>()))(P) \
            ) \
        )) type; \
    };
/* BOOST_CONCEPT_TRAITS_RESULT_OF_EXPR */

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#define BOOST_CONCEPT_TRAITS_RESULT_OF_SEQ(ns) \
    (ns)(result_of_impl)(::boost::forward<B>(::boost::declval<B>())) \
    (result_of_expr)(BOOST_TYPEOF_KEYWORD)(::boost::add_pointer)(1)
/**/
#else   // !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#define BOOST_CONCEPT_TRAITS_RESULT_OF_SEQ(ns) \
    (ns)(result_of_impl)(::boost::forward<B>(::boost::declval<B>())) \
    (result_of_expr)(BOOST_TYPEOF_KEYWORD)(::std::add_pointer)(1)
/**/
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS

#else   // !defined(BOOST_NO_CXX11_DECLTYPE)

#define BOOST_CONCEPT_TRAITS_RESULT_OF_EXPR(z, n, P) \
    template <typename F BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, typename P)> \
    struct result_of_expr<true, F BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, P)> \
    { \
        typedef decltype( \
            BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_CALL_Z( \
                z, n, (::boost::forward<F>(::boost::declval<F>()))(P) \
            ) \
        ) type; \
    };
/* BOOST_CONCEPT_TRAITS_RESULT_OF_EXPR */

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#define BOOST_CONCEPT_TRAITS_RESULT_OF_SEQ(ns) \
    (ns)(result_of_impl)(::boost::forward<B>(::boost::declval<B>())) \
    (result_of_expr)(decltype)(::boost::add_pointer)(1)
/**/
#else   // !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#define BOOST_CONCEPT_TRAITS_RESULT_OF_SEQ(ns) \
    (ns)(result_of_impl)(::boost::forward<B>(::boost::declval<B>())) \
    (result_of_expr)(decltype)(::std::add_pointer)(1)
/**/
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS

#endif  // BOOST_NO_CXX11_DECLTYPE

#else   // !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#endif  // BOOST_NO_CXX11_VARIADIC_TEMPLATES

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <
        bool b
      , typename F
        BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
            BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
          , typename P
          , = ::boost::concept::policy::use_default BOOST_PP_INTERCEPT
        )
    >
    struct result_of_expr
    {
    };

    BOOST_PP_REPEAT(
        BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
      , BOOST_CONCEPT_TRAITS_RESULT_OF_EXPR
      , P
    )
    BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF(
        BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
      , BOOST_CONCEPT_TRAITS_RESULT_OF_SEQ(
            ::boost::concept::traits::_detail::metafunction::
        )
    )
    BOOST_PP_REPEAT(
        BOOST_PP_DEC(BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT)
      , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF_Z
      , BOOST_CONCEPT_TRAITS_RESULT_OF_SEQ(
            ::boost::concept::traits::_detail::metafunction::
        )
    )
#else   // !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    template <bool b, typename F, typename... Args>
    struct result_of_expr
    {
#if defined(BOOST_NO_CXX11_DECLTYPE)
        typedef BOOST_TYPEOF_KEYWORD
#else
        typedef decltype
#endif
        (
            ::boost::forward<F>(::boost::declval<F>())(
                ::boost::forward<Args>(::boost::declval<Args>())...
            )
        ) type;
    };

    template <typename F, typename... Args>
    struct result_of_expr<false,F,Args...>
    {
    };

    template <typename F, typename... Args>
    class result_of_impl
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::forward<B>(::boost::declval<B>())(
                            ::boost::forward<Args>(
                                ::boost::declval<Args>()
                            )...
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::concept::traits::_detail::metafunction
        ::result_of_expr<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::result_of_impl<F,Args...>
                ::_check<F>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , F
          , Args...
        > type;
    };
#endif  // BOOST_NO_CXX11_VARIADIC_TEMPLATES
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#undef BOOST_CONCEPT_TRAITS_RESULT_OF_SEQ
#undef BOOST_CONCEPT_TRAITS_RESULT_OF_EXPR
#endif

#include <boost/concept/traits/trivial_access_fwd.hpp>
#include <boost/concept/traits/trivial_access/result_type_of.hpp>
#include <boost/concept/traits/introspection/nested_type/has_result_type.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#include <boost/preprocessor/repetition/enum_params.hpp>

#define BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION(z, n, P) \
    template < \
        typename R \
      , typename T \
        BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, typename P) \
    > \
    struct result_of< \
        R (T::*(BOOST_PP_ENUM_PARAMS_Z(z, n, P)))( \
            BOOST_PP_ENUM_PARAMS_Z(z, n, P) \
        ) \
    > \
    { \
        typedef R type; \
    };
/* BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION */

#define BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION_CONST(z, n, P) \
    template < \
        typename R \
      , typename T \
        BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, typename P) \
    > \
    struct result_of< \
        R (T::*(BOOST_PP_ENUM_PARAMS_Z(z, n, P)))( \
            BOOST_PP_ENUM_PARAMS_Z(z, n, P) \
        ) const \
    > \
    { \
        typedef R type; \
    };
/* BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION_CONST */

#define BOOST_CONCEPT_TRAITS_RESULT_OF_FUNCTION(z, n, P) \
    template <typename F BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, typename P)> \
    struct result_of<F(BOOST_PP_ENUM_PARAMS_Z(z, n, P))> \
      : ::boost::mpl::eval_if< \
            ::boost::concept::traits::has_result_type< \
                F(BOOST_PP_ENUM_PARAMS_Z(z, n, P)) \
            > \
          , ::boost::mpl::identity< \
                ::boost::concept::traits::result_type_of< \
                    F(BOOST_PP_ENUM_PARAMS_Z(z, n, P)) \
                > \
            > \
          , ::boost::concept::traits::_detail::metafunction::result_of_impl< \
                F BOOST_PP_ENUM_TRAILING_PARAMS_Z(z, n, P) \
            > \
        >::type \
    { \
    };
/* BOOST_CONCEPT_TRAITS_RESULT_OF_FUNCTION */

#endif  // BOOST_NO_CXX11_VARIADIC_TEMPLATES

//[reference__result_of
namespace boost { namespace concept { namespace traits {

    template <typename>
    struct result_of
    {
    };

    template <typename R, typename T>
    struct result_of<R T::*>
    {
        typedef R type;
    };

//<-
#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    BOOST_PP_REPEAT(
        BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
      , BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION
      , P
    )

    BOOST_PP_REPEAT(
        BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
      , BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION_CONST
      , P
    )

    BOOST_PP_REPEAT(
        BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
      , BOOST_CONCEPT_TRAITS_RESULT_OF_FUNCTION
      , P
    )
#else   // !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
//->
    template <typename R, typename T, typename... Args>
    struct result_of<R (T::*(Args...))(Args...)>
    {
        typedef R type;
    };

    template <typename R, typename T, typename... Args>
    struct result_of<R (T::*(Args...))(Args...) const>
    {
        typedef R type;
    };

    template <typename F, typename... Args>
    struct result_of<F(Args...)>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_has_result_type_<F(Args...)>
          , _bct_result_type_of_<F(Args...)>
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _forward_<F>(_declval_<F>())(
                        _forward_<Args>(_declval_<Args>())...
                    )
                )
              , _mpl_identity_<
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    _BOOST_TYPEOF_KEYWORD_
#else
                    _decltype_
#endif
                    (
                        _forward_<F>(_declval_<F>())(
                            _forward_<Args>(_declval_<Args>())...
                        )
                    )
                >
              , void
            >
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_result_type<F(Args...)>
          , ::boost::mpl::identity<
                ::boost::concept::traits::result_type_of<F(Args...)>
            >
          , ::boost::concept::traits::_detail::metafunction
            ::result_of_impl<F,Args...>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
//<-
#endif  // BOOST_NO_CXX11_VARIADIC_TEMPLATES
//->
}}}  // namespace boost::concept::traits
//]

#if defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct result_of_t : ::boost::result_of<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#if defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
#undef BOOST_CONCEPT_TRAITS_RESULT_OF_FUNCTION
#undef BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION_CONST
#undef BOOST_CONCEPT_TRAITS_RESULT_OF_MEMBER_FUNCTION
#endif

#endif  // include guard

