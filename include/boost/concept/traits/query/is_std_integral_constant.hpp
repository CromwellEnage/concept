// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_STD_INTEGRAL_CONSTANT_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_STD_INTEGRAL_CONSTANT_HPP

#include <boost/concept/traits/introspection/nested_type/is_value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_std_integral_constant_value
      : ::boost::mpl::if_<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_convertible<
#else
            ::std::is_convertible<
#endif
                T
#if defined(BOOST_NO_CXX11_DECLTYPE)
              , BOOST_TYPEOF_TPL(T::value)
#else
              , decltype(T::value)
#endif
            >
          , ::boost::concept::traits::is_value_type_of<
#if defined(BOOST_NO_CXX11_DECLTYPE)
                BOOST_TYPEOF_TPL(T::value)
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<decltype(T::value)>::type
#else
                typename ::std::remove_const<decltype(T::value)>::type
#endif
              , T
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_std_integral_constant_impl
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
                    BOOST_TYPEOF_TPL(B::value)
#else
                    decltype(B::value)
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::is_std_integral_constant_impl<T>::BOOST_NESTED_TEMPLATE
                _check<T>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::concept::traits::_detail::metafunction
            ::has_std_integral_constant_value<T>
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__is_std_integral_constant
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_std_integral_constant
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(
                _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type::value
            )
          , _mpl_if_<
                _std_is_convertible_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                  , _decltype_(
                        _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type::value
                    )
                >
              , _bct_is_value_type_of_<
                    _decltype_(
                        _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type::value
                    )
                  , typename _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction
        ::is_std_integral_constant_impl<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            typename ::boost::remove_const<
                typename ::boost::remove_reference<T>::type
            >::type
#else
            typename ::std::remove_const<
                typename ::std::remove_reference<T>::type
            >::type
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

