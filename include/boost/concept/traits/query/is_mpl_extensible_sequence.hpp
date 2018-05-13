// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_EXTENSIBLE_SEQUENCE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MPL_EXTENSIBLE_SEQUENCE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/aux_/clear_impl.hpp>
#include <boost/config.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename Tag, typename T>
    struct is_mpl_extensible_sequence_impl
      : ::boost::mpl::bool_<
            sizeof(
                typename ::boost::mpl::clear_impl<Tag>
                ::BOOST_NESTED_TEMPLATE apply<T,void*>
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
    class is_mpl_extensible_sequence
    {
 #if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef ::boost::concept::traits::_detail::metafunction
                ::is_mpl_extensible_sequence_impl<
                    typename ::boost::mpl::sequence_tag<_mutable_T>::type
                  , _mutable_T
                >
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_random_access_container.hpp>
#include <boost/concept/traits/query/is_runtime_pair.hpp>
#include <boost/concept/traits/introspection/nested_type/has_is_view.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/is_sequence.hpp>

//[reference__is_mpl_extensible_sequence
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_mpl_extensible_sequence
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _mpl_is_sequence_<typename _std_remove_const_<T>::type>
          , _mpl_eval_if_<
                _bct_is_random_access_container_<T>
              , _mpl_false_
              , _mpl_eval_if_<
                    _bct_is_runtime_pair_<T>
                  , _mpl_false_
                  , _mpl_eval_if_<
                        _bct_has_is_view_<T>
                      , _mpl_false_
                      , _mpl_true_
                    >
                >
            >
          , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::mpl::is_sequence<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_random_access_container<T>
              , ::boost::mpl::false_
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_runtime_pair<T>
                  , ::boost::mpl::false_
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_is_view<T>
                      , ::boost::mpl::false_
#if 0
                      , ::boost::concept::traits::_detail::metafunction
                        ::is_mpl_extensible_sequence<T>
#else
                      , ::boost::mpl::true_
#endif
                    >
                >
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

