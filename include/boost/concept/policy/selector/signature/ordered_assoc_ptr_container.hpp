// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_POLICY_SELECTOR_SIGNATURE_ORDERED_ASSOC_PTR_CONTAINER_HPP
#define \
BOOST_CONCEPT_POLICY_SELECTOR_SIGNATURE_ORDERED_ASSOC_PTR_CONTAINER_HPP

#include <boost/concept/policy/arg_fwd.hpp>
#include <boost/concept/traits/query/is_mpl_boolean_constant.hpp>
#include <boost/concept/traits/query/is_unary_metafunc_class.hpp>
#include <boost/concept/traits/query/is_binary_function.hpp>
#include <boost/concept/traits/query/is_boolean_expression.hpp>
#include <boost/concept/traits/query/is_allocator.hpp>
#include <boost/concept/traits/query/is_clone_allocator.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/protect.hpp>
#include <boost/mpl/bind.hpp>

//[reference__ordered_associative_ptr_container_selector_signature
namespace boost { namespace concept { namespace policy {

    template <typename Key, typename Value>
    struct ordered_associative_ptr_container_selector_signature
    {
        typedef ::boost::parameter::parameters<
                    ::boost::parameter::optional<
                        ::boost::parameter::deduced<
                            ::boost::concept::policy::unique_flag_tag
                        >
                      , ::boost::concept::traits::is_mpl_boolean_constant<
                            ::boost::mpl::_
                        >
                    >
                  , ::boost::parameter::optional<
                        ::boost::parameter::deduced<
                            ::boost::concept::policy::compare_selector_tag
                        >
                      , ::boost::concept::traits::is_unary_metafunction_class<
                            ::boost::mpl::_
                          , Key
                          , ::boost::mpl::protect<
                                ::boost::mpl::bind4<
                                    ::boost::mpl::quote4<
                                        ::boost::concept::traits
                                        ::is_binary_function
                                    >
                                  , ::boost::mpl::_1
                                  , Key
                                  , Key
                                  , ::boost::mpl::quote1<
                                        ::boost::concept::traits
                                        ::is_boolean_expression
                                    >
                                >
                            >
                        >
                    >
                  , ::boost::parameter::optional<
                        ::boost::parameter::deduced<
                            ::boost::concept::policy::ptr_clone_allocator_tag
                        >
                      , ::boost::concept::traits::is_clone_allocator<
                            ::boost::mpl::_
                          , Value
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

