// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_PTR_ARRAY_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_PTR_ARRAY_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/policy/selector/signature/ptr_array.hpp>
#include <boost/ptr_container/ptr_array.hpp>
#include <boost/ptr_container/clone_allocator.hpp>
#include <boost/parameter/value_type.hpp>

//[reference__ptr_array_selector
namespace boost { namespace concept { namespace policy {

    template <typename P0, typename P1>
    struct ptr_array_selector
    {
        template <typename T>
        class apply
        {
            typedef typename ::boost::concept::policy
                    ::ptr_array_selector_signature<T>::type
                    ::BOOST_NESTED_TEMPLATE bind<P0,P1>::type
                    _arg_pack;
            typedef typename ::boost::parameter::value_type<
                        _arg_pack
                      , ::boost::concept::policy::constant_size_tag
                    >::type
                    _constant_size;

         public:
            typedef ::boost::ptr_array<
                        T
                      , _constant_size::value
                      , typename ::boost::parameter::value_type<
                            _arg_pack
                          , ::boost::concept::policy::ptr_clone_allocator_tag
                          , ::boost::heap_clone_allocator
                        >::type
                    >
                    type;
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

