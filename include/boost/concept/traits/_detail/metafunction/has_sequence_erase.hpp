// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_SEQUENCE_ERASE_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_SEQUENCE_ERASE_HPP

#include <boost/concept/traits/introspection/member_function/has_erase.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_sequence_erase
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_erase<
                T
              , typename T::iterator
            >
          , ::boost::concept::traits::has_erase<
                T
              , typename T::iterator
              , typename T::iterator
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

