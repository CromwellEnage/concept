// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ORDERED_ITERATOR_OF_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ORDERED_ITERATOR_OF_HPP

#include <boost/concept/traits/query/is_readable_iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_ordered_iterator_of_impl
      : ::boost::mpl::if_<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
            ::boost::is_same<
                typename ::boost::remove_const<T2>::type::ordered_iterator
#else
            ::std::is_same<
                typename ::std::remove_const<T2>::type::ordered_iterator
#endif
              , T1
            >
          , ::boost::concept::traits::is_readable_iterator<T1>
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_ordered_iterator.hpp>

//[reference__is_ordered_iterator_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_ordered_iterator_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_ordered_iterator_<T2>
          , _mpl_if_<
                _std_is_same_<
                    T1
                  , typename _std_remove_const_<T2>::type::ordered_iterator
                >
              , _bct_is_readable_iterator_<T1>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_ordered_iterator<T2>
          , ::boost::concept::traits::_detail::metafunction
            ::is_ordered_iterator_of_impl<T1,T2>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

