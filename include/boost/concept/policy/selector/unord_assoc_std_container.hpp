// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_UNORD_ASSOC_STD_CONTAINER_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_UNORD_ASSOC_STD_CONTAINER_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_UNORDERED_SET && \
    !defined BOOST_NO_CXX11_HDR_UNORDERED_MAP

#include <boost/concept/policy/selector/std_unordered_set.hpp>
#include <boost/concept/policy/selector/std_unordered_map.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_void.hpp>
#else
#include <type_traits>
#endif

//[reference__unordered_associative_std_container_selector
namespace boost { namespace concept { namespace policy {

    template <typename P0, typename P1, typename P2, typename P3>
    struct unordered_associative_std_container_selector
    {
        template <typename Key, typename Mapped = void>
        struct apply
          : ::boost::mpl::eval_if<
//<-
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                ::boost::is_void<Mapped>
#else
//->
                ::std::is_void<Mapped>
//<-
#endif
//->
              , ::boost::mpl::apply1<
                    ::boost::concept::policy
                    ::std_unordered_set_selector<P0,P1,P2,P3>
                  , Key
                >
              , ::boost::mpl::apply2<
                    ::boost::concept::policy
                    ::std_unordered_map_selector<P0,P1,P2,P3>
                  , Key
                  , Mapped
                >
            >
        {
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif

#endif  // include guard

