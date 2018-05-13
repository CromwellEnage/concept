// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_RESERVE_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_RESERVE_HPP

#include <boost/utility/declref.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_reserve0_impl
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
#if defined BOOST_NO_CXX11_DECLTYPE
          , BOOST_TYPEOF_KEYWORD(::boost::declref<T>().reserve())
#else
          , decltype(::boost::declref<T>().reserve())
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/is_size_type_of.hpp>
#include <boost/concept/policy/use_default.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_reserve0_impl<T,::boost::concept::policy::use_default>
      : ::boost::concept::traits::is_size_type_of<
#if defined BOOST_NO_CXX11_DECLTYPE
            BOOST_TYPEOF_KEYWORD(::boost::declref<T>().reserve())
#else
            decltype(::boost::declref<T>().reserve())
#endif
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

    template <typename T, typename ResultPlaceholderExpr>
    class has_reserve0
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
                    BOOST_TYPEOF_KEYWORD(::boost::declref<B>().reserve())
#else
                    decltype(::boost::declref<B>().reserve())
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_reserve0<T,ResultPlaceholderExpr>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_reserve0_impl<T,ResultPlaceholderExpr>
                  , ::boost::mpl::false_
                >::type
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/utility/declval.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename U>
    class has_reserve1
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _chk(
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
                    (::boost::declref<B>().reserve(::boost::declval<U>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _chk(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_reserve1<T,U>::_chk<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T>
    struct has_reserve1_default
      : public ::boost::concept::traits::_detail::metafunction
        ::has_reserve1<T,typename T::size_type>::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_size_type.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_reserve1<T,::boost::concept::policy::use_default>
      : public ::boost::mpl::if_<
            ::boost::concept::traits::has_size_type<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_reserve1_default<T>
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#endif

//[reference__has_reserve
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U>
    struct has_reserve
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _std_is_const_<T>
          , _mpl_eval_if_<
                _is_valid_expression_(_declref_<T>().reserve())
              , _mpl_eval_if_<
                    _std_is_same_<U,boost::concept::policy::use_default>
                  , _bct_is_size_type_of_<
                        _decltype_(_declref_<T>().reserve())
                      , T
                    >
                  , _mpl_apply1_<
                        U
                      , _decltype_(_declref_<T>().reserve())
                    >
                >
              , _mpl_false_
            >
          , _mpl_eval_if_<
                _std_is_same_<U,boost::concept::policy::use_default>
              , _mpl_if_<
                    _bct_has_size_type_<T>
                  , _is_valid_expression_(
                        _declref_<T>().reserve(
                            _declval_<typename T::size_type>()
                        )
                    )
                  , _mpl_false_
                >
              , _is_valid_expression_(
                    _declref_<T>().reserve(_declval_<T>())
                )
            >
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_const<T>
#else
            ::std::is_const<T>
#endif
          , ::boost::concept::traits::_detail::metafunction::has_reserve0<T,U>
          , ::boost::concept::traits::_detail::metafunction::has_reserve1<T,U>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

