// Copyright (C) 2013-2017 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_MUTABLE_HEAP_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_MUTABLE_HEAP_HPP

#include <boost/concept/traits/introspection/member_function/has_update.hpp>
#include <boost/concept/traits/introspection/member_function/has_increase.hpp>
#include <boost/concept/traits/introspection/member_function/has_decrease.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/config.hpp>

#if defined BOOST_NO_CXX11_DECLTYPE
#include <boost/typeof/typeof.hpp>
#endif

#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#else
#include <type_traits>
#endif

namespace boost { namespace concept { namespace traits {
namespace _detail { namespace metafunction {

    template <typename T>
    class is_mutable_heap_impl
    {
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
        typedef typename ::boost::remove_const<T>::type _mutable_T;
#else
        typedef typename ::std::remove_const<T>::type _mutable_T;
#endif

     public:
        typedef typename ::boost::mpl::eval_if<
#if defined BOOST_NO_CXX11_HDR_TYPE_TRAITS
                    ::boost::is_same<
#else
                    ::std::is_same<
#endif
#if defined BOOST_NO_CXX11_DECLTYPE
                        BOOST_TYPEOF_KEYWORD
#else
                        decltype
#endif
                        (
                            ::boost::declref<_mutable_T>().push(
                                ::boost::declcref<
                                    typename _mutable_T::value_type
                                >()
                            )
                        )
                      , typename _mutable_T::handle_type
                    >
                  , ::boost::mpl::eval_if<
                        ::boost::concept::traits::has_update<
                            _mutable_T
                          , typename _mutable_T::handle_type
                          , typename _mutable_T::const_reference
                        >
                      , ::boost::mpl::eval_if<
                            ::boost::concept::traits::has_update<
                                _mutable_T
                              , typename _mutable_T::handle_type
                            >
                          , ::boost::mpl::eval_if<
                                ::boost::concept::traits::has_increase<
                                    _mutable_T
                                  , typename _mutable_T::handle_type
                                  , typename _mutable_T::const_reference
                                >
                              , ::boost::mpl::eval_if<
                                    ::boost::concept::traits::has_increase<
                                        _mutable_T
                                      , typename _mutable_T::handle_type
                                    >
                                  , ::boost::mpl::if_<
                                        ::boost::concept::traits
                                        ::has_decrease<
                                            _mutable_T
                                          , typename _mutable_T::handle_type
                                          , typename _mutable_T
                                            ::const_reference
                                        >
                                      , ::boost::concept::traits
                                        ::has_decrease<
                                            _mutable_T
                                          , typename _mutable_T::handle_type
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
                type;
    };
}}  // namespace _detail::metafunction
}}}  // namespace boost::concept::traits

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/concept/traits/query/is_heap.hpp>
#include <boost/concept/traits/introspection/nested_type/has_handle_type.hpp>

//[reference__is_mutable_heap
namespace boost { namespace concept { namespace traits {

    template <typename T>
    struct is_mutable_heap
//<-
#if defined BOOST_CONCEPT_CONFIG_DOCUMENTATION
//->
      : _mpl_eval_if_<
            _bct_is_heap_<T>
          , _mpl_eval_if_<
                _bct_has_handle_type_<T>
              , _mpl_eval_if_<
                    _std_is_same_<
                        _decltype_(
                            _declref_<
                                typename _std_remove_const_<T>::type
                            >().push(
                                _declcref_<
                                    typename _std_remove_const_<T>::type
                                    ::value_type
                                >()
                            )
                        )
                      , typename _std_remove_const_<T>::type::handle_type
                    >
                  , _mpl_eval_if_<
                        _bct_has_update_<
                            typename _std_remove_const_<T>::type
                          , typename _std_remove_const_<T>::type::handle_type
                          , typename _std_remove_const_<T>::type
                            ::const_reference
                        >
                      , _mpl_eval_if_<
                            _bct_has_update_<
                                typename _std_remove_const_<T>::type
                              , typename _std_remove_const_<T>::type
                                ::handle_type
                            >
                          , _mpl_eval_if_<
                                _bct_has_increase_<
                                    typename _std_remove_const_<T>::type
                                  , typename _std_remove_const_<T>::type
                                    ::handle_type
                                  , typename _std_remove_const_<T>::type
                                    ::const_reference
                                >
                              , _mpl_eval_if_<
                                    _bct_has_increase_<
                                        typename _std_remove_const_<T>::type
                                      , typename _std_remove_const_<T>::type
                                        ::handle_type
                                    >
                                  , _mpl_if_<
                                        _bct_has_decrease_<
                                            typename _std_remove_const_<T>
                                            ::type
                                          , typename _std_remove_const_<T>
                                            ::type::handle_type
                                          , typename _std_remove_const_<T>
                                            ::type::const_reference
                                        >
                                      , _bct_has_decrease_<
                                            typename _std_remove_const_<T>
                                            ::type
                                          , typename _std_remove_const_<T>
                                            ::type::handle_type
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
            ::boost::concept::traits::is_heap<T>
          , ::boost::mpl::eval_if<
                ::boost::concept::traits::has_handle_type<T>
              , ::boost::concept::traits::_detail::metafunction
                ::is_mutable_heap_impl<T>
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

