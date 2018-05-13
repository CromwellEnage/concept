// Copyright (C) 2017-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_BITMASK_TYPE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_BITMASK_TYPE_HPP

#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/type_traits/declval.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_bitmask_operable_impl
      : ::boost::concept::traits::is_boolean_expression<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD(
                (::boost::declval<T>() & ::boost::declval<T>()) != 0
            )
#else
          , decltype((::boost::declval<T>() & ::boost::declval<T>()) != 0)
#endif
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_bitwise_and_assignable.hpp>
#include <boost/concept/traits/query/is_bitwise_or_assignable.hpp>
#include <boost/concept/traits/query/is_bitwise_xor_assignable.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_bitmask_operators
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
                    BOOST_TYPEOF_KEYWORD(
                        (::boost::declval<B>() & ::boost::declval<B>()) != 0
                    )
#else
                    decltype(
                        (::boost::declval<B>() & ::boost::declval<B>()) != 0
                    )
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::eval_if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_bitmask_operators<T>
                ::BOOST_NESTED_TEMPLATE _check<T>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_bitwise_and_assignable<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_bitwise_or_assignable<T>
                  , ::boost::mpl::if_<
                        ::boost::concept::traits::is_bitwise_xor_assignable<T>
                      , ::boost::concept::traits::_detail::metafunction
                        ::is_bitmask_operable_impl<T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_complementable.hpp>
#include <boost/concept/traits/query/is_bitwise_and_operable.hpp>
#include <boost/concept/traits/query/is_bitwise_or_operable.hpp>
#include <boost/concept/traits/query/is_bitwise_xor_operable.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__is_math_real_type
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_bitmask_type
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_bitwise_and_assignable_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_eval_if_<
                _bct_is_bitwise_or_assignable_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                >
              , _mpl_eval_if_<
                    _bct_is_bitwise_xor_assignable_<
                        typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type
                    >
                  , _mpl_eval_if_<
                        _bct_is_bitwise_and_operable_<T>
                      , _mpl_eval_if_<
                            _bct_is_bitwise_or_operable_<T>
                          , _mpl_eval_if_<
                                _bct_is_bitwise_xor_operable_<T>
                              , _mpl_eval_if_<
                                    _bct_is_complementable_<T>
                                  , _mpl_if_<
                                        _is_valid_expression_(
                                            (
                                                _declval_<
                                                    T
                                                >() & _declval_<T>()
                                            ) != 0
                                        )
                                      , _bct_is_boolean_expression_<
                                            _decltype_(
                                                (
                                                    _declval_<
                                                        T
                                                    >() & _declval_<T>()
                                                ) != 0
                                            )
                                        >
                                      , _mpl_false_
                                    >
                                  , _mpl_false_
                                >
                              , _mpl_false_
                            >
                          , _mpl_false_
                        >
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::has_bitmask_operators<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_complementable<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_bitwise_and_operable<T>
                  , ::boost::mpl::if_<
                        ::boost::concept::traits::is_bitwise_or_operable<T>
                      , ::boost::concept::traits::is_bitwise_xor_operable<T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
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

