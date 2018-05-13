// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_ADDITIVE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_ADDITIVE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_addable.hpp>
#include <boost/concept/traits/query/is_subtractable.hpp>

//[reference__is_additive
namespace boost { namespace concept { namespace traits {

    template <typename T, typename Difference>
    struct is_additive
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_addable_<T,Difference>
          , _mpl_if_<
                _bct_is_subtractable_<T,Difference>
              , _bct_is_subtractable_<T,T,Difference>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_addable<T,Difference>
          , ::boost::mpl::if_<
                ::boost::concept::traits::is_subtractable<T,Difference>
              , ::boost::concept::traits::is_subtractable<T,T,Difference>
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

