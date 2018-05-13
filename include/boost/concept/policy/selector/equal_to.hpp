// Copyright (C) 2011-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_POLICY_SELECTOR_EQUAL_TO_HPP
#define BOOST_CONCEPT_POLICY_SELECTOR_EQUAL_TO_HPP

#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace policy {
namespace _detail { namespace metafunction {

    template <typename T>
    struct equal_to_range_predicate
    {
        typedef bool result_type;
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::add_lvalue_reference<
                    typename ::boost::add_const<
                        typename ::std::remove_reference<T>::type
#else
        typedef typename ::std::add_lvalue_reference<
                    typename ::std::add_const<
                        typename ::std::remove_reference<T>::type
#endif
                    >::type
                >::type
                first_argument_type;
        typedef first_argument_type second_argument_type;

        result_type
            operator()(
                first_argument_type lhs
              , second_argument_type rhs
            ) const;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::policy

#include <boost/range/algorithm/equal.hpp>

namespace boost { namespace concept { namespace policy {
namespace _detail { namespace metafunction {

    template <typename T>
    inline typename equal_to_range_predicate<T>::result_type
        equal_to_range_predicate<T>::operator()(
            typename equal_to_range_predicate<T>::first_argument_type lhs
          , typename equal_to_range_predicate<T>::second_argument_type rhs
        ) const
    {
        return ::boost::range::equal(lhs, rhs);
    }
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::policy

#include <boost/concept/policy/selector_fwd.hpp>
#include <boost/concept/traits/query/is_range.hpp>
#include <functional>

//[reference__equal_to_selector
namespace boost { namespace concept { namespace policy {

    struct equal_to_selector
    {
        template <typename T>
        struct apply
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
          : _mpl_if_<
                _bct_is_range_<T>
              , [](T const& lhs, T const& rhs){
                    return _range_equal_(lhs, rhs);
                }
              , _std_equal_to_<T>
            >
//<-
#elif !defined BOOST_MPL_CFG_NO_NESTED_FORWARDING
          : ::boost::mpl::if_<
                ::boost::concept::traits::is_range<T>
              , ::boost::concept::policy::_detail::metafunction
                ::equal_to_range_predicate<T>
              , ::std::equal_to<T>
            >
#endif
//->
        {
//<-
#if defined BOOST_MPL_CFG_NO_NESTED_FORWARDING
            typedef typename ::boost::mpl::if_<
                        ::boost::concept::traits::is_range<T>
                      , ::boost::concept::policy::_detail::metafunction
                        ::equal_to_range_predicate<T>
                      , ::std::equal_to<T>
                    >::type
                    type;
#endif
//->
        };
    };
}}}  // namespace boost::concept::policy
//]

#endif  // include guard

