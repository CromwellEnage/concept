// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_SORTED_ASSOC_CONT_IMPL_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_SORTED_ASSOC_CONT_IMPL_HPP

#include <boost/concept/traits/introspection/nested_type/has_hasher.hpp>
#include <boost/concept/traits/introspection/nested_type/has_key_compare.hpp>
#include <boost/concept/traits/introspection/member_function/has_key_comp.hpp>
#if defined BOOST_CONCEPT_CONFIG_CHECK_FOR_MEMBER_FUNCTION_VALUE_COMP
#include \
<boost/concept/traits/introspection/member_function/has_value_comp.hpp>
#else
#include \
<boost/concept/traits/introspection/nested_type/has_value_compare.hpp>
#endif
#include \
<boost/concept/traits/introspection/member_function/has_lower_bound.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_upper_bound.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_assoc_container_impl.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_sorted_associative_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_hasher<T>
          , ::boost::mpl::false_
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::_detail::metafunction
                ::is_minimal_associative_container_impl<T,UMFC>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_key_comp<T const>
                  , ::boost::mpl::eval_if<
#if defined BOOST_CONCEPT_CONFIG_CHECK_FOR_MEMBER_FUNCTION_VALUE_COMP
                        ::boost::concept::traits::has_value_comp<T const>
#else
                        ::boost::concept::traits::has_value_compare<T>
#endif
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_lower_bound<T const>
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits
                                ::has_upper_bound<T const>
                              , ::boost::mpl::if_<
                                    ::boost::concept::traits
                                    ::has_lower_bound<T>
                                  , ::boost::concept::traits
                                    ::has_upper_bound<T>
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
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

