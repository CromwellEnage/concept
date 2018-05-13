// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_ARG_FWD_HPP
#define BOOST_CONCEPT_POLICY_ARG_FWD_HPP

//[reference__constant_size_tag
namespace boost { namespace concept { namespace policy {

    struct constant_size_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__unique_flag_tag
namespace boost { namespace concept { namespace policy {

    struct unique_flag_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__hasher_selector_tag
namespace boost { namespace concept { namespace policy {

    struct hasher_selector_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__compare_selector_tag
namespace boost { namespace concept { namespace policy {

    struct compare_selector_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__allocator_selector_tag
namespace boost { namespace concept { namespace policy {

    struct allocator_selector_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_clone_allocator_tag
namespace boost { namespace concept { namespace policy {

    struct ptr_clone_allocator_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_allocator_tag
namespace boost { namespace concept { namespace policy {

    struct ptr_allocator_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__sequence_selector_tag
namespace boost { namespace concept { namespace policy {

    struct sequence_selector_tag;
}}}  // namespace boost::concept::policy
//]

//[reference__constant_size_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct constant_size_arg;
}}}  // namespace boost::concept::policy
//]

//[reference__unique_flag_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct unique_flag_arg;
}}}  // namespace boost::concept::policy
//]

//[reference__hasher_selector_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct hasher_selector_arg;
}}}  // namespace boost::concept::policy
//]

//[reference__compare_selector_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct compare_selector_arg;
}}}  // namespace boost::concept::policy
//]

//[reference__allocator_selector_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct allocator_selector_arg;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_clone_allocator_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct ptr_clone_allocator_arg;
}}}  // namespace boost::concept::policy
//]

//[reference__ptr_allocator_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct ptr_allocator_arg;
}}}  // namespace boost::concept::policy
//]

//[reference__sequence_selector_arg__fwd
namespace boost { namespace concept { namespace policy {

    template <typename T>
    struct sequence_selector_arg;
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

