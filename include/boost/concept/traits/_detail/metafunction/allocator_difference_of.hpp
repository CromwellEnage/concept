// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ALLOCATOR_DIFFERENCE_OF_HPP
#define BOOST_CONCEPT_TRAITS_TRIVIAL_ACCESS_ALLOCATOR_DIFFERENCE_OF_HPP

#include \
<boost/concept/traits/_detail/metafunction/pointer_of_actual_or_value.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_POINTER_TRAITS)
#include <boost/intrusive/pointer_traits.hpp>
#else
#include <memory>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct allocator_difference_of_pointer
    {
#if defined(BOOST_NO_CXX11_POINTER_TRAITS)
        typedef typename ::boost::intrusive::pointer_traits<
#else
        typedef typename ::std::pointer_traits<
#endif
            typename ::boost::concept::traits::_detail::metafunction
            ::pointer_of_actual_or_value<T>::type
        >::difference_type type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/_detail/metafunction/has_difference_type.hpp>
#include \
<boost/concept/traits/_detail/metafunction/difference_type_of_actual.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct allocator_difference_of
      : ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>
          , ::boost::mpl::identity<void>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::_detail::metafunction
                ::has_difference_type<T>
              , ::boost::concept::traits::_detail::metafunction
                ::difference_type_of_actual<T>
              , ::boost::concept::traits::_detail::metafunction
                ::allocator_difference_of_pointer<T>
            >
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

