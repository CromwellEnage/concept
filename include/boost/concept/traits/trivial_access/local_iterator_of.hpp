// Copyright (C) 2016-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_LOCAL_ITERATOR_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_LOCAL_ITERATOR_OF_HPP

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct local_iterator_of_impl
    {
        typedef typename T::local_iterator type;
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
    struct const_local_iterator_of_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type::const_local_iterator
#else
        typedef typename ::std::remove_const<T>::type::const_local_iterator
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

//[reference__local_iterator_of
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct local_iterator_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _type_erasure_is_placeholder_<T>
          , _mpl_identity_<void>
          , _mpl_if_<
                _std_is_const_<T>
              , typename _std_remove_const_<T>::type::const_local_iterator
              , typename T::local_iterator
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
                ::const_local_iterator_of_impl<T>
              , ::boost::concept::traits::_detail::metafunction
                ::local_iterator_of_impl<T>
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
    struct local_iterator_of_t
      : ::boost::concept::traits::local_iterator_of<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#endif  // include guard

