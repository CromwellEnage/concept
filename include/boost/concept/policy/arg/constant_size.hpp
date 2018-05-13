// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_ARG_CONSTANT_SIZE_HPP
#define BOOST_CONCEPT_POLICY_ARG_CONSTANT_SIZE_HPP

#include <boost/concept/policy/arg_fwd.hpp>
#include <boost/parameter/aux_/template_keyword.hpp>

//[reference__constant_size_arg
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct constant_size_arg
      : ::boost::parameter::template_keyword<
            ::boost::concept::policy::constant_size_tag
          , T
        >
    {
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

