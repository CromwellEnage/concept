// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_STD_PRIORITY_QUEUE_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_STD_PRIORITY_QUEUE_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/std_deque.hpp>
#include <boost/concept/policy/selector/less_than.hpp>
#include <boost/concept/policy/selector/signature/std_priority_queue.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/apply.hpp>
#include <queue>

//[reference__std_priority_queue_selector
namespace boost { namespace concept { namespace policy {

    template <typename T0, typename T1>
    struct std_priority_queue_selector
    {
        template <typename T>
        class apply
        {
            typedef typename ::boost::concept::policy
                    ::std_priority_queue_selector_signature<T>::type
                    ::BOOST_NESTED_TEMPLATE bind<T0,T1>::type
                    _arg_pack;

         public:
            typedef ::std::priority_queue<
                        T
                      , typename ::boost::mpl::apply1<
                            typename ::boost::parameter::value_type<
                                _arg_pack
                              , ::boost::concept::policy::sequence_selector_tag
                              , ::boost::concept::policy::std_deque_selector<>
                            >::type
                          , T
                        >::type
                      , typename ::boost::mpl::apply1<
                            typename ::boost::parameter::value_type<
                                _arg_pack
                              , ::boost::concept::policy::compare_selector_tag
                              , ::boost::concept::policy::less_than_selector
                            >::type
                          , T
                        >::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

