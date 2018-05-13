// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_ARCHETYPE_CLONE_ALLOCATOR_HPP
#define BOOST_CONCEPT_ARCHETYPE_CLONE_ALLOCATOR_HPP

//[reference__clone_allocator_archetype
namespace boost { namespace concept {

    struct clone_allocator_archetype
    {
        template <typename T>
        static T* allocate_clone(T const&);

        template <typename T>
        void deallocate_clone(T const*);
    };
}}  // namespace boost::concept
//]

#endif  // include guard

