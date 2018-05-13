// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_READ_WRITE_PROPERTY_MAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_READ_WRITE_PROPERTY_MAP_HPP

#include <boost/property_map/property_map.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_convertible.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_read_write_property_map_impl
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
                typename ::boost::property_traits<T>::category
              , ::boost::read_write_property_map_tag
            >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_readable_property_map.hpp>
#include <boost/concept/traits/query/is_writable_property_map.hpp>

//[reference__is_read_write_property_map
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Key>
    struct is_read_write_property_map
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_readable_property_map_<T,Key>
          , _mpl_eval_if_<
                _bct_is_writable_property_map_<T,Key>
              , _mpl_if_<
                    _std_is_convertible_<
                        typename _property_traits_<T>::category
                      , boost::read_write_property_map_tag
                    >
                  , _mpl_true_
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_readable_property_map<T,Key>
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_writable_property_map<T,Key>
              , ::boost::concept::traits::_detail::metafunction
                ::is_read_write_property_map_impl<T>
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

