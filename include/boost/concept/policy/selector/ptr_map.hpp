// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_PTR_MAP_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_PTR_MAP_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/less_than.hpp>
#include <boost/concept/policy/selector/std_allocator.hpp>
#include \
<boost/concept/policy/selector/signature/ordered_assoc_ptr_container.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/clone_allocator.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>
#include <utility>

//[reference__ptr_map_selector
namespace boost { namespace concept { namespace policy {

    template <typename P0, typename P1, typename P2, typename P3>
    struct ptr_map_selector
    {
        template <typename Key, typename Mapped>
        class apply
        {
            typedef ::std::pair<Key const,void*>
                    _value;
            typedef typename ::boost::concept::policy
                    ::ordered_associative_ptr_container_selector_signature<
                        Key
                      , _value
                    >::type::BOOST_NESTED_TEMPLATE bind<P0,P1,P2,P3>::type
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
            typedef typename ::boost::parameter::value_type<
                        _arg_pack
                      , ::boost::concept::policy::ptr_clone_allocator_tag
                      , ::boost::heap_clone_allocator
                    >::type
                    _clone_allocator;
            typedef typename ::boost::parameter::value_type<
                        _arg_pack
                      , ::boost::concept::policy::ptr_allocator_tag
                      , typename ::boost::mpl::apply1<
                            ::boost::concept::policy::std_allocator_selector
                          , _value
                        >::type
                    >::type
                    _allocator;

         public:
            typedef typename ::boost::mpl::if_<
                        typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::unique_flag_tag
                          , ::boost::mpl::false_
                        >::type
                      , ::boost::ptr_map<
                            Key
                          , Mapped
                          , _comparator
                          , _clone_allocator
                          , _allocator
                        >
                      , ::boost::ptr_multimap<
                            Key
                          , Mapped
                          , _comparator
                          , _clone_allocator
                          , _allocator
                        >
                    >::type
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

