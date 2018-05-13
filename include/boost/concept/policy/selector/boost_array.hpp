// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_BOOST_ARRAY_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_BOOST_ARRAY_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/array.hpp>

//[reference__boost_array_selector
namespace boost { namespace concept { namespace policy {

    template <typename ConstantSize>
    struct boost_array_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::boost::array<T,ConstantSize::value> type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

