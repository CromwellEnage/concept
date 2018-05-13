// Copyright (C) 2011-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_INPUT_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_INPUT_ITERATOR_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#else
#include <type_traits>
#endif

#if !defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
#include <iterator>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_input_iterator_impl
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::mpl::if_<
            ::boost::is_convertible<
#else
      : ::boost::mpl::eval_if<
            ::std::is_convertible<
#endif
                typename ::boost::iterators::iterator_reference<
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                    T
#else
                    ::std::iterator_traits<T>
#endif
                >::type
              , typename ::boost::iterators::iterator_value<
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                    T
#else
                    ::std::iterator_traits<T>
#endif
                >::type
            >
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::is_convertible<
#else
          , ::boost::mpl::if_<
                ::std::is_convertible<
#endif
#if defined(BOOST_NO_CXX11_DECLTYPE)
                    BOOST_TYPEOF_KEYWORD(
                        *::boost::concept::traits::declref<T>()++
                    )
#else
                    decltype(*::boost::concept::traits::declref<T>()++)
#endif
                  , typename ::boost::iterators::iterator_value<
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                        T
#else
                        ::std::iterator_traits<T>
#endif
                    >::type
#if !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                >
              , ::boost::mpl::true_
              , ::boost::mpl::false_
#endif
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type/has_reference.hpp>
#include \
<boost/concept/traits/_detail/metafunction/has_pre_increment_operator.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_post_inc_deref_able.hpp>
#include \
<boost/concept/traits/_detail/metafunction/is_post_inc_deref_nv.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_input_iterator
      : ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::boost::mpl::eval_if<
                    ::boost::concept::traits::_detail::metafunction
                    ::is_readable_iterator<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::has_pre_increment_operator<T>
                  , ::boost::mpl::false_
                >::type
              , ::boost::concept::traits::_detail::metafunction
                ::is_post_increment_dereferenceable<T>
              , ::boost::mpl::false_
            >::type
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::_detail::metafunction
                ::is_post_increment_dereferenceable_non_void<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_reference<
#if defined(BOOST_NO_CXX17_ITERATOR_TRAITS)
                        T
#else
                        ::std::iterator_traits<T>
#endif
                    >
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_input_iterator_impl<T>
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

