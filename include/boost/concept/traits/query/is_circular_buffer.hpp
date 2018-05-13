// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_CIRCULAR_BUFFER_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_CIRCULAR_BUFFER_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_array_range.hpp>
#include <boost/concept/traits/introspection/member_function/has_capacity.hpp>
#include <boost/concept/traits/introspection/member_function/has_full.hpp>
#include <boost/concept/traits/introspection/member_function/has_reserve.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

//[reference__is_circular_buffer
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_circular_buffer
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_reserve_<
                typename _std_add_const_<T>::type
            >
          , _mpl_eval_if_<
                _bct_has_array_range_<T>
              , _mpl_if_<
                    _bct_has_capacity_<T>
                  , _bct_has_full_<T>
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_reserve<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_const<T>::type
#else
                typename ::std::add_const<T>::type
#endif
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_array_range<T>
              , ::boost::mpl::if_<
                    ::boost::concept::traits::has_capacity<T>
                  , ::boost::concept::traits::has_full<T>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

