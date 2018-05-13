// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ITERATOR1_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ITERATOR1_OF_HPP

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct iterator1_of_impl
    {
        typedef typename T::iterator1 type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct const_iterator1_of_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type::const_iterator1
#else
        typedef typename ::std::remove_const<T>::type::const_iterator1
#endif
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access_fwd.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#endif

//[reference__iterator1_of
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct iterator1_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _type_erasure_is_placeholder_<T>
          , _mpl_identity_<void>
          , _mpl_if_<
                _std_is_const_<T>
              , typename _std_remove_const_<T>::type::const_iterator1
              , typename T::iterator1
            >
        >
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>
          , ::boost::mpl::identity<void>
          , ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_const<T>
#else
                ::std::is_const<T>
#endif
              , ::boost::concept::traits::_detail::metafunction
                ::const_iterator1_of_impl<T>
              , ::boost::concept::traits::_detail::metafunction
                ::iterator1_of_impl<T>
            >
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
    struct iterator1_of_t
      : ::boost::concept::traits::iterator1_of<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#endif  // include guard

