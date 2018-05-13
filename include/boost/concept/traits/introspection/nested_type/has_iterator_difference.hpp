// Copyright (C) 2011-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_ITERATOR_DIFFERENCE_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_HAS_ITERATOR_DIFFERENCE_HPP

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include <boost/concept/traits/_detail/metafunction/has_difference_type.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
#include <iterator>
#endif

//[reference__has_iterator_difference
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_iterator_difference
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_has_trait_named_(difference_type)<
            _std_iterator_traits_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::has_difference_type<
#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
            ::std::iterator_traits<
#endif
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
            >
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

