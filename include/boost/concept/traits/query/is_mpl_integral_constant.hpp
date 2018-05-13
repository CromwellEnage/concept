// Copyright (C) 2005-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_INTEGRAL_CONSTANT_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_INTEGRAL_CONSTANT_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_mpl_static_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/is_value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_mpl_integral_constant
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_mpl_integral_constant
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _bct_is_value_type_of_<bool,T>
          , _mpl_false_
          , _bct_is_mpl_static_constant_<T>
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_value_type_of<bool,T>
          , ::boost::mpl::false_
          , ::boost::concept::traits::is_mpl_static_constant<T>
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

