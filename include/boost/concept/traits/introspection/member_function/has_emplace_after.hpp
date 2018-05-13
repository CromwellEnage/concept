// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_EMPLACE_AFTER_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_EMPLACE_AFTER_HPP

#include <boost/utility/declref.hpp>
#include <boost/move/move.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

#if defined BOOST_NO_CXX11_VARIADIC_TEMPLATES
#include <boost/concept/traits/_detail/preprocessor/has_function_def.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEM_FUNC_HAS_EMPLACE_AF_SEQ(ns) \
        (ns)(has_emplace_after)(::boost::declref<B>().emplace_after) \
        (::boost::mpl::bool_)(BOOST_TYPEOF_KEYWORD)(::boost::add_pointer)(0) \
        //!
#else   // !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEM_FUNC_HAS_EMPLACE_AF_SEQ(ns) \
        (ns)(has_emplace_after)(::boost::declref<B>().emplace_after) \
        (::boost::mpl::bool_)(BOOST_TYPEOF_KEYWORD)(::std::add_pointer)(0) \
        //!
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS
#else   // !defined BOOST_NO_CXX11_DECLTYPE
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEM_FUNC_HAS_EMPLACE_AF_SEQ(ns) \
        (ns)(has_emplace_after)(::boost::declref<B>().emplace_after) \
        (::boost::mpl::bool_)(decltype)(::boost::add_pointer)(0) \
        //!
#else   // !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEM_FUNC_HAS_EMPLACE_AF_SEQ(ns) \
        (ns)(has_emplace_after)(::boost::declref<B>().emplace_after) \
        (::boost::mpl::bool_)(decltype)(::std::add_pointer)(0) \
        //!
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS
#endif  // BOOST_NO_CXX11_DECLTYPE
#else   // !defined BOOST_NO_CXX11_VARIADIC_TEMPLATES
#include <boost/utility/declval.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#endif  // BOOST_NO_CXX11_VARIADIC_TEMPLATES

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

#if defined BOOST_NO_CXX11_VARIADIC_TEMPLATES
    BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF(
        BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
      , BOOST_CONCEPT_TRAITS_INTROSPECTION_MEM_FUNC_HAS_EMPLACE_AF_SEQ(
            ::boost::concept::traits::_detail::metafunction::
        )
    )
    BOOST_PP_REPEAT(
        BOOST_PP_DEC(BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT)
      , BOOST_CONCEPT_TRAITS__DETAIL_HAS_FUNCTION_DEF_Z
      , BOOST_CONCEPT_TRAITS_INTROSPECTION_MEM_FUNC_HAS_EMPLACE_AF_SEQ(
            ::boost::concept::traits::_detail::metafunction::
        )
    )
#else  // !defined BOOST_NO_CXX11_VARIADIC_TEMPLATES
    template <typename T, typename... Args>
    class has_emplace_after
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
                    BOOST_TYPEOF_TPL
#else
                    decltype
#endif
                    ((
                        ::boost::declref<B>().emplace_after(
                            ::boost::forward<Args>(
                                ::boost::declval<Args>()
                            )...
                        )
                    ))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_emplace_after<T,Args...>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
#endif  // BOOST_NO_CXX11_VARIADIC_TEMPLATES
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined BOOST_NO_CXX11_VARIADIC_TEMPLATES
#undef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEM_FUNC_HAS_EMPLACE_AF_SEQ
#endif

#include <boost/concept/traits/introspection/member_function_fwd.hpp>

//[reference__has_emplace_after
namespace boost { namespace concept { namespace traits {

//<-
#if defined BOOST_NO_CXX11_VARIADIC_TEMPLATES
    template <
        typename T
        BOOST_PP_ENUM_TRAILING_PARAMS(
            BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
          , typename P
        )
    >
#else
//->
    template <typename T, typename... Args>
//<-
#endif
//->
    struct has_emplace_after
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _is_valid_expression_(
            _declref_<T>.emplace_after(
                _forward_<Args>(_declval_<Args>())...
            )
        )
//<-
#elif defined BOOST_NO_CXX11_VARIADIC_TEMPLATES
      : ::boost::concept::traits::_detail::metafunction::has_emplace_after<
            T
            BOOST_PP_ENUM_TRAILING_PARAMS(
                BOOST_CONCEPT_TRAITS_VARIADIC_ARG_COUNT
              , P
            )
        >::type
#else
      : ::boost::concept::traits::_detail::metafunction
        ::has_emplace_after<T,Args...>::type
#endif
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

