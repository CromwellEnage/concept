// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_CALLABLE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_CALLABLE_HPP

#include <boost/concept/traits/result_of.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_callable
      : ::boost::mpl::apply1<
            ResultPlaceholderExpr
          , typename ::boost::concept::traits::result_of<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                typename ::boost::remove_reference<T>::type
#else
                typename ::std::remove_reference<T>::type
#endif
            >::type
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/aux_/has_type.hpp>

//[reference__is_callable
namespace boost { namespace concept { namespace traits {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_callable
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            typename _mpl_aux_has_type_<
                _bct_result_of_<
                    typename _std_remove_reference_<T>::type
                >
            >::type
          , _mpl_apply1_<
                ResultPlaceholderExpr
              , typename _bct_result_of_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::mpl::if_<
            typename ::boost::mpl::aux::has_type<
                ::boost::concept::traits::result_of<
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
                    typename ::boost::remove_reference<T>::type
#else
                    typename ::std::remove_reference<T>::type
#endif
                >
            >::type
          , ::boost::concept::traits::_detail::metafunction
            ::is_callable<T,ResultPlaceholderExpr>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

