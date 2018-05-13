// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MULTIPLICATIVE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MULTIPLICATIVE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_multipliable.hpp>
#include <boost/concept/traits/query/is_dividable.hpp>

//[reference__is_multiplicative
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Dividend>
    struct is_multiplicative
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_multipliable_<T,Dividend>
          , _mpl_if_<
                _bct_is_dividable_<T,Dividend>
              , _bct_is_dividable_<T,T,Dividend>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_multipliable<T,Dividend>
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_dividable<T,Dividend>
              , ::boost::concept::traits::is_dividable<T,T,Dividend>
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

