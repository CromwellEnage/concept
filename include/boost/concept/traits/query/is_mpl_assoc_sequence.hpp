// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_ASSOC_SEQUENCE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_ASSOC_SEQUENCE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/aux_/has_key_impl.hpp>
#include <boost/config.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename Tag, typename T>
    struct is_mpl_associative_sequence_impl
      : ::boost::mpl::bool_<
            sizeof(
                typename ::boost::mpl::has_key_impl<Tag>
                ::BOOST_NESTED_TEMPLATE apply<T,void*>
            ) != 0
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/fusion/support/special_tags_fwd.hpp>
#include <boost/fusion/sequence/intrinsic/has_key.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_mpl_associative_sequence_impl<
        ::boost::fusion::fusion_sequence_tag
      , T
    > : ::boost::mpl::bool_<
            sizeof(
                ::boost::fusion::extension::has_key_impl<
                    typename ::boost::fusion::detail::tag_of<T>::type
                >
            ) != 0
        >
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/mpl/sequence_tag.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_mpl_associative_sequence
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef ::boost::concept::traits::_detail::metafunction
                ::is_mpl_associative_sequence_impl<
                    typename ::boost::mpl::sequence_tag<_mutable_T>::type
                  , _mutable_T
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_mpl_forward_iterator.hpp>
#include <boost/concept/traits/query/is_mpl_sequence.hpp>
#include <boost/mpl/eval_if.hpp>

//[reference__is_mpl_associative_sequence
namespace boost { namespace concept { namespace traits {

    template <typename T, typename PlaceholderExpr>
    struct is_mpl_associative_sequence
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_if_<
            _bct_is_mpl_sequence_<T,PlaceholderExpr>
          , _is_valid_expression_(
                _declval_<
                    typename _mpl_has_key_<
                        typename _std_remove_const_<T>::type
                      , void*
                    >::type
                >()
            )
          , _mpl_false_
        >::type
//<-
#else
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_mpl_sequence<T,PlaceholderExpr>
          , ::boost::concept::traits::_detail::metafunction
            ::is_mpl_associative_sequence<T>
          , ::boost::mpl::false_
        >::type
#endif  // BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

