// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ITERATOR_CATEGORY_OF_HPP
#define \
BOOST_CONCEPT_TRAITS_INTROSPECTION_NESTED_TYPE_IS_ITERATOR_CATEGORY_OF_HPP

#include <boost/concept/traits/trivial_access/iterator_category_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename Category>
    struct is_iterator_with_category
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
                typename ::boost::concept::traits
                ::iterator_category_of<T>::type
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , typename ::boost::remove_const<
                    typename ::boost::remove_reference<Category>::type
                >::type
#else
              , typename ::std::remove_const<
                    typename ::std::remove_reference<Category>::type
                >::type
#endif
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

#include \
<boost/concept/traits/introspection/nested_type/has_iterator_category.hpp>

//[reference__is_iterator_category_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_iterator_category_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_has_iterator_category_<T2>
          , _mpl_if_<
                _std_is_convertible_<
                    typename _bct_iterator_category_of_<T2>::type
                  , typename _std_remove_const_<
                        typename _std_remove_reference_<T1>::type
                    >::type
                >
              , _mpl_true_
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::if_<
            ::boost::concept::traits::has_iterator_category<T2>
          , ::boost::concept::traits::_detail::metafunction
            ::is_iterator_with_category<T2,T1>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

