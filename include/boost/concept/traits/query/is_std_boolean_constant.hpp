// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_STD_BOOLEAN_CONSTANT_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_STD_BOOLEAN_CONSTANT_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_std_integral_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/is_value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_std_boolean_constant
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_std_boolean_constant
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _bct_is_std_integral_constant_<T>
          , _bct_is_value_type_of_<bool,T>
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_std_integral_constant<T>
          , ::boost::concept::traits::is_value_type_of<bool,T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

