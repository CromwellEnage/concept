// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_REVERSE_ITERATOR2_OF_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_REVERSE_ITERATOR2_OF_HPP

#include <boost/concept/traits/trivial_access/reverse_iterator2_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T1, typename T2>
    struct is_reverse_iterator2_of_impl
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
                typename ::boost::concept::traits
                ::reverse_iterator2_of<T2>::type
              , T1
            >
#if !defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
          , ::boost::mpl::true_
          , ::boost::mpl::false_
        >::type
#endif
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/introspection/nested_type_fwd.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_reverse_iterator2.hpp>

//[reference__is_reverse_iterator2_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_reverse_iterator2_of
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_reverse_iterator2_<T2>
          , _mpl_if_<
                _std_is_same_<
                    typename _bct_reverse_iterator2_of_<T2>::type
                  , T1
                >
              , _mpl_true_
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_reverse_iterator2<T2>
          , ::boost::concept::traits::_detail::metafunction
            ::is_reverse_iterator2_of_impl<T1,T2>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

