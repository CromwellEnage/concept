// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MERGEABLE_HEAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MERGEABLE_HEAP_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_heap.hpp>
#include <boost/concept/traits/introspection/member_function/has_merge.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

//[reference__is_mergeable_heap
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_mergeable_heap
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _bct_has_merge_<
                typename _std_remove_const_<T>::type
            >
          , _bct_is_heap_<T>
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_merge<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >
          , ::boost::concept::traits::is_heap<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

