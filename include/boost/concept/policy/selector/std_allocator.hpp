// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_STD_ALLOCATOR_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_STD_ALLOCATOR_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_STD_ALLOCATOR
#include <vector>
#else
#include <memory>
#endif

//[reference__std_allocator_selector
namespace boost { namespace concept { namespace policy {

    struct std_allocator_selector
    {
        template <typename T>
        struct apply
        {
//<-
#if defined BOOST_NO_STD_ALLOCATOR
            typedef BOOST_DEDUCED_TYPENAME ::std::vector<T>::allocator_type
                    type;
#else
//->
            typedef ::std::allocator<T> type;
//<-
#endif
//->
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

