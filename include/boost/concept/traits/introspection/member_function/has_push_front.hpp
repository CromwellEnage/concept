// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_PUSH_FRONT_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_PUSH_FRONT_HPP

#include <boost/utility/declref.hpp>
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

    template <typename T>
    class has_std_push_front_expr
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
                        ::boost::declref<B>().push_front(
                            ::boost::declcref<
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
                        ::has_std_push_front_expr<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T>
    class has_ptr_push_front_expr
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
                        ::boost::declref<B>().push_front(
                            ::boost::declref<
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
                        ::has_ptr_push_front_expr<T>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#if !defined BOOST_NO_CXX11_DECLTYPE
#include <boost/type_traits/remove_reference.hpp>
#endif
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_ptr_push_front
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_push_front<
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD(
                    ::boost::declref<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        typename ::boost::remove_const<T>::type
#else
                        typename ::std::remove_const<T>::type
#endif
                    >().base()
                )
#else  // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<
#endif
                        decltype(
                            ::boost::declref<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<T>::type
#else
                                typename ::std::remove_const<T>::type
#endif
                            >().base()
                        )
                    >::type
                >::type
#endif  // BOOST_NO_CXX11_DECLTYPE
            >
          , ::boost::concept::traits::_detail::metafunction
            ::has_ptr_push_front_expr<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/member_function/has_front.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_ptr_container_members.hpp>

//[reference__has_push_front
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_push_front
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_front_<T>
          , _mpl_eval_if_<
                _bct_is_ptr_container_<T>
              , _mpl_eval_if_<
                    _is_valid_expression_(
                        _declref_<T>().push_front(
                            _declref_<
                                typename _std_remove_const_<T>::type
                                ::value_type
                            >()
                        )
                    )
                  , _is_valid_expression_(
                        _declref_<
                            typename _std_remove_const_<
                                typename _std_remove_reference_<
                                    _decltype_(
                                        _declref_<
                                            typename _std_remove_const_<
                                                T
                                            >::type
                                        >().base()
                                    )
                                >::type
                            >::type
                        >().base().push_front(
                            _declcref_<
                                typename _std_remove_const_<
                                    typename _std_remove_reference_<
                                        _decltype_(
                                            _declref_<
                                                typename _std_remove_const_<
                                                    T
                                                >::type
                                            >().base()
                                        )
                                    >::type
                                >::type::value_type
                            >()
                        )
                    )
                  , _mpl_false_
                >
              , _is_valid_expression_(
                    _declref_<T>().push_front(
                        _declcref_<
                            typename _std_remove_const_<T>::type
                            ::value_type
                        >()
                    )
                )
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_front<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::_detail::metafunction
                ::has_ptr_container_members<T>
              , ::boost::concept::traits::_detail::metafunction
                ::has_ptr_push_front<T>
              , ::boost::concept::traits::_detail::metafunction
                ::has_std_push_front_expr<T>
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

