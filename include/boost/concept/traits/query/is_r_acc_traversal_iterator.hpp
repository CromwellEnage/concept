// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_RANDOM_ACCESS_TRAVERSAL_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_RANDOM_ACCESS_TRAVERSAL_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_indexable_iterator.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_traversal_of.hpp>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_random_access_traversal_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_random_access_traversal_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _bct_is_indexable_traversal_iterator_<T>
          , _bct_is_iterator_traversal_of_<
                boost::iterators::random_access_traversal_tag
              , T
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::is_indexable_traversal_iterator<T>
          , ::boost::concept::traits::is_iterator_traversal_of<
                ::boost::iterators::random_access_traversal_tag
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

#endif  // include guard

