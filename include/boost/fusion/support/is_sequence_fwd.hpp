// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FUSION_SUPPORT_IS_SEQUENCE_FWD_HPP
#define BOOST_FUSION_SUPPORT_IS_SEQUENCE_FWD_HPP

namespace boost { namespace fusion { namespace extension {

    template <typename Tag>
    struct is_sequence_impl;
}}}  // namespace boost::fusion::extension

namespace boost { namespace fusion { namespace traits {

    template <typename T>
    struct is_sequence;
}}}  // namespace boost::fusion::traits

#endif  // include guard

