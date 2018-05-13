// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_STD_STACK_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_STD_STACK_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/std_vector.hpp>
#include <boost/mpl/apply.hpp>
#include <stack>

//[reference__std_stack_selector
namespace boost { namespace concept { namespace policy {

    template <typename SequenceSelector>
    struct std_stack_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::std::stack<
                        T
                      , typename ::boost::mpl::apply1<
                            SequenceSelector
                          , T
                        >::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

