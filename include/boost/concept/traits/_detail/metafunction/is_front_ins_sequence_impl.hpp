// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FRONT_INS_SEQUENCE_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_FRONT_INS_SEQUENCE_IMPL_HPP

#include <boost/concept/traits/introspection/nested_type/is_iterator_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_front.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_push_front.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_pop_front.hpp>
#include <boost/concept/traits/_detail/metafunction/is_sequence_impl.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_front_insertion_sequence_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_sequence_impl<T,UMFC>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_front<T const>
              , ::boost::mpl::if_<
                    ::boost::concept::traits::has_push_front<T>
                  , ::boost::concept::traits::has_pop_front<T>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

