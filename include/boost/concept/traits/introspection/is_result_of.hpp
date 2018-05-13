// Copyright (C) 2014-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_INTROSPECTION_IS_RESULT_OF_HPP
#define BOOST_CONCEPT_TRAITS_INTROSPECTION_IS_RESULT_OF_HPP

#include <boost/concept/traits/introspection_fwd.hpp>
#include <boost/concept/traits/query/is_callable.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/is_same.hpp>
#else
#include <type_traits>
#endif

//[reference__is_result_of
namespace boost { namespace concept { namespace traits {

    template <typename T1, typename T2>
    struct is_result_of
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _bct_is_callable_<
            T2
          , _mpl_if_<
                _std_is_same_<_mpl_placeholder_,T1>
              , _mpl_true_
              , _mpl_false_
            >
        >
//<-
#else   // !defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
      : ::boost::concept::traits::is_callable<
            T2
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
          , ::boost::is_same< ::boost::mpl::_,T1>
#else
          , ::boost::mpl::if_<
                ::std::is_same< ::boost::mpl::_,T1>
              , ::boost::mpl::true_
              , ::boost::mpl::false_
            >
#endif
        >
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

