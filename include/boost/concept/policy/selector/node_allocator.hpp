// Copyright (C) 2014-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_NODE_ALLOCATOR_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_NODE_ALLOCATOR_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/container/node_allocator.hpp>
#include <boost/mpl/size_t.hpp>

//[reference__node_allocator_selector
namespace boost { namespace concept { namespace policy {

    template <typename NodesPerBlock, typename Version>
    struct node_allocator_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::container::node_allocator<
                        T
                      , NodesPerBlock::value
                      , Version::value
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

