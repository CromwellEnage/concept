// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_PUSH_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_PUSH_HPP

#include <boost/utility/declref.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#if !defined BOOST_NO_CXX11_DECLTYPE
#include <boost/type_traits/remove_reference.hpp>
#endif
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_push_expr
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
                    (
                        ::boost::declref<B>().push(
                            ::boost::declcref<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::value_type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _chk(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_push_expr<T>::_chk<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__has_push
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_push
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _bct_has_value_type_<T>
          , _is_valid_expression_(
                _declref_<T>().push(
                    _declcref_<
                        typename _std_remove_const_<T>::type::value_type
                    >()
                )
            )
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_value_type<T>
          , ::boost::concept::traits::_detail::metafunction::has_push_expr<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

