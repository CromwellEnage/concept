// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_LVALUE_ASSIGNABLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_LVALUE_ASSIGNABLE_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Value, typename ResultPlaceholderExpr>
    struct is_lvalue_assignable_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD(
                ::boost::concept::traits::declref<
                    T
                >() = ::boost::concept::traits::declref<Value>()
            )
#else
          , decltype(
                ::boost::concept::traits::declref<
                    T
                >() = ::boost::concept::traits::declref<Value>()
            )
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/policy/use_default.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_lvalue_assignable_impl<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::concept::traits::_detail::metafunction
        ::is_lvalue_assignable_impl<
            T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<
                typename ::boost::remove_reference<T>::type
            >::type
#else
          , typename ::std::add_const<
                typename ::std::remove_reference<T>::type
            >::type
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

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Value>
    class has_lvalue_assignment_operator
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::add_pointer<
#else
                typename ::std::add_pointer<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        ::boost::concept::traits::declref<
                            B
                        >() = ::boost::concept::traits::declref<V>()
                    )
#else
                    decltype(
                        ::boost::concept::traits::declref<
                            B
                        >() = ::boost::concept::traits::declref<V>()
                    )
#endif
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_lvalue_assignment_operator<T,Value>
                ::BOOST_NESTED_TEMPLATE
                _check<T,Value>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T>
    class has_lvalue_assignment_operator<
        T
      , ::boost::concept::policy::use_default
    > : public ::boost::concept::traits::_detail::metafunction
        ::has_lvalue_assignment_operator<
            T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , typename ::boost::add_const<
                typename ::boost::remove_reference<T>::type
            >::type
#else
          , typename ::std::add_const<
                typename ::std::remove_reference<T>::type
            >::type
#endif
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/is_convertible_to_cref_of.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_lvalue_assignable
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Value, typename ResultPlaceholderExpr>
    struct is_lvalue_assignable
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(
                _bct_declref_<T>() = _bct_declref_<
                    typename _mpl_if_<
                        _std_is_same_<
                            Value
                          , boost::concept::policy::use_default
                        >
                      , typename _std_add_const_<
                            typename _std_remove_reference_<T>::type
                        >::type
                      , Value
                    >::type
                >()
            )
          , _mpl_apply1_<
                ResultPlaceholderExpr
              , _decltype_(
                    _bct_declref_<T>() = _bct_declref_<
                        typename _mpl_if_<
                            _std_is_same_<
                                Value
                              , boost::concept::policy::use_default
                            >
                          , typename _std_add_const_<
                                typename _std_remove_reference_<T>::type
                            >::type
                          , Value
                        >::type
                    >()
                )
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_lvalue_assignment_operator<T,Value>::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_lvalue_assignable_impl<T,Value,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

