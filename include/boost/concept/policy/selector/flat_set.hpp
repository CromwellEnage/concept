// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_FLAT_SET_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_FLAT_SET_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/less_than.hpp>
#include <boost/concept/policy/selector/new_allocator.hpp>
#include <boost/concept/policy/selector/signature/ordered_assoc_container.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

//[reference__flat_set_selector
namespace boost { namespace concept { namespace policy {

    template <typename P0, typename P1, typename P2>
    struct flat_set_selector
    {
        template <typename Key>
        class apply
        {
            typedef typename ::boost::concept::policy
                    ::ordered_associative_container_selector_signature<
                        Key
                      , Key
                    >::type::BOOST_NESTED_TEMPLATE bind<P0,P1,P2>::type
                    _arg_pack;
            typedef typename ::boost::mpl::apply1<
                        typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::compare_selector_tag
                          , ::boost::concept::policy::less_than_selector
                        >::type
                      , Key
                    >::type
                    _comparator;
            typedef typename ::boost::mpl::apply1<
                        typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::allocator_selector_tag
                          , ::boost::concept::policy::new_allocator_selector
                        >::type
                      , Key
                    >::type
                    _allocator;

         public:
            typedef typename ::boost::mpl::if_<
                        typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::unique_flag_tag
                          , ::boost::mpl::false_
                        >::type
                      , ::boost::container::flat_set<
                            Key
                          , _comparator
                          , _allocator
                        >
                      , ::boost::container::flat_multiset<
                            Key
                          , _comparator
                          , _allocator
                        >
                    >::type
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

