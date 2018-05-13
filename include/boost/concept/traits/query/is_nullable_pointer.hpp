// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_NULLABLE_POINTER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_NULLABLE_POINTER_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

#if defined(BOOST_NO_CXX11_NULLPTR)

#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/concept/traits/declref.hpp>
#include <boost/type_traits/declval.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#else
#include <boost/concept/traits/introspection/is_lvalue_reference_of.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_nullable_pointer_impl
      : ::boost::mpl::eval_if<
#if defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_same<
#else
            ::std::is_same<
#endif
                BOOST_TYPEOF_KEYWORD(
                    ::boost::concept::traits::declref<T>() = 0
                )
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
            ::boost::concept::traits::is_lvalue_reference_of<
                decltype(::boost::concept::traits::declref<T>() = 0)
#endif  // BOOST_NO_CXX11_DECLTYPE
              , T
            >
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_boolean_expression<
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(::boost::declval<T>() == 0)
#else
                    decltype(::boost::declval<T>() == 0)
#endif
                >
              , ::boost::concept::traits::is_boolean_expression<
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD(0 == ::boost::declval<T>())
#else
                    decltype(0 == ::boost::declval<T>())
#endif
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#endif

#else   // !defined(BOOST_NO_CXX11_NULLPTR)
#include <cstddef>
#endif  // BOOST_NO_CXX11_NULLPTR

#include <boost/concept/traits/query/is_lvalue_assignable.hpp>
#include <boost/concept/traits/query/is_equality_comparable.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _mutable_T = typename ::boost::remove_const<
            typename ::boost::remove_reference<T>::type
        >::type
#else
      , typename _mutable_T = typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
        >::type
#endif
    >
    class is_nullable_pointer
    {
#if defined(BOOST_NO_CXX11_NULLPTR)
        template <typename B>
        static ::boost::type_traits::yes_type
            _chk_eq_0(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(::boost::declval<B>() == 0)
#else
                    decltype(::boost::declval<B>() == 0)
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _chk_eq_0(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _chk_eq_1(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(0 == ::boost::declval<B>())
#else
                    decltype(0 == ::boost::declval<B>())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _chk_eq_1(...);

        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::concept::traits::declref<B>() = 0
                    )
#else
                    decltype(::boost::concept::traits::declref<B>() = 0)
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);
#endif  // BOOST_NO_CXX11_NULLPTR

     public:
#if defined(BOOST_NO_CXX11_NULLPTR)
        typedef typename ::boost::mpl::eval_if_c<
            (
                sizeof(
                    ::boost::concept::traits::_detail::metafunction
                    ::is_nullable_pointer<T>::BOOST_NESTED_TEMPLATE
                    _chk_eq_0<_mutable_T>(0)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::boost::concept::traits::_detail::metafunction
                    ::is_nullable_pointer<T>::BOOST_NESTED_TEMPLATE
                    _chk_eq_1<_mutable_T>(0)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::boost::concept::traits::_detail::metafunction
                    ::is_nullable_pointer<T>::BOOST_NESTED_TEMPLATE
                    _check<_mutable_T>(0)
                ) == sizeof(::boost::type_traits::yes_type)
            )
#else
        typedef typename ::boost::mpl::eval_if<
            ::boost::concept::traits
            ::is_lvalue_assignable<_mutable_T,::std::nullptr_t const>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits
                ::is_equality_comparable<T,::std::nullptr_t const>
#endif  // BOOST_NO_CXX11_NULLPTR
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_lvalue_assignable<_mutable_T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_nullable_pointer_impl<_mutable_T>
                  , ::boost::mpl::false_
                >
#if !defined(BOOST_NO_CXX11_NULLPTR)
              , ::boost::mpl::false_
            >
#endif
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>

//[reference__is_nullable_pointer
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_nullable_pointer
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
                _bct_is_equality_comparable_<T>
              , _mpl_if_<
                    _bct_is_lvalue_assignable_<
                        typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type
                      , _std_nullptr_t_ const
                    >
                  , _bct_is_equality_comparable_<
                        T
                      , _std_nullptr_t_ const
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_nullable_pointer<T>::type
          , ::boost::concept::traits::is_equality_comparable<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

