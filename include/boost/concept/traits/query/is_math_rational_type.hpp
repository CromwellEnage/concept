// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_RATIONAL_TYPE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_RATIONAL_TYPE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_math_real_type.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_numerator.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_denominator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_math_rational_type
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_math_rational_type
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_math_real_type_<T>
          , _mpl_if_<
                _bct_has_numerator_<T>
              , _bct_has_denominator_<T>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_math_real_type<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_numerator<T>
              , ::boost::concept::traits::has_denominator<T>
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

