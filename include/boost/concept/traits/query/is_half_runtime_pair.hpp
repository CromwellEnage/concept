// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_HALF_RUNTIME_PAIR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_HALF_RUNTIME_PAIR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/introspection/nested_type/has_first_type.hpp>
#include <boost/concept/traits/introspection/member_data/has_first.hpp>
#include <boost/concept/traits/introspection/member_data/has_second.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_half_runtime_pair
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_half_runtime_pair
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_has_first_<T>
          , _mpl_false_
          , _mpl_if_<
                _bct_has_first_type_<T>
              , _bct_has_second_<T>
              , _mpl_false_
            >
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_first<T>
          , ::boost::mpl::false_
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_first_type<T>
              , ::boost::concept::traits::has_second<T>
              , ::boost::mpl::false_
            >
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

