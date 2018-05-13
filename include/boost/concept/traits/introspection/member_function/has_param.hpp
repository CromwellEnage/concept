// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_PARAM_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_PARAM_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_param_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_KEYWORD(
                (::boost::concept::traits::declcref<T>().param)()
            )
#else
          , decltype((::boost::concept::traits::declcref<T>().param)())
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

    template <typename T>
    class has_param
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
                        (::boost::concept::traits::declcref<B>().param)()
                    )
#else
                    decltype(
                        (::boost::concept::traits::declcref<B>().param)()
                    )
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_param<T>::BOOST_NESTED_TEMPLATE
                _check<T>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/is_param_type_of.hpp>
#include <boost/mpl/if.hpp>

//[reference__has_param
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_param
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(_bct_declcref_<T>().param())
          , _mpl_apply1_<
                ResultPlaceholderExpr
              , _decltype_(_bct_declcref_<T>().param())
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_param<T>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_param_impl<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

