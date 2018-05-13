// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ITERATOR_BOOL_PAIR_OF_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ITERATOR_BOOL_PAIR_OF_HPP

#include <boost/concept/traits/introspection/nested_type/is_iterator_of.hpp>
#include <boost/concept/traits/trivial_access/first_type_of.hpp>
#include <boost/concept/traits/trivial_access/second_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_iterator_bool_pair_of_impl
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_convertible<
#else
            ::std::is_convertible<
#endif
                typename ::boost::concept::traits::second_type_of<T1>::type
              , bool
            >
          , ::boost::concept::traits::is_iterator_of<
                typename ::boost::concept::traits::first_type_of<T1>::type
              , T2
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include <boost/concept/traits/query/is_runtime_pair.hpp>

//[reference__is_iterator_bool_pair_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_iterator_bool_pair_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_runtime_pair_<T1>
          , _mpl_if_<
                _std_is_convertible_<
                    typename _bct_second_type_of_<T1>::type
                  , bool
                >
              , _bct_is_iterator_of_<
                    typename _bct_first_type_of_<T1>::type
                  , T2
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_runtime_pair<T1>
          , ::boost::concept::traits::_detail::metafunction
            ::is_iterator_bool_pair_of_impl<T1,T2>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

