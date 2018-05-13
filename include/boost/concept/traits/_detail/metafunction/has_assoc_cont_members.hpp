// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_ASSOC_CONT_MEMBERS_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_ASSOC_CONT_MEMBERS_HPP

#include \
<boost/concept/traits/introspection/member_function/has_equal_range.hpp>
#include <boost/concept/traits/introspection/member_function/has_max_size.hpp>
#include <boost/concept/traits/introspection/member_function/has_size.hpp>
#include <boost/concept/traits/introspection/member_function/has_count.hpp>
#include <boost/concept/traits/introspection/member_function/has_find.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_minimal_associative_container_members
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_equal_range<T const>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_equal_range<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_count<T const>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_max_size<T const>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_size<T const>
                          , ::boost::mpl::if_<
                                ::boost::concept::traits::has_find<T const>
                              , ::boost::concept::traits::has_find<T>
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
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

