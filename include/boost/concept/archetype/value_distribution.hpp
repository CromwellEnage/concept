// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_ARCHETYPE_VALUE_DISTRIBUTION_HPP
#define BOOST_CONCEPT_ARCHETYPE_VALUE_DISTRIBUTION_HPP

#include <boost/concept/traits/query/is_value_generator.hpp>
#include <boost/core/enable_if.hpp>

//[reference__value_distribution_archetype
namespace boost { namespace concept {

    template <typename T>
    struct value_distribution_archetype
    {
        typedef T result_type;

        template <typename G>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
        typename _core_enable_if_<
            _bct_is_value_generator_<G>
//<-
#else
        typename ::boost::enable_if<
            ::boost::concept::traits::is_value_generator<G>
#endif
//->
          , result_type
        >::type
            operator()(G&);

        result_type min() const;
        result_type max() const;
        void reset();
    };
}}  // namespace boost::concept
//]

#endif  // include guard

