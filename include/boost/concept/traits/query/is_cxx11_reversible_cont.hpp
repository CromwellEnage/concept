// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_CXX11_REVERSIBLE_CONT_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_CXX11_REVERSIBLE_CONT_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_reversible_container.hpp>
#include <boost/concept/traits/introspection/member_function/has_crbegin.hpp>
#include <boost/concept/traits/introspection/member_function/has_crend.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_cxx11_reversible_container
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_cxx11_reversible_container
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_has_crbegin_<T>
          , _mpl_if_<
                _bct_has_crend_<T>
              , _bct_is_reversible_container_<T>
              , _mpl_false_
            >
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_crbegin<T>
          , ::boost::mpl::if_<
                ::boost::concept::traits::has_crend<T>
              , ::boost::concept::traits::is_reversible_container<T>
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

