// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ERASE_ELEMENT_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_FUNCTION_HAS_ERASE_ELEMENT_HPP

#include <boost/cstdint.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, ::boost::uintmax_t Arity>
    class has_erase_element_impl;
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/utility/declref.hpp>
#include <boost/utility/declval.hpp>
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
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class has_erase_element_impl<T,1>
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
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::declref<B>().erase_element(
                            ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_erase_element_impl<T,1>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T>
    class has_erase_element_impl<T,2>
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
                    BOOST_TYPEOF_KEYWORD
#else
                    decltype
#endif
                    (
                        ::boost::declref<B>().erase_element(
                            ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                          , ::boost::declval<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                                typename ::boost::remove_const<B>::type
#else
                                typename ::std::remove_const<B>::type
#endif
                                ::size_type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
                    sizeof(
                        ::boost::concept::traits::_detail::metafunction
                        ::has_erase_element_impl<T,2>
                        ::_check<T>(BOOST_TTI_DETAIL_NULLPTR)
                    ) == sizeof(::boost::type_traits::yes_type)
                >
                type;
    };

    template <typename T, typename SizeArity>
    struct has_erase_element
      : ::boost::concept::traits::_detail::metafunction
        ::has_erase_element_impl<T,SizeArity::value>
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_size_type.hpp>

//[reference__has_erase_element
namespace boost { namespace concept { namespace traits {

    template <typename T, typename SizeArity>
    struct has_erase_element
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _bct_has_size_type_<T>
          , _is_valid_expression_(
                _declref_<T>().erase_element(
                    _declval_<
                        typename _std_remove_const_<T>::type::size_type
                    >()
                    // SizeArity::value determines number of
                    // instances of above argument.
                )
            )
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_size_type<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_erase_element<T,SizeArity>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

