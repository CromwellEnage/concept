// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_CLONE_ALLOCATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_CLONE_ALLOCATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_allocate_clone.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_deallocate_clone.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

//[reference__is_clone_allocator
namespace boost { namespace concept { namespace traits {

    template <typename T, typename U>
    struct is_clone_allocator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_if_<
            _bct_has_allocate_clone_<T,U>
          , _bct_has_deallocate_clone_<T,U>
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_allocate_clone<T,U>
          , ::boost::concept::traits::has_deallocate_clone<T,U>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

