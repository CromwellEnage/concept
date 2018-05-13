// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_REVERSIBLE_CONT_IMPL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_REVERSIBLE_CONT_IMPL_HPP

#include <boost/concept/traits/query/is_reversible.hpp>
#include <boost/concept/traits/introspection/nested_type/has_hasher.hpp>
#include <boost/concept/traits/introspection/member_function/has_size.hpp>
#include <boost/concept/traits/_detail/metafunction/is_container_impl.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_reversible_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_hasher<T>
          , ::boost::mpl::false_
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_size<T const>
              , ::boost::mpl::if_<
                    ::boost::concept::traits::_detail::metafunction
                    ::is_minimal_container_impl<T,UMFC>
                  , ::boost::concept::traits::is_reversible<T,UMFC>
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

