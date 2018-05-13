// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_STD_HASH_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_STD_HASH_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/config.hpp>

#if !defined BOOST_NO_CXX11_HDR_FUNCTIONAL

#include <functional>

//[reference__std_hash_selector
namespace boost { namespace concept { namespace policy {

    struct std_hash_selector
    {
        template <typename T>
        struct apply
        {
            typedef ::std::hash<T> type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif

#endif  // include guard

