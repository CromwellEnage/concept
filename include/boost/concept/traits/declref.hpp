// Copyright (C) 2011-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_DECLREF_HPP
#define BOOST_CONCEPT_TRAITS_DECLREF_HPP

#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_lvalue_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__declref
namespace boost { namespace concept { namespace traits {

    template <typename T>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    typename _std_add_lvalue_reference_<T>::type declref() noexcept;
//<-
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
    typename ::boost::add_lvalue_reference<T>::type declref() BOOST_NOEXCEPT;
#else
    typename ::std::add_lvalue_reference<T>::type declref() BOOST_NOEXCEPT;
#endif
//->
}}}  // namespace boost::concept::traits
//]

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__declcref
namespace boost { namespace concept { namespace traits {

    template <typename T>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    typename _std_add_lvalue_reference_<
        typename _std_add_const_<
            typename _std_remove_reference_<T>::type
        >::type
    >::type declcref() noexcept;
//<-
#elif defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
    typename ::boost::add_lvalue_reference<
        typename ::boost::add_const<
            typename ::boost::remove_reference<T>::type
        >::type
    >::type declcref() BOOST_NOEXCEPT;
#else
    typename ::std::add_lvalue_reference<
        typename ::std::add_const<
            typename ::std::remove_reference<T>::type
        >::type
    >::type declcref() BOOST_NOEXCEPT;
#endif
//->
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

