// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_EVENT_FILTER_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_EVENT_FILTER_OF_HPP

#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct event_filter_of_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type::event_filter type;
#else
        typedef typename ::std::remove_const<T>::type::event_filter type;
#endif
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access_fwd.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

//[reference__event_filter_of
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct event_filter_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _type_erasure_is_placeholder_<T>
          , void
          , typename _std_remove_const_<T>::type::event_filter
        >
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>
          , ::boost::mpl::identity<void>
          , ::boost::concept::traits::_detail::metafunction
            ::event_filter_of_impl<T>
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#if defined BOOST_NO_CXX11_TEMPLATE_ALIASES

namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct event_filter_of_t
      : ::boost::concept::traits::event_filter_of<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#endif  // include guard

