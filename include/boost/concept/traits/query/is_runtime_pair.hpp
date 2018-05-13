// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_RUNTIME_PAIR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_RUNTIME_PAIR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/member_data/has_first.hpp>
#include <boost/concept/traits/introspection/member_data/has_second.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_runtime_pair
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename FirstPlaceholderExpr
      , typename SecondPlaceholderExpr
    >
    struct is_runtime_pair
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _bct_has_first_<T,FirstPlaceholderExpr>
          , _bct_has_second_<T,SecondPlaceholderExpr>
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_first<T,FirstPlaceholderExpr>
          , ::boost::concept::traits::has_second<T,SecondPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

