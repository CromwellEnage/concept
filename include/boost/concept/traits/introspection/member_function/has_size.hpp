// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_SIZE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_SIZE_HPP

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
    struct has_size_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (::boost::declcref<T>().size(::boost::declval<Param>()))
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_size_impl<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    > : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD(::boost::declcref<T>().size())
#else
          , decltype(::boost::declcref<T>().size())
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param>
    class has_size
    {
        template <typename B, typename U>
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
                    (::boost::declcref<B>().size(::boost::declval<U>()))
                >::type
            );

        template <typename B, typename U>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_size<T,Param>
                        ::_check<T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T>
    class has_size<T,::boost::concept::policy::use_default>
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
                    BOOST_TYPEOF_KEYWORD(::boost::declcref<B>().size())
#else
                    decltype(::boost::declcref<B>().size())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_size<T,::boost::concept::policy::use_default>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
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
    struct has_size_std
      : ::boost::mpl::if_<
            typename ::boost::concept::traits::_detail::metafunction
            ::has_size<T,Param>::type
          , ::boost::concept::traits::_detail::metafunction
            ::has_size_impl<T,Param,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    class has_size_ptr_container
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

#if defined BOOST_NO_CXX11_DECLTYPE
        typedef BOOST_TYPEOF_KEYWORD(::boost::declref<_mutable_T>().base())
#else
        typedef decltype(::boost::declref<_mutable_T>().base())
#endif
                _Base;

     public:
        typedef typename ::boost::mpl::if_<
                    typename ::boost::concept::traits::_detail::metafunction
                    ::has_size<_Base,Param>::type
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_size_impl<_Base,Param,ResultPlaceholderExpr>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/is_size_type_of.hpp>
#include <boost/concept/traits/query/is_ptr_container.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__has_size
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_size
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _std_is_same_<Param,boost::concept::policy::use_default>
          , _mpl_eval_if_<
                _is_valid_expression_(_declcref_<T>().size())
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(_declcref_<T>().size())
                >
              , _mpl_false_
            >
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _declcref_<T>().size(_declval_<Param>())
                )
              , _mpl_apply1_<
                    ResultPlaceholderExpr
                  , _decltype_(
                        _declcref_<T>().size(_declval_<Param>())
                    )
                >
              , _mpl_false_
            >
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_ptr_container<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_size_ptr_container<T,Param,ResultPlaceholderExpr>
          , ::boost::concept::traits::_detail::metafunction
            ::has_size_std<T,Param,ResultPlaceholderExpr>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

