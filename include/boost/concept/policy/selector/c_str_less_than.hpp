// Copyright (C) 2012-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_C_STR_LESS_THAN_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_C_STR_LESS_THAN_HPP

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/config.hpp>

#if !defined BOOST_NO_CWCHAR
#include <cwchar>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_extent.hpp>
#else
#include <type_traits>
#endif

//[reference__c_str_less_than_selector
namespace boost { namespace concept { namespace policy {

    struct c_str_less_than_selector
    {
        template <typename T>
        struct apply
        {
            class type
            {
                inline static bool
                    _evaluate(
                        T const& lhs
                      , T const& rhs
//<-
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                      , ::boost::true_type
#else
//->
                      , ::std::true_type
//<-
#endif
//->
                    )
                {
                    return strcmp(lhs, rhs) < 0;
                }

//<-
#if !defined BOOST_NO_CWCHAR
//->
                inline static bool
                    _evaluate(
                        T const& lhs
                      , T const& rhs
//<-
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                      , ::boost::false_type
#else
//->
                      , ::std::false_type
//<-
#endif
//->
                    )
                {
                    return wcscmp(lhs, rhs) < 0;
                }
//<-
#endif
//->

             public:
                typedef bool result_type;
                typedef T const& first_argument_type;
                typedef T const& second_argument_type;

                inline result_type
                    operator()(
                        first_argument_type lhs
                      , second_argument_type rhs
                    ) const
                {
                    return type::_evaluate(
                        lhs
                      , rhs
//<-
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                      , ::boost::is_same<
                            typename ::boost::remove_cv<
                                typename ::boost::remove_pointer<
                                    typename ::boost::remove_extent<T>::type
#else
//->
                      , ::std::is_same<
                            typename ::std::remove_cv<
                                typename ::std::remove_pointer<
                                    typename ::std::remove_extent<T>::type
//<-
#endif
//->
                                >::type
                            >::type
                          , char
                        >()
                    );
                }
            };
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

