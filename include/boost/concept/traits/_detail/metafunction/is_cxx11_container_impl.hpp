// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_CXX11_CONTAINER_IMPL_HPP
#define BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_IS_CXX11_CONTAINER_IMPL_HPP

#include <boost/iterator/iterator_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <iterator>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_cxx11_container_with_difference_type
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::mpl::if_<
            ::boost::is_same<
#else
      : ::boost::mpl::eval_if<
            ::std::is_same<
#endif
                typename T::difference_type
              , typename ::boost::iterators::iterator_difference<
                    ::std::iterator_traits<typename T::const_iterator>
                >::type
            >
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::is_same<
#else
          , ::boost::mpl::if_<
                ::std::is_same<
#endif
                    typename T::difference_type
                  , typename ::boost::iterators::iterator_difference<
                        ::std::iterator_traits<typename T::iterator>
                    >::type
                >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , ::boost::mpl::true_
              , ::boost::mpl::false_
            >
#endif
          , ::boost::mpl::false_
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include \
<boost/concept/traits/introspection/nested_type/has_difference_type.hpp>
#include <boost/concept/traits/introspection/member_function/has_cbegin.hpp>
#include <boost/concept/traits/introspection/member_function/has_cend.hpp>
#include <boost/concept/traits/_detail/metafunction/is_container_impl.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename UMFC>
    struct is_cxx11_container_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_difference_type<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_cbegin<T const>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_cend<T const>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::_detail::metafunction
                        ::is_minimal_container_impl<T,UMFC>
                      , ::boost::concept::traits::_detail::metafunction
                        ::is_cxx11_container_with_difference_type<T>
                      , ::boost::mpl::false_
                    >
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

