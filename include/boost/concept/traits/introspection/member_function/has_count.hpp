// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_COUNT_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_COUNT_HPP

#include <boost/utility/declref.hpp>
#include <boost/utility/declval.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_count_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (::boost::declcref<T>().count(::boost::declval<Param>()))
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/policy/use_default.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_count_impl<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (
                ::boost::declcref<T>().count(
                    ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        typename ::boost::remove_const<T>::type::key_type
#else
                        typename ::std::remove_const<T>::type::key_type
#endif
                    >()
                )
            )
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param>
    class has_count_expr
    {
        template <typename B, typename P>
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
                    (::boost::declcref<B>().count(::boost::declval<P>()))
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_count_expr<T,Param>
                        ::_check<T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_count
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_count_expr<T,Param>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_count_impl<T,Param,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >
    {
    };

    template <typename T, typename ResultPlaceholderExpr>
    struct has_count_default
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_count_expr<
                T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::remove_const<T>::type::key_type
#else
              , typename ::std::remove_const<T>::type::key_type
#endif
            >::type
          , ::boost::concept::traits::_detail::metafunction::has_count_impl<
                T
              , ::boost::concept::policy::use_default
              , ResultPlaceholderExpr
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_key_type.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_count<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_key_type<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_count_default<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/is_size_type_of.hpp>

//[reference__has_count
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_count
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_if_<
                _std_is_same_<Param,boost::concept::policy::use_default>
              , _bct_has_key_type_<T>
              , _mpl_true_
            >::type
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _declcref_<T>().count(
                        _declval_<
                            typename _mpl_if_<
                                _std_is_same_<
                                    Param
                                  , boost::concept::policy::use_default
                                >
                              , typename _std_remove_const_<T>::type
                                ::key_type
                              , Param
                            >::type
                        >()
                    )
                )
              , _mpl_eval_if_<
                    _std_is_same_<Param,boost::concept::policy::use_default>
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _declcref_<T>().count(
                                _declval_<
                                    typename _std_remove_const_<T>::type
                                    ::key_type
                                >()
                            )
                        )
                    >
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _declcref_<T>().count(_declval_<Param>())
                        )
                    >
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::concept::traits::_detail::metafunction
        ::has_count<T,Param,ResultPlaceholderExpr>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

