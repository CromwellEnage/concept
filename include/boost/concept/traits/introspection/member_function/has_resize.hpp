// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_RESIZE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_RESIZE_HPP

#include <boost/cstdint.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Element, ::boost::uintmax_t Arity>
    class has_resize_impl;

    template <typename T, ::boost::uintmax_t Arity>
    class has_resize_with_value_type;
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/utility/declref.hpp>
#include <boost/utility/declval.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    class has_resize_impl<T,U,1>
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::declref<B>().resize(
                            ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                          , ::boost::declval<V>()
                        )
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_resize_impl<T,U,1>
                        ::_check<T,U>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T, typename U>
    class has_resize_impl<T,U,2>
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::declref<B>().resize(
                            ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                          , ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                          , ::boost::declval<V>()
                        )
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_resize_impl<T,U,2>
                        ::_check<T,U>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T>
    class has_resize_with_value_type<T,1>
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::declref<B>().resize(
                            ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                          , ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::value_type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_resize_with_value_type<T,1>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T>
    class has_resize_with_value_type<T,2>
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::declref<B>().resize(
                            ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                          , ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                          , ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::value_type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_resize_with_value_type<T,2>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Element, typename SizeArity>
    struct has_resize
      : ::boost::concept::traits::_detail::metafunction
        ::has_resize_impl<T,Element,SizeArity::value>
    {
    };

    template <typename T, typename SizeArity>
    struct has_resize<
        T
      , ::boost::concept::policy::use_default
      , SizeArity
    > : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_value_type<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_resize_with_value_type<T,SizeArity::value>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_size_type.hpp>

//[reference__has_resize
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U, typename SizeArity>
    struct has_resize
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_size_type_<T>
          , _mpl_eval_if_<
                _std_is_same_<U,boost::concept::policy::use_default>
              , _mpl_if_<
                    _bct_has_value_type_<T>
                  , _is_valid_expression_(
                        _declref_<T>().resize(
                            _declval_<
                                typename _std_remove_const_<T>::type
                                ::size_type
                            >()
                            // SizeArity::value determines number of
                            // instances of above argument.
                          , _declval_<
                                typename _std_remove_const_<T>::type
                                ::value_type
                            >()
                        )
                    )
                  , _mpl_false_
                >
              , _is_valid_expression_(
                    _declref_<T>().resize(
                        _declval_<
                            typename _std_remove_const_<T>::type::size_type
                        >()
                        // SizeArity::value determines number of
                        // instances of above argument.
                      , _declval_<U>()
                    )
                )
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_size_type<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_resize<T,U,SizeArity>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

