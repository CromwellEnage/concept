// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ALLOCATOR_TYPE_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ALLOCATOR_TYPE_OF_HPP

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct allocator_type_of_actual
    {
        typedef typename T::allocator_type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct allocator_type_of
      : ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>
          , ::boost::mpl::identity<void>
          , ::boost::concept::traits::_detail::metafunction
            ::allocator_type_of_actual<T>
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/trivial_access_fwd.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__allocator_type_of
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct allocator_type_of
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
            >::type::allocator_type
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::allocator_type_of<
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

#if defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)

namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct allocator_type_of_t
      : ::boost::concept::traits::allocator_type_of<T>::type
    {
    };
}}}  // namespace boost::concept::traits

#endif

#endif  // include guard

