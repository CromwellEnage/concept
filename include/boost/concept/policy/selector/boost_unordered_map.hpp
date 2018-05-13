// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_BOOST_UNORDERED_MAP_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_BOOST_UNORDERED_MAP_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/boost_hash.hpp>
#include <boost/concept/policy/selector/less_than.hpp>
#include <boost/concept/policy/selector/new_allocator.hpp>
#include <boost/concept/policy/selector/signature/unorder_assoc_container.hpp>
#include <boost/unordered/unordered_map.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>
#include <utility>

//[reference__boost_unordered_map_selector
namespace boost { namespace concept { namespace policy {

    template <typename P0, typename P1, typename P2, typename P3>
    struct boost_unordered_map_selector
    {
        template <typename Key, typename Mapped>
        class apply
        {
            typedef ::std::pair<Key const,Mapped>
                    _value;
            typedef typename ::boost::concept::policy
                    ::unordered_associative_container_selector_signature<
                        Key
                      , _value
                    >::type::BOOST_NESTED_TEMPLATE bind<P0,P1,P2,P3>::type
                    _arg_pack;
            typedef typename ::boost::mpl::apply1<
                        typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::hasher_selector_tag
                          , ::boost::concept::policy::boost_hash_selector
                        >::type
                      , Key
                    >::type
                    _hasher;
            typedef typename ::boost::mpl::apply1<
                        typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::compare_selector_tag
                          , ::boost::concept::policy::equal_to_selector
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
                      , _value
                    >::type
                    _allocator;

         public:
            typedef typename ::boost::mpl::if_<
                        typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::unique_flag_tag
                          , ::boost::mpl::false_
                        >::type
                      , ::boost::unordered_map<
                            Key
                          , Mapped
                          , _comparator
                          , _allocator
                        >
                      , ::boost::unordered_multimap<
                            Key
                          , Mapped
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
