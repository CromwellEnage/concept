// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_BIMAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_BIMAP_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_container.hpp>
#include <boost/concept/traits/introspection/member_data/has_left.hpp>
#include <boost/concept/traits/introspection/member_data/has_right.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_bimap
namespace boost { namespace concept { namespace traits {

    template <
        typename T
      , typename LeftPlaceholderExpr
      , typename RightPlaceholderExpr
    >
    struct is_bimap
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_container_<T>
          , _mpl_if_<
                _bct_has_left_<T,LeftPlaceholderExpr>
              , _bct_has_right_<T,RightPlaceholderExpr>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_container<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_left<T,LeftPlaceholderExpr>
              , ::boost::concept::traits::has_right<T,RightPlaceholderExpr>
              , ::boost::mpl::false_
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

