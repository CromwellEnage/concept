// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_FINISH_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_FINISH_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_finish_impl_0
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD(::boost::declref<T>().finish())
#else
          , decltype(::boost::declref<T>().finish())
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/utility/declval.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_finish_impl_1
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD
#else
          , decltype
#endif
            (::boost::declref<T>().finish(::boost::declval<Param>()))
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/is_index_of.hpp>
#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_finish_impl_0<T,::boost::concept::policy::use_default>
      : ::boost::concept::traits::is_index_of<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF_KEYWORD
#else
            decltype
#endif
            (::boost::declref<T>().finish())
          , T
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    class has_finish_impl
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
                        ::boost::declref<B>().finish(
                            ::boost::declval<P>()
                        )
                    )
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_finish_impl<T,Param,ResultPlaceholderExpr>
                        ::_check<T,Param>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_finish_impl_1<T,Param,ResultPlaceholderExpr>
                  , ::boost::mpl::false_
                >::type
                type;
    };

    template <typename T, typename ResultPlaceholderExpr>
    class has_finish_impl<
        T
      , ::boost::concept::policy::use_default
      , ResultPlaceholderExpr
    >
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
                    BOOST_TYPEOF_KEYWORD(::boost::declref<B>().finish())
#else
                    decltype(::boost::declref<B>().finish())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_finish_impl<
                            T
                          , ::boost::concept::policy::use_default
                          , ResultPlaceholderExpr
                        >::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_finish_impl_0<T,ResultPlaceholderExpr>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#endif
#else
#include <boost/concept/traits/introspection/is_raw_reference_of.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Param>
    struct has_finish_impl_1<T,Param,::boost::concept::policy::use_default>
#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
                BOOST_TYPEOF_KEYWORD
#else   // !defined BOOST_NO_CXX11_DECLTYPE
      : ::boost::concept::traits::is_raw_reference_of<
                decltype
#endif  // BOOST_NO_CXX11_DECLTYPE
                (::boost::declref<T>().finish(::boost::declval<Param>()))
              , T
            >
#if defined BOOST_NO_CXX11_DECLTYPE
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__has_finish
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_finish
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _std_is_same_<Param,boost::concept::policy::use_default>
          , _mpl_eval_if_<
                _is_valid_expression_(_declref_<T>().finish())
              , _mpl_eval_if_<
                    _std_is_same_<
                        ResultPlaceholderExpr
                      , boost::concept::policy::use_default
                    >
                  , _bct_is_index_of_<
                        _decltype_(_declref_<T>().finish())
                      , T
                    >
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(_declref_<T>().finish())
                    >
                >
              , _mpl_false_
            >
          , _mpl_eval_if_<
                _is_valid_expression_(
                    _declref_<T>().finish(_declval_<Param>())
                )
              , _mpl_eval_if_<
                    _std_is_same_<
                        ResultPlaceholderExpr
                      , boost::concept::policy::use_default
                    >
                  , _bct_is_raw_reference_of_<
                        _decltype_(
                            _declref_<T>().finish(
                                _declval_<Param>()
                            )
                        )
                      , T
                    >
                  , _mpl_apply1_<
                        ResultPlaceholderExpr
                      , _decltype_(
                            _declref_<T>().finish(
                                _declval_<Param>()
                            )
                        )
                    >
                >
              , _mpl_false_
            >
        >::type
//<-
#else
      : ::boost::concept::traits::_detail::metafunction
        ::has_finish_impl<T,Param,ResultPlaceholderExpr>::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

