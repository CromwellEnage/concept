// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_ARCHETYPE_ACCUMULATOR_HPP
#define BOOST_CONCEPT_ARCHETYPE_ACCUMULATOR_HPP

#include <boost/accumulators/framework/accumulator_base.hpp>

//[reference__accumulator_archetype
namespace boost { namespace concept {

    template <typename T>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    struct accumulator_archetype : _accumulator_base_
//<-
#else
    struct accumulator_archetype : ::boost::accumulators::accumulator_base
#endif
//->
    {
        typedef T result_type;

        template <typename ArgPack>
        accumulator_archetype(ArgPack const&);

        template <typename ArgPack>
        void operator()(ArgPack const&);

        template <typename ArgPack>
        result_type result(ArgPack const&) const;
    };
}}  // namespace boost::concept
//]

#endif  // include guard

