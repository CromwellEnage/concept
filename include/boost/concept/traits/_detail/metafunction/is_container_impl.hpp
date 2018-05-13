// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_CONTAINER_IMPL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_CONTAINER_IMPL_HPP

#include <boost/concept/traits/query/is_range.hpp>
#include <boost/concept/traits/introspection/nested_type/has_iterator.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/traits/introspection/nested_type/has_reference.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    // MAINTAINER:
    //  * ::std::forward_list does not have a size() accessor.
    //  * ::boost::numeric::ublas::c_vector has data() accessors.
    //  * ::boost::numeric::ublas::c_vector has neither an empty() accessor
    //    nor a max_size() accessor.
    template <typename T, typename UMFC>
    struct is_minimal_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_value_type<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_reference<T const>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_range<T const,UMFC>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_iterator<T const>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_reference<T>
                          , ::boost::mpl::if_<
                                ::boost::concept::traits::is_range<T,UMFC>
                              , ::boost::concept::traits::has_iterator<T>
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

    // MAINTAINER:
    // Not all container implementations are default-constructible
    // or swappable.
    template <typename T>
    struct is_mutable_container_impl : ::boost::mpl::true_
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

