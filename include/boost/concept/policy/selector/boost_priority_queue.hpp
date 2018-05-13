// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_BOOST_PRIORITY_QUEUE_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_BOOST_PRIORITY_QUEUE_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/less_than.hpp>
#include <boost/concept/policy/selector/std_allocator.hpp>
#include <boost/concept/policy/selector/signature/boost_priority_queue.hpp>
#include <boost/heap/priority_queue.hpp>
#include <boost/heap/policies.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/apply.hpp>
#include <cstdint>

//[reference__boost_priority_queue_selector
namespace boost { namespace concept { namespace policy {

    template <typename P0, typename P1, typename P2, typename P3>
    struct boost_priority_queue_selector
    {
        template <typename T>
        class apply
        {
            typedef typename ::boost::concept::policy
                    ::boost_priority_queue_selector_signature<T>::type
                    ::BOOST_NESTED_TEMPLATE bind<P0,P1,P2,P3>::type
                    _arg_pack;

         public:
            typedef ::boost::heap::priority_queue<
                        T
                      , ::boost::heap::compare<
                            typename ::boost::mpl::apply1<
                                typename ::boost::parameter::value_type<
                                    _arg_pack
                                  , ::boost::concept::policy
                                    ::compare_selector_tag
                                  , ::boost::concept::policy
                                    ::less_than_selector
                                >::type
                              , T
                            >::type
                        >
                      , ::boost::heap::allocator<
                            typename ::boost::mpl::apply1<
                                typename ::boost::parameter::value_type<
                                    _arg_pack
                                  , ::boost::concept::policy
                                    ::allocator_selector_tag
                                  , ::boost::concept::policy
                                    ::std_allocator_selector
                                >::type
                              , T
                            >::type
                        >
                      , ::boost::heap::stable<
                            ::boost::heap::detail::extract_stable<
                                _arg_pack
                            >::value
                        >
                      , ::boost::heap::stability_counter_type<
                            typename ::boost::parameter::binding<
                                _arg_pack
                              , ::boost::heap::tag::stability_counter_type
                              , ::boost::uintmax_t
                            >::type
                        >
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

