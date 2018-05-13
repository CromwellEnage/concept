// Copyright (C) 2016-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_SIMPLE_NODE_HANDLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_SIMPLE_NODE_HANDLE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_get_allocator.hpp>
#include <boost/concept/traits/introspection/member_function/has_value.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_simple_node_handle
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_simple_node_handle
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _bct_has_get_allocator_<T>
          , _bct_has_value_<T>
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_get_allocator<T>
          , ::boost::concept::traits::has_value<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

