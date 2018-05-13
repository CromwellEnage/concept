// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_ITERATOR_HPP

#include <boost/concept/traits/query/is_lvalue_assignable.hpp>
#include <boost/concept/traits/_detail/metafunction/is_dereferenceable.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_pre_increment_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_iterator
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_dereferenceable<T>::type
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_lvalue_assignable<T>
              , ::boost::concept::traits::_detail::metafunction
                ::has_pre_increment_operator<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

