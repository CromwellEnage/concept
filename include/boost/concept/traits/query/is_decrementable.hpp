// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_DECREMENTABLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_DECREMENTABLE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_pre_decrementable.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_post_decrement_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_decrementable
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_decrementable
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _is_valid_expression_(_bct_declref_<T>()--)
          , _bct_is_pre_decrementable_<T>
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_pre_decrementable<T>
          , ::boost::concept::traits::_detail::metafunction
            ::has_post_decrement_operator<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

