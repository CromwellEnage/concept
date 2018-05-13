// Copyright (C) 2011-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_POINTER_OF_ACTUAL_OR_VALUE_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_POINTER_OF_ACTUAL_OR_VALUE_HPP

#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/add_pointer.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct pointer_of_value
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::add_pointer<
#else
      : ::std::add_pointer<
#endif
            typename ::boost::concept::traits::value_type_of<T>::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_pointer.hpp>
#include <boost/concept/traits/_detail/metafunction/pointer_of_actual.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct pointer_of_actual_or_value
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_pointer<T>
          , ::boost::concept::traits::_detail::metafunction
            ::pointer_of_actual<T>
          , ::boost::concept::traits::_detail::metafunction
            ::pointer_of_value<T>
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

