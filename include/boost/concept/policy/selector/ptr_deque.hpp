// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_PTR_DEQUE_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_PTR_DEQUE_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/signature/ptr_sequence.hpp>
#include <boost/concept/policy/selector/std_allocator.hpp>
#include <boost/ptr_container/ptr_deque.hpp>
#include <boost/ptr_container/clone_allocator.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/apply.hpp>

//[reference__ptr_deque_selector
namespace boost { namespace concept { namespace policy {

    template <typename P0, typename P1>
    struct ptr_deque_selector
    {
        template <typename T>
        class apply
        {
            typedef typename ::boost::concept::policy
                    ::ptr_sequence_selector_signature<T>::type
                    ::BOOST_NESTED_TEMPLATE bind<P0,P1>::type
                    _arg_pack;

         public:
            typedef ::boost::ptr_deque<
                        T
                      , typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::ptr_clone_allocator_tag
                          , ::boost::heap_clone_allocator
                        >::type
                      , typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::ptr_allocator_tag
                          , ::boost::mpl::apply1<
                                ::boost::concept::policy::std_allocator_selector
                              , void*
                            >::type
                        >::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

