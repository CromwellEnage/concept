// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_POINTER_OF_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_POINTER_OF_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_mutable_pointer_of
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<typename T2::pointer,T1>
#else
      : ::boost::mpl::if_<
            ::std::is_same<typename T2::pointer,T1>
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_const_pointer_of
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
            typename ::boost::remove_const<T2>::type::const_pointer
#else
      : ::boost::mpl::if_<
            ::std::is_same<
                typename ::std::remove_const<T2>::type::const_pointer
#endif
              , T1
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

#include <boost/concept/traits/introspection_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_pointer.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_reference.hpp>
#endif

//[reference__is_pointer_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_pointer_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_pointer_<T2>
          , _mpl_eval_if_<
                _std_is_const_<T2>
              , _mpl_if_<
                    _std_is_same_<
                        typename _std_remove_const_<T2>::type
                        ::const_reference
                      , T1
                    >
                  , _mpl_true_
                  , _mpl_false_
                >
              , _mpl_if_<
                    _std_is_same_<typename T2::reference,T1>
                  , _mpl_true_
                  , _mpl_false_
                >
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::concept::traits::has_pointer<T2>
          , ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_const<T2>
#else
                ::std::is_const<T2>
#endif
              , ::boost::concept::traits::_detail::metafunction
                ::is_const_reference_of<T1,T2>
              , ::boost::concept::traits::_detail::metafunction
                ::is_mutable_reference_of<T1,T2>
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

