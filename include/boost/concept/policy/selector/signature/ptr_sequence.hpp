// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_SIGNATURE_PTR_SEQUENCE_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_SIGNATURE_PTR_SEQUENCE_HPP

#include <boost/concept/policy/arg_fwd.hpp>
#include <boost/concept/traits/query/is_allocator.hpp>
#include <boost/concept/traits/query/is_clone_allocator.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/mpl/placeholders.hpp>

//[reference__ptr_sequence_selector_signature
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct ptr_sequence_selector_signature
    {
        typedef ::boost::parameter::parameters<
                    ::boost::parameter::optional<
                        ::boost::parameter::deduced<
                            ::boost::concept::policy::ptr_clone_allocator_tag
                        >
                      , ::boost::concept::traits::is_clone_allocator<
                            ::boost::mpl::_
                          , T
                        >
                    >
                  , ::boost::parameter::optional<
                        ::boost::parameter::deduced<
                            ::boost::concept::policy::ptr_allocator_tag
                        >
                      , ::boost::concept::traits::is_allocator<
                            ::boost::mpl::_
                        >
                    >
                >
                type;
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

