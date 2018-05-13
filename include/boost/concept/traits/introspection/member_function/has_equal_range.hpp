// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_EQUAL_RANGE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_EQUAL_RANGE_HPP

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
    struct has_equal_range_imp0
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (::boost::declref<T>().equal_range(::boost::declval<Param>()))
        >::type
    {
    };

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_equal_range_impl
      : ::boost::concept::traits::_detail::metafunction
        ::has_equal_range_imp0<T,Param,ResultPlaceholderExpr>
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_range.hpp>
#include <boost/concept/traits/introspection/nested_type/is_iterator_of.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/placeholders.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param>
    struct has_equal_range_imp0<
        T
      , Param
      , ::boost::concept::policy::use_default
    > : ::boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF_KEYWORD
#else
            decltype
#endif
            (::boost::declref<T>().equal_range(::boost::declval<Param>()))
          , ::boost::concept::traits::is_iterator_of< ::boost::mpl::_,T>
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_equal_range_impl<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::concept::traits::_detail::metafunction::has_equal_range_imp0<
            T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , typename ::boost::remove_const<T>::type::key_type
#else
          , typename ::std::remove_const<T>::type::key_type
#endif
          , ResultPlaceholderExpr
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
    class has_equal_range_expr
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
                    (
                        ::boost::declref<B>().equal_range(
                            ::boost::declval<P>()
                        )
                    )
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_equal_range_expr<T,Param>
                        ::_check<T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_equal_range
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_equal_range_expr<T,Param>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_equal_range_impl<T,Param,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
    {
    };

    template <typename T, typename ResultPlaceholderExpr>
    struct has_equal_range_with_default_param
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_equal_range_expr<
                T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::remove_const<T>::type::key_type
#else
              , typename ::std::remove_const<T>::type::key_type
#endif
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_equal_range_impl<
                T
              , ::boost::concept::policy::use_default
              , ResultPlaceholderExpr
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_key_type.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_equal_range<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::if_<
            ::boost::concept::traits::has_key_type<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_equal_range_with_default_param<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>

//[reference__has_equal_range
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_equal_range
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
                    _declref_<T>().equal_range(
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
                            _declref_<T>().equal_range(
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
                            _declref_<T>().equal_range(
                                _declval_<Param>()
                            )
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
        ::has_equal_range<T,Param,ResultPlaceholderExpr>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

