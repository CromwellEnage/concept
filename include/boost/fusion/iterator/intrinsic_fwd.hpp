// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FUSION_ITERATOR_INTRINSIC_FWD_HPP
#define BOOST_FUSION_ITERATOR_INTRINSIC_FWD_HPP

namespace boost { namespace fusion { namespace extension {

    template <typename Tag>
    struct deref_impl;

    template <typename Tag>
    struct deref_data_impl;

    template <typename Tag>
    struct next_impl;

    template <typename Tag>
    struct prior_impl;

    template <typename Tag>
    struct equal_to_impl;

    template <typename Tag>
    struct advance_impl;

    template <typename Tag>
    struct distance_impl;

    template <typename Tag>
    struct key_of_impl;

    template <typename Tag>
    struct value_of_impl;

    template <typename Tag>
    struct value_of_data_impl;
}}}  // namespace boost::fusion::extension

namespace boost { namespace fusion { namespace result_of {

    template <typename Iterator>
    struct deref;

    template <typename Iterator>
    struct deref_data;

    template <typename Iterator>
    struct next;

    template <typename Iterator>
    struct prior;

    template <typename Iterator1, typename Iterator2>
    struct equal_to;

    template <typename Iterator, int N>
    struct advance_c;

    template <typename Iterator, typename N>
    struct advance;

    template <typename Iterator1, typename Iterator2>
    struct distance;

    template <typename Iterator>
    struct key_of;

    template <typename Iterator>
    struct value_of;

    template <typename Iterator>
    struct value_of_data;
}}}  // namespace boost::fusion::result_of

#endif  // include guard

