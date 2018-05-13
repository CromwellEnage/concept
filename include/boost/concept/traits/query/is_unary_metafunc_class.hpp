// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_UNARY_METAFUNC_CLASS_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_UNARY_METAFUNC_CLASS_HPP

#include <boost/mpl/apply.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct eval_unary_metafunction_class
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
          , typename ::boost::mpl::apply1<T,Param>::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename Expr>
    struct is_unary_metafunction_class_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_type<
                typename T::BOOST_NESTED_TEMPLATE apply<Param>
            >
          , ::boost::concept::traits::_detail::metafunction
            ::eval_unary_metafunction_class<T,Param,Expr>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/utility/declval.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename Expr>
    class is_unary_metafunction_class
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

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
                        ::boost::declval<
                            typename B::BOOST_NESTED_TEMPLATE apply<P>
                        >()
                    )
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::is_unary_metafunction_class<T,Param,Expr>
                        ::_check<_mutable_T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_unary_metafunction_class_impl<_mutable_T,Param,Expr>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_template/has_apply.hpp>

//[reference__is_unary_metafunction_class
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct is_unary_metafunction_class
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_apply_<T>
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _declval_<
                        typename _std_remove_const_<T>::template apply<Param>
                    >()
                )
              , _mpl_eval_if_<
                    _bct_has_type_<
                        typename _std_remove_const_<T>::template apply<Param>
                    >
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , typename _mpl_apply1_<T,Param>::type
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_apply<T>
          , ::boost::concept::traits::_detail::metafunction
            ::is_unary_metafunction_class<T,Param,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

