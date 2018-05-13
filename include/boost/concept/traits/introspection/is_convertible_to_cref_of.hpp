// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_IS_CONVERTIBLE_TO_CREF_OF_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_IS_CONVERTIBLE_TO_CREF_OF_HPP

#include <boost/concept/traits/introspection_fwd.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <type_traits>
#endif

//[reference__is_convertible_to_cref_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_convertible_to_cref_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _std_is_convertible_<
                T1
              , typename _std_add_lvalue_reference_<
                    typename _std_add_const_<
                        typename _std_remove_reference_<T2>::type
                    >::type
                >::type
            >
          , _mpl_true_
          , _mpl_false_
        >::type
//<-
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_convertible<
            T1
          , typename ::boost::add_lvalue_reference<
                typename ::boost::add_const<
                    typename ::boost::remove_reference<T2>::type
                >::type
            >::type
        >
#else   // !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::mpl::if_<
            ::std::is_convertible<
                T1
              , typename ::std::add_lvalue_reference<
                    typename ::std::add_const<
                        typename ::std::remove_reference<T2>::type
                    >::type
                >::type
            >
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION, BOOST_NO_CXX11_HDR_TYPE_TRAITS
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

