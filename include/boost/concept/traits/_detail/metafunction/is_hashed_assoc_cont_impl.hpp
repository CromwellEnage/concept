// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_HASHED_ASSOC_CONT_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_HASHED_ASSOC_CONT_IMPL_HPP

#if defined BOOST_CONCEPT_CONFIG_BUG_IN_BIMAP_UNORDERED_VIEWS_NO_HASH_FUNCS
#include <boost/concept/traits/introspection/nested_type/has_hasher.hpp>
#include <boost/concept/traits/introspection/nested_type/has_key_equal.hpp>
#else
#include \
<boost/concept/traits/introspection/member_function/has_hash_function.hpp>
#include <boost/concept/traits/introspection/member_function/has_key_eq.hpp>
#endif
#include \
<boost/concept/traits/introspection/member_function/has_bucket_count.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_max_bucket_count.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_assoc_container_impl.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_minimal_hashed_associative_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_minimal_associative_container_impl<T,UMFC>
          , ::boost::mpl::eval_if<
#if defined BOOST_CONCEPT_CONFIG_BUG_IN_BIMAP_UNORDERED_VIEWS_NO_HASH_FUNCS
                ::boost::concept::traits::has_hasher<T>
#else
                ::boost::concept::traits::has_hash_function<T const>
#endif
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_max_bucket_count<T const>
                  , ::boost::mpl::if_<
                        ::boost::concept::traits::has_bucket_count<T const>
#if defined BOOST_CONCEPT_CONFIG_BUG_IN_BIMAP_UNORDERED_VIEWS_NO_HASH_FUNCS
                      , ::boost::concept::traits::has_key_equal<T>
#else
                      , ::boost::concept::traits::has_key_eq<T const>
#endif
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

