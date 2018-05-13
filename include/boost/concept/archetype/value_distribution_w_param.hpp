// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_ARCHETYPE_VALUE_DISTRIBUTION_W_PARAM_HPP
#define BOOST_CONCEPT_ARCHETYPE_VALUE_DISTRIBUTION_W_PARAM_HPP

#include <boost/concept/traits/query/is_value_generator.hpp>
#include <boost/core/enable_if.hpp>

//[reference__value_distribution_archetype_with_param
namespace boost { namespace concept {

    template <typename T>
    struct value_distribution_archetype_with_param
    {
        struct param_type
        {
            typedef value_distribution_archetype_with_param<T>
                    distribution_type;

            param_type(param_type const&);
            param_type& operator=(param_type const&);
            bool operator==(param_type const&) const;
            bool operator!=(param_type const&) const;
        };

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
            operator()(G&, param_type const&);

        result_type min() const;
        result_type max() const;
        param_type const& param() const;
        void param(param_type const&);
        void reset();

        bool
            operator==(
                value_distribution_archetype_with_param<T> const&
            ) const;

        bool
            operator!=(
                value_distribution_archetype_with_param<T> const&
            ) const;
    };
}}  // namespace boost::concept
//]

#endif  // include guard

