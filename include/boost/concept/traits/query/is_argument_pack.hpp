// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ACCUMULATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ACCUMULATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_result_type.hpp>
#include <boost/accumulators/framework/accumulator_base.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

//[reference__is_accumulator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_accumulator
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _std_is_base_of_<
                _accumulator_base_
              , typename _std_remove_const_<T>::type
            >
          , _bct_has_result_type_<T>
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::if_<
#if defined BOOST_NO_CX11_HDR_TYPE_TRAITS
            ::boost::is_base_of<
#else
            ::std::is_base_of<
#endif
                ::boost::accumulators::accumulator_base
#if defined BOOST_NO_CX11_HDR_TYPE_TRAITS
              , typename ::boost::remove_const<T>::type
#else
              , typename ::std::remove_const<T>::type
#endif
            >
          , ::boost::concept::traits::has_result_type<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

