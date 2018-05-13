// Copyright (C) 2013-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_REAL_TYPE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MATH_REAL_TYPE_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_lvalue_assignable.hpp>
#include <boost/concept/traits/query/is_addable.hpp>
#include <boost/concept/traits/query/is_subtractable.hpp>
#include <boost/concept/traits/query/is_multipliable.hpp>
#include <boost/concept/traits/query/is_dividable.hpp>
#include <boost/concept/traits/query/is_identity_operable.hpp>
#include <boost/concept/traits/query/is_negatable.hpp>
#include <boost/concept/traits/query/is_comparable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

//[reference__is_math_real_type
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_math_real_type
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_lvalue_assignable_<
                typename _std_remove_const_<
                    typename _std_remove_reference_<T>::type
                >::type
            >
          , _mpl_eval_if_<
                _bct_is_identity_operable_<T>
              , _mpl_eval_if_<
                    _bct_is_addable_<T>
                  , _mpl_eval_if_<
                        _bct_is_subtractable_<T>
                      , _mpl_eval_if_<
                            _bct_is_multipliable_<T>
                          , _mpl_eval_if_<
                                _bct_is_dividable_<T>
                              , _mpl_if_<
                                    _bct_is_negatable_<T>
                                  , _bct_is_comparable_<T>
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
            ::boost::concept::traits::is_lvalue_assignable<
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
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_identity_operable<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_addable<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::is_subtractable<T>
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::is_multipliable<T>
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::is_dividable<T>
                              , ::boost::mpl::if_<
                                    ::boost::concept::traits::is_negatable<T>
                                  , ::boost::concept::traits::is_comparable<T>
                                  , ::boost::mpl::false_
                                >
                              , ::boost::mpl::false_
                            >
                          , ::boost::mpl::false_
                        >
                      , ::boost::mpl::false_
                    >
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

