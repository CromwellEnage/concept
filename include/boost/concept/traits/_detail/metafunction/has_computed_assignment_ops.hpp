// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_COMPUTED_ASSIGNMENT_OPS_HPP
#define \
BOOST_CONCEPT_TRAITS__DETAIL_METAFUNCTION_HAS_COMPUTED_ASSIGNMENT_OPS_HPP

#include <boost/concept/traits/query/is_addition_assignable.hpp>
#include <boost/concept/traits/query/is_subtraction_assignable.hpp>
#include <boost/concept/traits/query/is_multiply_assignable.hpp>
#include <boost/concept/traits/introspection/member_function/has_assign.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_plus_assign.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_minus_assign.hpp>
#include <boost/concept/traits/introspection/is_convertible_to_cref_of.hpp>
#include <boost/concept/traits/trivial_access/value_type_of.hpp>
#include <boost/concept/policy/use_default.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_computed_assignment_ops
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_multiplication_assignable<
                T
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
              , typename ::boost::add_const<
#else
              , typename ::std::add_const<
#endif
                    typename ::boost::concept::traits::value_type_of<T>::type
                >::type
              , ::boost::concept::traits
                ::is_convertible_to_cref_of<T,::boost::mpl::_>
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_assign<
                    T
                  , ::boost::concept::policy::use_default
                  , ::boost::concept::traits
                    ::is_convertible_to_cref_of<T,::boost::mpl::_>
                >
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_subtraction_assignable<
                        T
                      , ::boost::concept::policy::use_default
                      , ::boost::concept::traits
                        ::is_convertible_to_cref_of<T,::boost::mpl::_>
                    >
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::is_addition_assignable<
                            T
                          , ::boost::concept::policy::use_default
                          , ::boost::concept::traits
                            ::is_convertible_to_cref_of<T,::boost::mpl::_>
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_plus_assign<
                                T
                              , ::boost::concept::policy::use_default
                              , ::boost::concept::traits
                                ::is_convertible_to_cref_of<T,::boost::mpl::_>
                            >
                          , ::boost::concept::traits::has_minus_assign<
                                T
                              , ::boost::concept::policy::use_default
                              , ::boost::concept::traits
                                ::is_convertible_to_cref_of<T,::boost::mpl::_>
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
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#endif  // include guard

