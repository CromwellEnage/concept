// Copyright (C) 2005-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_STATIC_CONSTANT_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_STATIC_CONSTANT_HPP

#include <boost/mpl/equal_to.hpp>
#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <
        typename T
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
      , typename _mutable_T = typename ::boost::remove_const<
            typename ::boost::remove_reference<T>::type
        >::type
#else
      , typename _mutable_T = typename ::std::remove_const<
            typename ::std::remove_reference<T>::type
        >::type
#endif
    >
    struct is_mpl_static_constant
      : ::boost::mpl::equal_to<_mutable_T,typename _mutable_T::type>
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_std_integral_constant.hpp>
#include <boost/concept/traits/introspection/nested_type/has_type.hpp>
#include <boost/concept/traits/introspection/nested_type/is_tag_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/integral_c_tag.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_mpl_static_constant
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_mpl_static_constant
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
      : _mpl_eval_if_<
            _bct_is_std_integral_constant_<T>
          , _mpl_eval_if_<
                _bct_has_type_<T>
              , _mpl_if_<
                    _bct_is_tag_of_<
                        _mpl_integral_c_tag_
                      , T
                    >
                  , _mpl_equal_to_<
                        typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type
                      , typename _std_remove_const_<
                            typename _std_remove_reference_<T>::type
                        >::type::type
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
            ::boost::concept::traits::is_std_integral_constant<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_type<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits
                    ::is_tag_of< ::boost::mpl::integral_c_tag,T>
                  , ::boost::concept::traits::_detail::metafunction
                    ::is_mpl_static_constant<T>
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

