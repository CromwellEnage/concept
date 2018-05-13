// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_ASSOC_CONTAINER_IMPL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_ASSOC_CONTAINER_IMPL_HPP

#include <boost/concept/traits/_detail/metafunction/is_container_impl.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_assoc_cont_members.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_minimal_associative_container_impl
      : ::boost::mpl::if_<
            ::boost::concept::traits::_detail::metafunction
            ::is_minimal_container_impl<T,UMFC>
          , ::boost::concept::traits::_detail::metafunction
            ::has_minimal_associative_container_members<T>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/is_size_type_of.hpp>
#include <boost/concept/traits/introspection/member_function/has_erase.hpp>
#include <boost/concept/traits/introspection/member_function/has_clear.hpp>
#include <boost/concept/traits/_detail/metafunction/has_sequence_erase.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_mutable_associative_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_erase<
                    T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::add_const<typename T::key_type>::type
#else
              , typename ::std::add_const<typename T::key_type>::type
#endif
              , ::boost::concept::policy::use_default
              , ::boost::concept::traits::is_size_type_of< ::boost::mpl::_,T>
            >
          , ::boost::mpl::if_<
                ::boost::concept::traits::_detail::metafunction
                ::has_sequence_erase<T>
              , ::boost::concept::traits::has_clear<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

