// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ITERATABLE_HEAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ITERATABLE_HEAP_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_heap.hpp>
#include <boost/concept/traits/query/is_range.hpp>
#include <boost/mpl/and.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

//[reference__is_iteratable_heap
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_iteratable_heap
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_and_<
            _bct_is_heap_<T>
          , _bct_is_range_<typename _std_add_const_<T>::type>
        >
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::and_<
            ::boost::concept::traits::is_heap<T>
          , ::boost::concept::traits::is_range<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_const<T>::type
#else
                typename ::std::add_const<T>::type
#endif
            >
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

