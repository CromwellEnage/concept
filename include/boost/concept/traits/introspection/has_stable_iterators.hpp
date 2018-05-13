// Copyright (C) 2005-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_HAS_STABLE_ITERATORS_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_HAS_STABLE_ITERATORS_HPP

#include <boost/concept/traits/introspection_fwd.hpp>
#include <boost/concept/traits/query/is_container.hpp>
#include <boost/concept/traits/query/is_flat_assoc_container.hpp>
#include <boost/concept/traits/query/is_hashed_assoc_container.hpp>
#include <boost/concept/traits/query/is_random_access_container.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__has_stable_iterators
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct has_stable_iterators
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_flat_associative_container_<T>
          , _mpl_false_
          , _mpl_eval_if_<
                _bct_is_hashed_associative_container_<T>
              , _mpl_false_
              , _mpl_if_<
                    _bct_is_random_access_container_<T>
                  , _mpl_false_
                  , _bct_is_container_<T>
                >
            >
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_flat_associative_container<T>
          , ::boost::mpl::false_
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_hashed_associative_container<T>
              , ::boost::mpl::false_
              , ::boost::mpl::if_<
                    ::boost::concept::traits::is_random_access_container<T>
                  , ::boost::mpl::false_
                  , ::boost::concept::traits::is_container<T>
                >
            >
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

