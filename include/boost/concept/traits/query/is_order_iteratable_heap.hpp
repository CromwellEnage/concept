// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ORDER_ITERATABLE_HEAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ORDER_ITERATABLE_HEAP_HPP

#include <boost/concept/traits/query/is_iteratable_heap.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_ordered_begin.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_ordered_end.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_order_iteratable_heap_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_iteratable_heap<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_ordered_begin<T const>
              , ::boost::concept::traits::has_ordered_end<T const>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

//[reference__is_order_iteratable_heap
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_order_iteratable_heap
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_iteratable_heap_<typename _std_remove_const_<T>::type>
          , _mpl_if_<
                _bct_has_ordered_begin_<typename _std_add_const_<T>::type>
              , _bct_has_ordered_end_<typename _std_add_const_<T>::type>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::concept::traits::_detail::metafunction
        ::is_order_iteratable_heap_impl<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            typename ::boost::remove_const<T>::type
#else
            typename ::std::remove_const<T>::type
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

