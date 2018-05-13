// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_BINARY_FUNCTION_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_BINARY_FUNCTION_HPP

#include <boost/mpl/apply.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
      , typename FirstArgument
      , typename SecondArgument
      , typename ResultPlaceholderExpr
    >
    struct is_binary_function_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD((
                ::boost::declval<T>()(
                    ::boost::declval<FirstArgument>()
                  , ::boost::declval<SecondArgument>()
                )
            ))
#else
          , decltype(
                ::boost::declval<T>()(
                    ::boost::declval<FirstArgument>()
                  , ::boost::declval<SecondArgument>()
                )
            )
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename FirstArg, typename SecondArg>
    class is_binary_func_expr
    {
        template <typename B, typename A1, typename A2>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD((
                        ::boost::declval<B>()(
                            ::boost::declval<A1>()
                          , ::boost::declval<A2>()
                        )
                    ))
#else
                    decltype(
                        ::boost::declval<B>()(
                            ::boost::declval<A1>()
                          , ::boost::declval<A2>()
                        )
                    )
#endif
                >::type
            );

        template <typename B, typename A1, typename A2>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::is_binary_func_expr<T,FirstArg,SecondArg>
                ::BOOST_NESTED_TEMPLATE
                _check<T,FirstArg,SecondArg>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_binary_function
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename FirstArgument
      , typename SecondArgument
      , typename ResultPlaceholderExpr
    >
    struct is_binary_function
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(
                _declval_<T>()(
                    _declval_<FirstArgument>()
                  , _declval_<SecondArgument>()
                )
            )
          , _mpl_apply1_<
                ResultPlaceholderExpr
              , _decltype_(
                     _declval_<T>()(
                          _declval_<FirstArgument>()
                        , _declval_<SecondArgument>()
                     )
                )
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_binary_func_expr<T,FirstArgument,SecondArgument>::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_binary_function_impl<
                T
              , FirstArgument
              , SecondArgument
              , ResultPlaceholderExpr
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

