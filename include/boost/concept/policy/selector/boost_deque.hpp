// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_BOOST_DEQUE_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_BOOST_DEQUE_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/new_allocator.hpp>
#include <boost/container/deque.hpp>
#include <boost/mpl/apply.hpp>

//[reference__boost_deque_selector
namespace boost { namespace concept { namespace policy {

    template <typename AllocatorSelector>
    struct boost_deque_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::container::deque<
                        T
                      , typename ::boost::mpl::apply1<
                            AllocatorSelector
                          , T
                        >::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

