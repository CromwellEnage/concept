// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_RANGE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_RANGE_HPP

#include <boost/range/iterator.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename PlaceholderExpr, typename T>
    struct is_range_iterator_of
      : ::boost::mpl::apply1<
            PlaceholderExpr
          , typename ::boost::range_iterator<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_reference<T>::type
#else
                typename ::std::remove_reference<T>::type
#endif
            >::type
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_single_pass_iterator.hpp>
#include <boost/concept/traits/query/is_runtime_pair.hpp>
#include <boost/concept/traits/introspection/member_function/has_begin.hpp>
#include <boost/concept/traits/introspection/member_function/has_end.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_array.hpp>
#include <boost/type_traits/remove_const.hpp>
#endif

//[reference__is_range
namespace boost { namespace concept { namespace traits {

    template <typename T, typename PlaceholderExpr>
    struct is_range
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _std_is_array_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_true_
          , _mpl_eval_if_<
                _bct_is_runtime_pair_<T>
              , _bct_is_runtime_pair_<
                    T
                  , PlaceholderExpr
                  , PlaceholderExpr
                >
              , _mpl_eval_if_<
                    _bct_has_begin_<T>
                  , _mpl_eval_if_<
                        _bct_has_end_<T>
                      , _mpl_apply1_<
                           PlaceholderExpr
                          , typename _range_iterator_<
                                typename _std_remove_reference_<T>::type
                            >::type
                        >
                      , _mpl_false_
                    >
                  , _mpl_false_
                >
            >
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
            ::boost::is_array<
                typename ::boost::remove_const<
                    typename ::boost::remove_reference<T>::type
                >::type
            >
#else
            ::std::is_array<
                typename ::std::remove_const<
                    typename ::std::remove_reference<T>::type
                >::type
            >
#endif
          , ::boost::mpl::true_
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_runtime_pair<T>
              , ::boost::concept::traits::is_runtime_pair<
                    T
                  , PlaceholderExpr
                  , PlaceholderExpr
                >
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_begin<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_end<T>
                      , ::boost::concept::traits::_detail::metafunction
                        ::is_range_iterator_of<PlaceholderExpr,T>
                      , ::boost::mpl::false_
                    >
                  , ::boost::mpl::false_
                >
            >
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

