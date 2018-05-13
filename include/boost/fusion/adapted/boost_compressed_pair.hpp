// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FUSION_ADAPTED_BOOST_COMPRESSED_PAIR_HPP
#define BOOST_FUSION_ADAPTED_BOOST_COMPRESSED_PAIR_HPP

#include <boost/fusion/adapted/adt/adapt_adt.hpp>
#include <boost/fusion/sequence/intrinsic_fwd.hpp>
#include <boost/fusion/iterator/intrinsic_fwd.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>
#include <boost/fusion/support/is_sequence_fwd.hpp>
#include <boost/fusion/support/is_view_fwd.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/compressed_pair.hpp>
#include <boost/call_traits.hpp>

BOOST_FUSION_ADAPT_TPL_ADT(
    (T1)(T2)
  , (::boost::compressed_pair)(T1)(T2)
  , (
        typename ::boost::call_traits<T1>::first_reference
      , typename ::boost::call_traits<T1>::first_const_reference
      , obj.first()
      , obj.first() = val
    )
    (
        typename ::boost::call_traits<T2>::second_reference
      , typename ::boost::call_traits<T2>::second_const_reference
      , obj.second()
      , obj.second() = val
    )
)

namespace boost { namespace fusion {

    struct compressed_pair_iterator_tag;
    struct compressed_pair_tag;
}}  // namespace boost::fusion

#endif  // include guard

