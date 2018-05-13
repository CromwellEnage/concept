// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_READABLE_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_READABLE_ITERATOR_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#else
#include <boost/mpl/if.hpp>
#include <type_traits>
#endif

#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
#include <iterator>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_readable_iterator_impl
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                BOOST_TYPEOF_KEYWORD(*::boost::concept::traits::declref<T>())
#else
                decltype(*::boost::concept::traits::declref<T>())
#endif
              , typename ::boost::iterators::iterator_value<
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                    T
#else
                    ::std::iterator_traits<T>
#endif
                >::type
            >
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query/is_lvalue_assignable.hpp>
#include <boost/concept/traits/introspection/nested_type/has_value_type.hpp>
#include <boost/concept/traits/_detail/metafunction/is_dereferenceable.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_readable_iterator
      : ::boost::mpl::eval_if<
            typename ::boost::concept::traits::_detail::metafunction
            ::is_dereferenceable<T>::type
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_lvalue_assignable<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_value_type<
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                        T
#else
                        ::std::iterator_traits<T>
#endif
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_readable_iterator_impl<T>
                  , ::boost::mpl::false_
                >
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

