// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_STD_VECTOR_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_STD_VECTOR_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/std_allocator.hpp>
#include <boost/mpl/apply.hpp>
#include <vector>

//[reference__std_vector_selector
namespace boost { namespace concept { namespace policy {

    template <typename AllocatorSelector>
    struct std_vector_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::std::vector<
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

