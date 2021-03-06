// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_NEXT_TO_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_NEXT_TO_HPP

#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/next_prior.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct next_to
      : ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>
          , ::boost::mpl::identity<void>
          , ::boost::mpl::next<T>
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access_fwd.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

//[reference__next_to
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct next_to
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _type_erasure_is_placeholder_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , void
          , typename _std_remove_const_<
                typename _std_remove_reference_<T>::type
            >::type::next
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::next_to<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            typename ::boost::remove_const<
                typename ::boost::remove_reference<T>::type
            >::type
#else
            typename ::std::remove_const<
                typename ::std::remove_reference<T>::type
            >::type
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#if defined (BOOST_NO_CXX11_TEMPLATE_ALIASES)

namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct next_to_t : ::boost::concept::traits::next_to<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#endif  // include guard

