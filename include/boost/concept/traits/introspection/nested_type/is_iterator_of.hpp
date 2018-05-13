// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ITERATOR_OF_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ITERATOR_OF_HPP

#include <boost/range/iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_range_iterator_of
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
                T1
              , typename ::boost::range_iterator<T2>::type
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

#include <boost/range/has_range_iterator.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_iterator_of
      : ::boost::mpl::if_<
            ::boost::has_range_iterator<T2>
          , ::boost::concept::traits::_detail::metafunction
            ::is_range_iterator_of<T1,T2>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

//[reference__is_iterator_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_iterator_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _range_has_range_iterator_<
                typename _std_remove_reference_<T2>::type
            >
          , _mpl_if_<
                _std_is_same_<
                    typename _std_remove_const_<
                        typename _std_remove_reference_<T1>::type
                    >::type
                  , typename _range_iterator_<
                        typename _std_remove_reference_<T2>::type
                    >::type
                >
              , _mpl_true_
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::_detail::metafunction::is_iterator_of<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            typename ::boost::remove_const<
                typename ::boost::remove_reference<T1>::type
            >::type
          , typename ::boost::remove_reference<T2>::type
#else
            typename ::std::remove_const<
                typename ::std::remove_reference<T1>::type
            >::type
          , typename ::std::remove_reference<T2>::type
#endif
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

