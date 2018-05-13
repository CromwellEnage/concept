// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_GET_FINISH_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_GET_FINISH_HPP

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
    struct has_get_finish_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (::boost::declref<T>().get_finish(::boost::declval<Param>()))
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
    struct has_get_finish_impl<
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
                ::boost::declref<T>().get_finish(
                    ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                        typename ::boost::remove_const<T>::type::index
#else
                        typename ::std::remove_const<T>::type::index
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
    class has_get_finish_expr
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
                    (::boost::declref<B>().get_finish(::boost::declval<P>()))
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_get_finish_expr<T,Param>
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
    struct has_get_finish
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_get_finish_expr<T,Param>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_get_finish_impl<T,ResultPlaceholderExpr,Param>
          , ::boost::mpl::false_
        >
    {
    };

    template <typename T, typename ResultPlaceholderExpr>
    struct has_get_finish_default
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_get_finish_expr<
                T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::remove_const<T>::type::index
#else
              , typename ::std::remove_const<T>::type::index
#endif
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_get_finish_impl<
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

#include <boost/concept/traits/introspection/nested_type/has_index.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_get_finish<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_index<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_get_finish_default<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/is_index_of.hpp>

//[reference__has_get_finish
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_get_finish
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            typename _mpl_if_<
                _std_is_same_<Param,boost::concept::policy::use_default>
              , _bct_has_index_<T>
              , _mpl_true_
            >::type
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _declref_<T>().get_finish(
                        _declval_<
                            typename _mpl_if_<
                                _std_is_same_<
                                    Param
                                  , boost::concept::policy::use_default
                                >
                              , typename _std_remove_const_<T>::type
                                ::index
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
                            _declref_<T>().get_finish(
                                _declval_<
                                    typename _std_remove_const_<T>::type
                                    ::index
                                >()
                            )
                        )
                    >
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _declref_<T>().get_finish(
                                _declval_<Param>()
                            )
                        )
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::concept::traits::_detail::metafunction
        ::has_get_finish<T,Param,ResultPlaceholderExpr>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

