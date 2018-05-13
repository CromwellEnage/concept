// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_ARCHETYPE_SINGLE_PASS_RANGE_HPP
#define BOOST_CONCEPT_ARCHETYPE_SINGLE_PASS_RANGE_HPP

#include <boost/concept_archetype.hpp>

//[reference__single_pass_range_archetype
namespace boost { namespace concept {

    template <typename T>
    struct single_pass_range_archetype
    {
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        typedef _input_iterator_archetype_<T> const_iterator;
//<-
#else
        typedef ::boost::input_iterator_archetype<T> const_iterator;
#endif
//->
        typedef const_iterator iterator;
        const_iterator begin() const;
        const_iterator end() const;
        iterator begin();
        iterator end();
    };
}}  // namespace boost::concept
//]

#endif  // include guard

