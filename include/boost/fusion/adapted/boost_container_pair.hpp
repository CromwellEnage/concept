// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FUSION_ADAPTED_BOOST_CONTAINER_PAIR_HPP
#define BOOST_FUSION_ADAPTED_BOOST_CONTAINER_PAIR_HPP

#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/sequence/intrinsic_fwd.hpp>
#include <boost/fusion/iterator/intrinsic_fwd.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>
#include <boost/fusion/support/is_sequence_fwd.hpp>
#include <boost/fusion/support/is_view_fwd.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/container/detail/pair.hpp>

BOOST_FUSION_ADAPT_TPL_STRUCT(
    (T1)(T2)
  , (::boost::container::container_detail::pair)(T1)(T2)
  , (T1, first)(T2, second)
)

namespace boost { namespace fusion {

    struct container_pair_iterator_tag;
    struct container_pair_tag;
}}  // namespace boost::fusion

#endif  // include guard

