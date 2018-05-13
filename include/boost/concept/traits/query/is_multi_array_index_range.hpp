// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MULTI_ARRAY_INDEX_RANGE_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MULTI_ARRAY_INDEX_RANGE_HPP

#include <boost/concept/traits/introspection/member_function/has_start.hpp>
#include <boost/concept/traits/introspection/member_function/has_finish.hpp>
#include <boost/concept/traits/introspection/member_function/has_stride.hpp>
#include <boost/concept/traits/trivial_access/index_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    struct is_multi_array_index_range_impl
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_start<
                T
              , typename ::boost::concept::traits::index_of<T>::type
            >
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_finish<
                    T
                  , typename ::boost::concept::traits::index_of<T>::type
                >
              , ::boost::mpl::if_<
                    ::boost::concept::traits::has_stride<
                        T
                      , typename ::boost::concept::traits::index_of<T>::type
                    >
                  , ::boost::concept::traits::has_size<
                        T
                      , typename ::boost::concept::traits::index_of<T>::type
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

#include <boost/concept/traits/query_fwd.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_get_start.hpp>
#include \
<boost/concept/traits/introspection/member_function/has_get_finish.hpp>

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/add_const.hpp>
#else
#include <type_traits>
#endif

//[reference__is_multi_array_index_range
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_multi_array_index_range
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
          _bct_has_get_start_<T>
        , _mpl_eval_if<
            _bct_has_get_finish_<T>
          , _mpl_eval_if<
              _bct_has_start_<T>
            , _mpl_eval_if<
                _bct_has_finish_<T>
              , _mpl_eval_if<
                  _bct_has_stride_<T>
                , _mpl_eval_if<
                    _bct_has_start_<
                      T
                    , typename _bct_index_of_<T>::type
                    >
                  , _mpl_eval_if<
                      _bct_has_finish_<
                        T
                      , typename _bct_index_of_<T>::type
                      >
                    , _mpl_eval_if<
                        _bct_has_stride_<
                          T
                        , typename _bct_index_of_<T>::type
                        >
                      , _bct_has_size_<
                          T
                        , typename _bct_index_of_<T>::type
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
            >
          , _mpl_false_
          >
        , _mpl_false_
        >::type
//<-
#else   // !defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
      : ::boost::mpl::eval_if<
            ::boost::concept::traits::has_get_start<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_get_finish<T>
              , ::boost::mpl::eval_if<
                    ::boost::concept::traits::has_start<T>
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_finish<T>
                      , ::boost::mpl::if_<
                            ::boost::concept::traits::has_stride<T>
                          , ::boost::concept::traits::_detail::metafunction
                            ::is_multi_array_index_range_impl<T>
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

