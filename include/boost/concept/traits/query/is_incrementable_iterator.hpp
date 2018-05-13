// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_INCREMENTABLE_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_INCREMENTABLE_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_incrementable.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_traversal_of.hpp>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__is_incrementable_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_incrementable_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _bct_is_incrementable_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _bct_is_iterator_traversal_of_<
                boost::iterators::incremental_traversal_tag
              , T
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_incrementable<
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
          , ::boost::concept::traits::is_iterator_traversal_of<
                ::boost::iterators::incrementable_traversal_tag
              , T
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#include <boost/iterator/function_input_iterator.hpp>

namespace boost { namespace concept { namespace traits {

    template <typename F, typename S>
    struct is_incrementable_iterator<
        ::boost::iterators::function_input_iterator<F,S>
    > : ::boost::concept::traits::is_incrementable<S>
    {
    };

    template <typename F, typename S>
    struct is_incrementable_iterator<
        ::boost::iterators::function_input_iterator<F,S> const
    > : ::boost::concept::traits::is_incrementable<S>
    {
    };

    template <typename F, typename S>
    struct is_incrementable_iterator<
        ::boost::iterators::function_input_iterator<F,S>&
    > : ::boost::concept::traits::is_incrementable<S>
    {
    };

    template <typename F, typename S>
    struct is_incrementable_iterator<
        ::boost::iterators::function_input_iterator<F,S> const&
    > : ::boost::concept::traits::is_incrementable<S>
    {
    };
}}}  // namespace boost::concept::traits

#endif  // include guard
