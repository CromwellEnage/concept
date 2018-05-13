// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_FREE_FUNCTION_FWD_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_FREE_FUNCTION_FWD_HPP

#include <boost/concept/policy/use_default.hpp>

//[reference__has_source__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_source;
}}}  // namespace boost::concept::traits
//]

//[reference__has_target__fwd
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename Param = ::boost::concept::policy::use_default
      , typename ResultPlaceholderExpr = ::boost::concept::policy::use_default
    >
    struct has_target;
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

