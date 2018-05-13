// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_FORWARD_TRAVERSAL_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_FORWARD_TRAVERSAL_ITERATOR_HPP

#include <boost/concept/traits/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/typeof/typeof.hpp>
#endif

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#if defined(BOOST_NO_CXX11_DECLTYPE)
#include <boost/type_traits/is_convertible.hpp>
#else
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#endif
#else   // !defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <type_traits>
#endif  // BOOST_NO_CXX11_HDR_TYPE_TRAITS

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_forward_traversal_iterator_impl
#if defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_convertible<
#else
      : ::boost::mpl::if_<
            ::std::is_convertible<
#endif
                BOOST_TYPEOF_KEYWORD(++::boost::concept::traits::declref<T>())
              , T
#else   // !defined(BOOST_NO_CXX11_DECLTYPE)
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
                decltype(++::boost::concept::traits::declref<T>())
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
              , typename ::boost::add_lvalue_reference<T>::type
#else
              , typename ::std::add_lvalue_reference<T>::type
#endif
#endif  // BOOST_NO_CXX11_DECLTYPE
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

#include <boost/concept/traits/query/is_incrementable.hpp>
#include <boost/concept/traits/_detail/metafunction/is_dereferenceable.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_forward_traversal_iterator
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_incrementable<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::_detail::metafunction
                ::is_forward_traversal_iterator_impl<T>
              , ::boost::concept::traits::_detail::metafunction
                ::is_dereferenceable<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_iterator_difference.hpp>
#include \
<boost/concept/traits/introspection/nested_type/is_iterator_traversal_of.hpp>
#include <boost/iterator/iterator_categories.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#endif

#if !defined( \
BOOST_CONCEPT_CONFIG_BUG_ADJACENT_FILTERED_RANGE_ITERATOR_NOT_EQ_COMP \
)
#include <boost/concept/traits/query/is_equality_comparable.hpp>
#endif

//[reference__is_forward_traversal_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_forward_traversal_iterator
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_single_pass_iterator_<T>
          , _mpl_eval_if_<
                _bct_is_equality_comparable_<T>
              , _mpl_eval_if_<
                    _bct_is_iterator_traversal_of_<
                        boost::iterators::forward_traversal_tag
                      , T
                    >
                  , _mpl_eval_if_<
                        _bct_has_iterator_difference_<T>
                      , _mpl_if_<
                            _std_is_same_<
                                _decltype_(
                                    ++_bct_declref_<
                                        typename _std_remove_const_<
                                            typename _std_remove_reference_<
                                                T
                                            >::type
                                        >::type
                                    >()
                                )
                              , typename _std_add_lvalue_reference_<
                                    typename _std_remove_const_<
                                        typename _std_remove_reference_<
                                            T
                                        >::type
                                    >::type
                                >::type
                            >
                          , _mpl_true_
                          , _mpl_false_
                        >
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
        // TODO: Include check for default constructibility.
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::_detail::metafunction
            ::is_forward_traversal_iterator<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
#else
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
#endif
            >
#if defined( \
BOOST_CONCEPT_CONFIG_BUG_ADJACENT_FILTERED_RANGE_ITERATOR_NOT_EQ_COMP \
)
          , ::boost::mpl::if_<
#else
          , ::boost::mpl::eval_if<
#endif
                ::boost::concept::traits::has_iterator_difference<T>
#if !defined( \
BOOST_CONCEPT_CONFIG_BUG_ADJACENT_FILTERED_RANGE_ITERATOR_NOT_EQ_COMP \
)
              , ::boost::mpl::if_<
                    ::boost::concept::traits::is_equality_comparable<T>
#endif
                  , ::boost::concept::traits::is_iterator_traversal_of<
                        ::boost::iterators::forward_traversal_tag
                      , T
                    >
#if !defined( \
BOOST_CONCEPT_CONFIG_BUG_ADJACENT_FILTERED_RANGE_ITERATOR_NOT_EQ_COMP \
)
                  , ::boost::mpl::false_
                >
#endif
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

