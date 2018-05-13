// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_VALUE_DISTRIBUTION_W_PRM_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_VALUE_DISTRIBUTION_W_PRM_HPP

#include <boost/concept/traits/trivial_access/param_type_of.hpp>
#include <boost/concept/traits/trivial_access/distribution_type_of.hpp>
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

    template <typename T>
    struct is_value_distribution_same_as_param_type_distro_type
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      : ::boost::is_same<
#else
      : ::boost::mpl::if_<
            ::std::is_same<
#endif
                T
              , typename ::boost::concept::traits::distribution_type_of<
                    typename ::boost::concept::traits::param_type_of<T>::type
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

#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include \
<boost/concept/traits/introspection/nested_type/has_distribution_type.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_value_distribution_with_param
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_equality_comparable<
                typename ::boost::concept::traits::param_type_of<T>::type
            >
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_distribution_type<
                    typename ::boost::concept::traits::param_type_of<T>::type
                >
              , ::boost::concept::traits::_detail::metafunction
                ::is_value_distribution_same_as_param_type_distro_type<T>
              , ::boost::mpl::false_
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_less_than_comparable.hpp>
#include <boost/concept/traits/query/is_value_distribution.hpp>
#include <boost/concept/traits/introspection/nested_type/has_param_type.hpp>

//[reference__is_value_distribution_with_param
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_value_distribution_with_param
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
          _bct_has_param_type_<T>
        , _mpl_eval_if_<
            _bct_is_value_distribution_<T,ResultPlaceholderExpr>
          , _mpl_eval_if_<
              _bct_is_equality_comparable_<T>
            , _mpl_eval_if_<
                _bct_is_equality_comparable_<
                  typename _bct_param_type_of_<T>::type
                >
              , _mpl_eval_if_<
                  _bct_has_distribution_type_<
                    typename _bct_param_type_of_<T>::type
                  >
                , _mpl_eval_if_<
                    _bct_has_distribution_type_<
                      typename _bct_param_type_of_<T>::type
                    >
                  , _mpl_if_<
                      _std_is_same_<
                        T
                      , typename _bct_distribution_type_of_<
                          typename _bct_param_type_of_<T>::type
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
            >
          , _mpl_false_
          >
        , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_param_type<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits
                ::is_value_distribution<T,ResultPlaceholderExpr>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_equality_comparable<T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_value_distribution_with_param<T>
                  , ::boost::mpl::false_
                >
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

