// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_BOOST_STATIC_VECTOR_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_BOOST_STATIC_VECTOR_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/container/static_vector.hpp>

//[reference__static_vector_selector
namespace boost { namespace concept { namespace policy {

    template <typename ConstantCapacity>
    struct static_vector_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::container::static_vector<
                        T
                      , ConstantCapacity::value
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

