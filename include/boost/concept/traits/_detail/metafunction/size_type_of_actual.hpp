// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_SIZE_TYPE_OF_ACTUAL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_SIZE_TYPE_OF_ACTUAL_HPP

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct size_type_of_actual
    {
        typedef typename T::size_type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

