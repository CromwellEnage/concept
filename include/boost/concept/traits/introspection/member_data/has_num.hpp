// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_DATA_HAS_NUM_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_MEMBER_DATA_HAS_NUM_HPP

#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename PlaceholderExpr>
    struct has_num_impl
      : ::boost::mpl::apply1<
            PlaceholderExpr
#if defined(BOOST_NO_CXX11_DECLTYPE)
          , BOOST_TYPEOF_TPL(T::num)
#else
          , decltype(T::num)
#endif
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/tti/detail/dnullptr.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename PlaceholderExpr>
    class has_num
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
                    BOOST_TYPEOF_TPL(B::num)
#else
                    decltype(B::num)
#endif
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef typename ::boost::mpl::if_c<
            sizeof(
                ::boost::concept::traits::_detail::metafunction
                ::has_num<T,PlaceholderExpr>::BOOST_NESTED_TEMPLATE
                _check<T>(BOOST_TTI_DETAIL_NULLPTR)
            ) == sizeof(::boost::type_traits::yes_type)
          , ::boost::concept::traits::_detail::metafunction
            ::has_num_impl<T,PlaceholderExpr>
          , ::boost::mpl::false_
        >::type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_data_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/is_num_type_of.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__has_num
namespace boost { namespace concept { namespace traits {

    template <typename T, typename PlaceholderExpr>
    struct has_num
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _is_valid_expression_(
                _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type::num
            )
          , _mpl_apply1_<
                PlaceholderExpr
              , _decltype_(
                    _std_remove_const_<
                        typename _std_remove_reference_<T>::type
                    >::type::num
                )
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::has_num<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            typename ::boost::remove_const<
                typename ::boost::remove_reference<T>::type
            >::type
#else
            typename ::std::remove_const<
                typename ::std::remove_reference<T>::type
            >::type
#endif
          , PlaceholderExpr
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

