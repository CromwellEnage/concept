// Copyright (C) 2014-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_POLYMORPHIC_ALLOCATOR_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_POLYMORPHIC_ALLOCATOR_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/container/pmr/polymorphic_allocator.hpp>

//[reference__polymorphic_allocator_selector
namespace boost { namespace concept { namespace policy {

    struct polymorphic_allocator_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::container::pmr::polymorphic_allocator<T> type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

