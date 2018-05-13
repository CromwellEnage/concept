// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_ARCHETYPE_VALUE_GENERATOR_HPP
#define BOOST_CONCEPT_ARCHETYPE_VALUE_GENERATOR_HPP

//[reference__value_generator_archetype
namespace boost { namespace concept {

    template <typename T>
    struct value_generator_archetype
    {
        typedef T result_type;
        static result_type min();
        static result_type max();
        result_type operator()();
    };
}}  // namespace boost::concept
//]

#endif  // include guard

