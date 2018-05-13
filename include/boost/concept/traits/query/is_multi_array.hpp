// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MULTI_ARRAY_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MULTI_ARRAY_HPP

#include <boost/concept/traits/query/is_multi_array_index_range.hpp>
#include <boost/concept/traits/introspection/member_function/has_origin.hpp>
#include <boost/concept/traits/introspection/member_function/has_shape.hpp>
#include <boost/concept/traits/introspection/member_function/has_strides.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_index_bases.hpp>
#include <boost/concept/traits/trivial_access/index_range_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct has_multi_array_members
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_multi_array_index_range<
                typename ::boost::concept::traits::index_range_of<T>::type
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_origin<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_shape<T>
                  , ::boost::mpl::if_<
                        ::boost::concept::traits::has_strides<T>
                      , ::boost::concept::traits::has_index_bases<T>
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

#include <boost/utility/declref.hpp>
#include <boost/utility/declval.hpp>
#include <boost/concept/traits/query/is_subscriptable.hpp>
#include <boost/concept/traits/trivial_access/index_gen_of.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/always.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_multi_array_with_subscript
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_subscriptable<
                T
#if defined BOOST_NO_CXX11_DECLTYPE
              , BOOST_TYPEOF_KEYWORD
#else
              , decltype
#endif
                (
                    ::boost::declref<
                        typename ::boost::concept::traits
                        ::index_gen_of<T>::type
                    >()[
                        ::boost::declval<
                            typename ::boost::concept::traits
                            ::index_range_of<T>::type
                        >()
                    ]
                )
//              , ::boost::concept::traits::_detail::metafunction
//                ::is_multi_array_impl< ::boost::mpl::_>
, ::boost::mpl::always< ::boost::mpl::true_>
            >
          , ::boost::concept::traits::_detail::metafunction
            ::has_multi_array_members<T>
          , void//::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_multi_array_impl
      : ::boost::mpl::if_<
            ::boost::concept::traits::_detail::metafunction
//            ::is_multi_array_with_subscript<
            ::has_multi_array_members<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::add_const<T>::type
#else
                typename ::std::add_const<T>::type
#endif
            >
          , ::boost::concept::traits::_detail::metafunction
//            ::is_multi_array_with_subscript<
            ::has_multi_array_members<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                typename ::boost::remove_const<T>::type
#else
                typename ::std::remove_const<T>::type
#endif
            >
          , ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_random_access_container.hpp>
#include <boost/concept/traits/query/is_equality_comparable.hpp>
#include <boost/concept/traits/query/is_comparable.hpp>
#include <boost/concept/traits/introspection/nested_type/has_index_gen.hpp>
#include <boost/concept/traits/introspection/nested_type/has_index_range.hpp>

//[reference__is_multi_array
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_multi_array
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_random_access_container_<T>
          , _mpl_eval_if_<
                _bct_has_index_range_<T>
              , _mpl_eval_if_<
                    _bct_is_multi_array_index_range_<
                        typename _bct_index_range_of_<T>::type
                    >
                  , _mpl_eval_if_<
                        _bct_has_index_gen_<T>
                      , _mpl_eval_if_<
                            _bct_has_origin_<T>
                          , _mpl_eval_if_<
                                _bct_has_shape_<T>
                              , _mpl_eval_if_<
                                    _bct_has_strides_<T>
                                  , _bct_has_index_bases_<T>
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
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::is_random_access_container<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::is_equality_comparable<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::is_comparable<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_index_gen<T>
                      , ::boost::mpl::if_<
                            ::boost::concept::traits::has_index_range<T>
                          , ::boost::concept::traits::_detail::metafunction
                            ::is_multi_array_impl<T>
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

