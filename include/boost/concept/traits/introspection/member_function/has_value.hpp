// Copyright (C) 2016-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_VALUE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_VALUE_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_value_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD(::boost::declref<T>().value())
#else
          , decltype(::boost::declref<T>().value())
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/add_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_value_default
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
#if !defined BOOST_NO_CXX11_DECLTYPE
            typename ::boost::add_reference<
#endif
#else   // !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::mpl::if_<
            ::std::is_same<
#if !defined BOOST_NO_CXX11_DECLTYPE
                typename ::std::add_lvalue_reference<
#endif
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    typename ::boost::concept::traits::value_type_of<T>::type
#if defined BOOST_NO_CXX11_DECLTYPE
              , BOOST_TYPEOF_KEYWORD(::boost::declref<T>().value())
#else
                >::type
              , decltype(::boost::declref<T>().value())
#endif
            >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/use_default.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_void.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_value_impl<T,::boost::concept::traits::use_default>
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_void<
#else
            ::std::is_void<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                BOOST_TYPEOF_KEYWORD(::boost::declref<T>().value())
#else
                decltype(::boost::declref<T>().value())
#endif
            >
          , ::boost::mpl::false_
          , ::boost::concept::traits::_detail::metafunction
            ::has_value_default<T>
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_value
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
                    BOOST_TYPEOF_KEYWORD(::boost::declref<B>().value())
#else
                    decltype(::boost::declref<B>().value())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_value<T>::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>

//[reference__has_value
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_value
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _is_valid_expression_(_declref_<T>().value())
          , _mpl_eval_if_<
                _std_is_same_<
                    ResultPlaceholderExpr
                  , boost::concept::traits::use_default
                >
              , _mpl_eval_if_<
                    _std_is_void_<
                        _decltype_(_declref_<T>().value())
                    >
                  , _mpl_false_
                  , _mpl_if_<
                        _std_is_same_<
                            typename _std_add_lvalue_reference_<
                                typename _bct_value_type_of_<T>::type
                            >::type
                          , _decltype_(_declref_<T>().value())
                        >
                      , _mpl_true_
                      , _mpl_false_
                    >
                >
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(_declref_<T>().value())
                >
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_value<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_value_impl<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

