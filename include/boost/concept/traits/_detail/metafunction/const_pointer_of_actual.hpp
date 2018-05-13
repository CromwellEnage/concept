// Copyright (C) 2011-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_CONST_POINTER_OF_ACTUAL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_CONST_POINTER_OF_ACTUAL_HPP

#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct const_pointer_of_actual
    {
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        typedef typename ::boost::remove_const<T>::type::const_pointer type;
#else
        typedef typename ::std::remove_const<T>::type::const_pointer type;
#endif
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

