// Copyright (C) 2016-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_UNORDER_ASSOC_CONT_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_UNORDER_ASSOC_CONT_IMPL_HPP

#include <boost/concept/traits/introspection/member_function/has_cbegin.hpp>
#include <boost/concept/traits/introspection/member_function/has_cend.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_begin_bucket.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_end_bucket.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_cbegin_bucket.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_cend_bucket.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_hashed_assoc_cont_impl.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_minimal_unordered_associative_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_minimal_hashed_associative_container_impl<T,UMFC>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_cbegin_bucket<T const>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_cend_bucket<T const>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_begin_bucket<T const>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_end_bucket<T const>
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_begin_bucket<T>
                              , ::boost::mpl::eval_if<
                                    ::boost::concept::traits
                                    ::has_end_bucket<T>
                                  , ::boost::mpl::if_<
                                        ::boost::concept::traits
                                        ::has_cbegin<T const>
                                      , ::boost::concept::traits
                                        ::has_cend<T const>
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
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/member_function/has_rehash.hpp>
#include <boost/concept/traits/introspection/member_function/has_reserve.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_assoc_container_impl.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_mutable_unordered_associative_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_mutable_associative_container_impl<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_rehash<T>
              , ::boost::concept::traits::has_reserve<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

